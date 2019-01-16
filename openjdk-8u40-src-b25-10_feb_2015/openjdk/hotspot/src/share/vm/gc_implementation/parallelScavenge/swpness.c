
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <err.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>
#include <stdint.h>
typedef unsigned long long u8;
#define is_bigendian() ( (*(char*)&__endian_bit) == 0 )
#define GET_BIT(X,Y) (X & ((uint64_t)1 << Y)) >> Y
#define GET_PFN(X) X & 0x7FFFFFFFFFFFFF
const int __endian_bit = 1;

/*
 * ref: https://www.kernel.org/doc/Documentation/vm/pagemap.txt
 *
 * [I/O related page flags]
 * 13. SWAPCACHE   page is mapped to swap space, ie. has an associated swap
 *     entry
 * 14. SWAPBACKED  page is backed by swap/RAM
 *
 * So, We use flag number 14.
 *
 */

u8 PAGEMAP_SWAPTYPE(u8 ent)
{
	return (ent & ((1ull << 5) - 1));
}

u8 PAGEMAP_ISSWAPPED(u8 ent)
{
	if((ent & (1ull << 62)) != 0)
		return 1;
	return 0;
}

u8 PAGEMAP_ISPRESENT(u8 ent)
{
	if((ent & (1ull << 63)) != 0)
		return 1;
	return 0;
}

u8 PAGEMAP_PFN(u8 ent)
{
	return (ent & ((1ull << 55) - 1));
}

int IS_HUGE(u8 kpflags)
{
	if ((kpflags & (1ull << 17)) != 0)
		return 1;
	return 0;
}

int IN_LRU(u8 kpflags)
{
	if ((kpflags & (1ull << 5)) != 0)
		return 1;
	return 0;
}

int IS_SWP(u8 kpflags)
{
	if ((kpflags & (1ull << 14)) != 0)
		return 1;
	return 0;
}

#define BASE_PAGE_SHIFT 12
#define BASE_PAGE_SIZE (1 << 12)
#define HUGE_PAGE_SIZE (1 << 21)

int cal_swpness(int pid, char *raw_beg, size_t raw_size)
{
	char pmap_path[25];	/* enough for 10-digit pid */
	char kpflg_path[] = "/proc/kpageflags";
	int pmapf, kpflgf;
	int tot_cnt = 0;
	int swp_cnt = 0;
	int out_of_lru = 0;

	sprintf(pmap_path, "/proc/%d/pagemap", pid);
	pmapf = open(pmap_path, O_RDONLY);
	kpflgf = open(kpflg_path, O_RDONLY);

	u8 vaddr;
	u8 beg = (u8) raw_beg;
	u8 size = (u8) raw_size;
	printf("[module] beg= %llu\n", beg);
	
	u8 start_va = beg;

	// TODO: Is it true? (below)
	// size(word) to byte 
	u8 end_va = start_va + size * 2;

	// there are maximum 128 pages in one region.
	for (vaddr = start_va; vaddr < end_va; vaddr += BASE_PAGE_SIZE) {
		uint64_t ent = 0;
		u8 pfn = 0;
		uint64_t kpflags = 0;
		u8 is_swapped = 0;
		u8 is_present = 0;
		// u8 swap_type = 0;
		u8 offset = vaddr >> (BASE_PAGE_SHIFT - 3);

		lseek(pmapf, offset, SEEK_SET);
		if (read(pmapf, &ent, 8) == 8) {
			pfn = PAGEMAP_PFN(ent);
			if (pfn == 0) {
				printf("pfn is 0!\n");
				continue;
			}
			is_swapped = GET_BIT(ent, 62);
			is_present = GET_BIT(ent, 63);
			// swap_type = PAGEMAP_SWAPTYPE(ent);
			printf("is_swapped %llu, is_present %llu\n",is_swapped, is_present);
		} else {
			// TODO: error handling
			printf("Fail to read pagemaps file!\n");
			return -1;
		}
		lseek(kpflgf, pfn * 8, SEEK_SET);
		if (read(kpflgf, &kpflags, 8) == 8) {
			printf("Result: 0x%llx\n",(unsigned long long )kpflags);
			if (IN_LRU(kpflags) == 0) {
				out_of_lru++;
				continue;
			}
			if (IS_HUGE(kpflags) == 1) {
				vaddr += HUGE_PAGE_SIZE -
					BASE_PAGE_SIZE;
				printf("Huge!\n");
			}
			// Increase swp obj counter
			if (IS_SWP(kpflags) == 1)
				swp_cnt++;
			// Increase total counter
			tot_cnt++;
		} else {
			err(2, "%s: read kpageflag", __func__);
		}
	}
	close(pmapf);
	close(kpflgf);

	// Summarize swapness (swapped pages / total pages in LRU list)
	printf("# of out of lru: %d\n", out_of_lru);
	if (tot_cnt != 0 && swp_cnt != 0) {
		printf("swp / tot: %d / %d\n", swp_cnt, tot_cnt);
		printf("Swappiness: %f\n", (double) swp_cnt / (double) tot_cnt);
	} else if (swp_cnt == 0) {
		printf("Swapped pages is Zero! Total pages is %d\n", tot_cnt);
	} else {
		printf("total_count is Zero!\n");
	}

	return 0;
}

/* TODO: Currently used version */
double cal_swpness_1(int pid, char *raw_beg, char *raw_end)
{
	char pmap_path[25];	/* enough for 10-digit pid */
	char kpflg_path[] = "/proc/kpageflags";
	int pmapf, kpflgf;
	int tot_cnt = 0;
	int swp_cnt = 0;
	int out_of_lru = 0;
	double swpness;

	sprintf(pmap_path, "/proc/%d/pagemap", pid);
	pmapf = open(pmap_path, O_RDONLY);
	kpflgf = open(kpflg_path, O_RDONLY);

	u8 vaddr;
	u8 beg = (u8) raw_beg;
	u8 end = (u8) raw_end;
	// printf("[module] beg= %llu\n", beg);
	
	u8 start_va = beg;

	// TODO: Is it true? (below)
	// size(word) to byte 
	u8 end_va = end; 

	for (vaddr = start_va; vaddr < end_va; vaddr += BASE_PAGE_SIZE) {
		uint64_t ent = 0;
		u8 pfn = 0;
		uint64_t kpflags = 0;
		u8 is_swapped = 0;
		u8 offset = vaddr >> (BASE_PAGE_SHIFT - 3);

		lseek(pmapf, offset, SEEK_SET);
		if (read(pmapf, &ent, 8) == 8) {
			pfn = PAGEMAP_PFN(ent);
			if (pfn == 0) {
				// printf("[module-warning] pfn is 0!\n");
				continue;
			}
			is_swapped = GET_BIT(ent, 62);
		} else {
			// TODO: error handling
			printf("[module-error] Fail to read pagemaps file!\n");
			return -1;
		}
		
		lseek(kpflgf, pfn * 8, SEEK_SET);
		if (read(kpflgf, &kpflags, 8) == 8) {
			if (IN_LRU(kpflags) == 0) {
				out_of_lru++;
				continue;
			}
			if (IS_HUGE(kpflags) == 1) {
				vaddr += HUGE_PAGE_SIZE -
					BASE_PAGE_SIZE;
			}
			if (is_swapped == 1)
				swp_cnt++;
			tot_cnt++;
		} else {
			err(2, "%s: read kpageflag", __func__);
		}
		
	}
	close(pmapf);
	close(kpflgf);

	// Summarize swapness (swapped pages / total pages in LRU list)
	// printf("[module-warning] # of out of lru: %d\n", out_of_lru);
	if (swp_cnt != 0 && tot_cnt != 0) {
		// printf("[module-info] (Case 1) swp / tot: %d / %d\n", swp_cnt, tot_cnt);
		// printf("> Swappiness: %f\n", (double) swp_cnt / (double) tot_cnt);
		swpness = (double) swp_cnt / (double) tot_cnt;
	} else if (swp_cnt == 0 && tot_cnt != 0) {
		// printf("[module-info] (Case 2) Swapped pages is Zero! Total pages is %d\n", tot_cnt);
		// printf("> Swappiness: 0\n");
		swpness = 0;
	} else if (tot_cnt == 0) {
		// printf("[module-info] (Case 3) total_count is Zero!\n");
		// printf("> Swappiness: 0\n");
		swpness = 0;
	}
	// printf("----------------------------------------\n");
	
	return swpness;
}

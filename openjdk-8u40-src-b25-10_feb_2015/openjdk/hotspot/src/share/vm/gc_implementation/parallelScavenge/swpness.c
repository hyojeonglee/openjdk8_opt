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
 * [Swap related bit]
 * Bit 62. page swapped
 * Bit 63. page present
 *
 * So, We use flag number 62.
 *
 */

// hjlee: for test
u8 PAGEMAP_SWAPTYPE(u8 ent)
{
	return (ent & ((1ull << 5) - 1));
}

// hjlee: Currently used version
u8 PAGEMAP_ISSWAPPED(u8 ent)
{
	if((ent & (1ull << 62)) != 0)
		return 1;
	return 0;
}

// hjlee: for test
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

// hjlee: for kpageflags (not used at this version)
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

// hjlee: Currently used version
double cal_swpness_1(int pid, char *raw_beg, char *raw_end)
{
	// hjlee: Do not need kpageflag at this version.
	// char kpflg_path[] = "/proc/kpageflags";
	// int kpflgf;
	char pmap_path[25];	/* enough for 10-digit pid */
	int pmapf;
	int tot_cnt = 0;
	int swp_cnt = 0;
	int out_of_lru = 0;
	double swpness = 0;

	sprintf(pmap_path, "/proc/%d/pagemap", pid);
	pmapf = open(pmap_path, O_RDONLY);

	u8 vaddr;
	u8 beg = (u8) raw_beg;
	u8 end = (u8) raw_end;
	
	u8 start_va = beg;
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
				printf("[module-warning] pfn is 0!\n");
				continue;
			}
			is_swapped = GET_BIT(ent, 62);
		} else {
			// TODO: error handling
			printf("[module-error] Fail to read pagemaps file!\n");
			return -1;
		}
		if (is_swapped == 1)
			swp_cnt++;
		tot_cnt++;
	}
	close(pmapf);

	// Summarize swapness (swapped pages / total pages in LRU list)
	if (swp_cnt != 0 && tot_cnt != 0) {
		// hjlee: for debug
		// printf("[module-info] (Case 1) swp / tot: %d / %d\n", swp_cnt, tot_cnt);
		printf("> Swappiness: %f\n", (double) swp_cnt / (double) tot_cnt);
		
		swpness = (double) swp_cnt / (double) tot_cnt;
	} else if (swp_cnt == 0 && tot_cnt != 0) {
		// hjlee: for debug
		// printf("[module-info] (Case 2) Swapped pages is Zero! Total pages is %d\n", tot_cnt);
		printf("> Swappiness: 0\n");
		
		swpness = 0;
	} else if (tot_cnt == 0) {
		// hjlee: for debug
		// printf("[module-info] (Case 3) total_count is Zero!\n");
		printf("> Swappiness: 0\n");
		
		swpness = 0;
	}
	
	return swpness;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <err.h>
#include <fcntl.h>

typedef unsigned long long u8;

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

// Issue 1. How to get pid of jvm summary process?
// >>> First, we will use pidof or jps for test.
int cal_swpness(int pid, char *raw_beg, size_t raw_size)
{
	char pmap_path[25];	/* enough for 10-digit pid */
	char kpflg_path[] = "/proc/kpageflags";
	int pmapf, kpflgf;
	int tot_cnt = 0;
	int swp_cnt = 0;

	sprintf(pmap_path, "/proc/%d/pagemap", pid);
	pmapf = open(pmap_path, O_RDONLY);
	kpflgf = open(kpflg_path, O_RDONLY);

	u8 vaddr;
	// printf("[module] raw_beg= %llu\n", raw_beg);
	// printf("[module] raw_size= %d\n", raw_size);
	u8 beg = (u8) raw_beg;
	u8 size = (u8) raw_size;
	printf("[module] beg= %llu\n", beg);
	// printf("[module] size= %llu\n", size);
	
	u8 start_va = beg;

	// TODO: Is it true? (below)
	// u8 reg_size = size / (u8) 512;
	// u8 end_va = start_va + reg_size;
	u8 end_va = start_va + size;

	for (vaddr = start_va; vaddr < end_va; vaddr += BASE_PAGE_SIZE) {
		u8 ent, pfn = 0;
		u8 kpflags;

		u8 offset = vaddr >> (BASE_PAGE_SHIFT - 3);

		lseek(pmapf, offset, SEEK_SET);
		if (read(pmapf, &ent, 8) == 8) {
			// printf("ok1\n");
			pfn = PAGEMAP_PFN(ent);
			// printf("ok2\n");
			if (pfn == 0)
				continue;
		} else {
			// TODO: error handling
			printf("Fail to read pagemaps file!\n");
		}
		// printf("ok3\n");	
		lseek(kpflgf, pfn * 8, SEEK_SET);
		if (read(kpflgf, &kpflags, 8) == 8) {
			if (IN_LRU(kpflags) == 0)
				continue;
			if (IS_HUGE(kpflags) == 1) {
				vaddr += HUGE_PAGE_SIZE -
					BASE_PAGE_SIZE;
			}
			// Increase swp obj counter
			if (IS_SWP(kpflags) == 1)
				swp_cnt++;
			// Increase total counter
			tot_cnt++;
			// printf("ok4\n");
		} else {
			err(2, "%s: read kpageflag", __func__);
		}
	}
	close(pmapf);
	close(kpflgf);

	// Summarize swapness (swapped pages / total pages in LRU list)
	if (tot_cnt != 0) {
		printf("swp / tot: %d / %d\n", swp_cnt, tot_cnt);
		printf("Swappiness: %f\n", (double) swp_cnt / (double) tot_cnt);
	} else if (swp_cnt == 0) {
		printf("Swapped pages is Zero!\n");
	} else {
		printf("total_count is Zero!\n");
	}

	return 0;
}

/*************************************************************************
        > File Name: test_overcommit_memory.c
      > Author: Xiaohui Jiang
      > Mail: jiang_xiaohui@163.com 
      > Created Time: Fri Dec  6 15:03:45 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>

#define handle_error(msg) \
        do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main (int argc, char * argv[])
{
    int fd = -1;
	off_t offset = 0;
	void * addr;
	pid_t pid = getpid();
	long numofpages_mmap = 1;
	long numofpages_write = 0;
    size_t pagesize = sysconf(_SC_PAGE_SIZE);

	(argc > 1) ? numofpages_mmap = atol(argv[1]) : 1;
	(argc > 2) ? numofpages_write = atol(argv[2]) : 0;
	if (numofpages_write > numofpages_mmap)
		numofpages_write = numofpages_mmap;

    printf("%s numofpages_mmap %ld, numofpages_write %ld, pagesize %d\n", argv[0], numofpages_mmap, numofpages_write, pagesize);


	for (long i=0; i < numofpages_mmap; i++) {
        addr = mmap(NULL, pagesize, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, fd, offset);
		if (addr == MAP_FAILED)
			handle_error("mmap");
		printf("pid %d mmap returned at 0x%p\n", pid, addr);
		if (i < numofpages_write){
		    *(long *)addr = i;
		    printf("wrote\n");
		}
	}
	sleep(600);
    //close(fd);
}

/*************************************************************************
      > File Name: malloc_test.c
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
    void * addr;
    void * caddr;
    pid_t pid = getpid();
    long numofpages_malloc = 1;
    long numofpages_write = 0;
    long seconds_sleep = 0;
    size_t pagesize = sysconf(_SC_PAGE_SIZE);

    numofpages_malloc = (argc > 1) ? atol(argv[1]):1;
    numofpages_write  = (argc > 2) ? atol(argv[2]):0;
    seconds_sleep     = (argc > 3) ? atol(argv[3]):60;
    if (numofpages_write > numofpages_malloc)
	numofpages_write = numofpages_malloc;

    printf("%s numofpages_malloc %ld, numofpages_write %ld, pagesize %d\n", argv[0], numofpages_malloc, numofpages_write, pagesize);


    addr = malloc(pagesize * numofpages_malloc);
    if (addr == NULL)
	handle_error("malloc");
    printf("pid %d malloc returned at %p\n", pid, addr);
    memset(addr, 0x55, pagesize * numofpages_write);
    printf("wrote\n");

    caddr = calloc(pagesize, numofpages_malloc);
    if (caddr == NULL)
	handle_error("calloc");
    printf("pid %d calloc returned at %p\n", pid, caddr);
    memset(caddr, 0xef, pagesize * numofpages_write);
    printf("wrote\n");



    sleep(seconds_sleep);
    free(addr);
    free(caddr);

    return 0;
}

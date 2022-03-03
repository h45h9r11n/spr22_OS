#include <stdlib.h>
#include <sys/mman.h>
#include <cstring>
#include <unistd.h>

int main(){

    long page_size = sysconf(_SC_PAGE_SIZE);
    page_size *= 1024;
    void *p;
    while (1){
        p = mmap(NULL, page_size, PROT_WRITE|PROT_READ, MAP_PRIVATE|MAP_ANONYMOUS, 0, 0);
        memset(p, 0, page_size);
        system("grep MemAvailable /proc/meminfo|awk -F ':' '{print $2}'>> memavail.txt");
    }
    return 0;
}

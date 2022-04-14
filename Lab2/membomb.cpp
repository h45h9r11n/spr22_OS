#include <stdlib.h>
#include <sys/mman.h>
#include <cstring>
#include <unistd.h>

int main(){
    int size = 4096*1024;
    void *p;
    while (true){
        p = mmap(NULL, size, PROT_WRITE|PROT_READ, MAP_PRIVATE|MAP_ANONYMOUS, 0, 0);
        memset(p, '0', size);
        system("grep MemAvailable /proc/meminfo|awk -F ':' '{print $2}'>> memavail.txt");
    }
    return 0;
}

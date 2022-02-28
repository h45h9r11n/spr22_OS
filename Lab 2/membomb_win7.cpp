#include <stdlib.h>
#include <windows.h>
#include <cstring>
#include <unistd.h>
using namespace std;

int main(){
    SYSTEM_INFO si;
	GetSystemInfo(&si);
	printf("The page size for this system is %u bytes.\n", si.dwPageSize);
    int size = 4096*1024;
    void *ptr;
    while (true){
        LPVOID ptr = VirtualAlloc(NULL,size,MEM_RESERVE,PAGE_READWRITE); //reserving memory
        ptr = VirtualAlloc(ptr,size,MEM_COMMIT,PAGE_READWRITE); //commiting memory
        memset(ptr, '0', size);
    }
    return 0;
}

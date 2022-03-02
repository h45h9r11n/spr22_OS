#include <stdlib.h>
#include <windows.h>
#include <cstring>
#include <unistd.h>
using namespace std;

int main() {

    MEMORYSTATUSEX status;
    status.dwLength = sizeof(status);
    GlobalMemoryStatusEx(&status);
    total = status.ullTotalPhys;

    SYSTEM_INFO si;
    GetSystemInfo(&si);
    int psize = si.dwPageSize;
    int size = (int)total / psize;
    void* ptr;
    for (int i = 0; i < psize, i++) {
        LPVOID ptr = VirtualAlloc(NULL, size, MEM_RESERVE, PAGE_READWRITE);
        ptr = VirtualAlloc(ptr, size, MEM_COMMIT, PAGE_READWRITE);
        memset(ptr, '0', size);
    }
    return 0;
}

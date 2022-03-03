#include <stdlib.h>
#include <windows.h>
#include <cstring>
#include <unistd.h>
using namespace std;

int main() {
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    int size = si.dwPageSize;

    void* ptr;
    while (1){
        LPVOID ptr = VirtualAlloc(NULL, size, MEM_RESERVE, PAGE_READWRITE);
        ptr = VirtualAlloc(ptr, size, MEM_COMMIT, PAGE_READWRITE);
        memset(ptr, '0', size);
    }
    return 0;
}

#include <chrono>
#include <fstream>
#include <stdlib.h>   
#include <linux/kernel.h>
#include <unistd.h>

void* callAlocator(int num, size_t size){
    if (num == 1){
        return malloc (sizeof(int) * size);
    }

    if (num == 2){
        return new int[size]; 
    }

    if (num == 3){
        return sbrk(sizeof(int) * size);
    }
    return NULL;
}

void callFree(int num, void *ptr){
    if (num == 1){
        free(ptr);
        return;
    }

    if (num == 2){
        delete ptr;
        return;
    }

}

int main () {
    std::ofstream resfile;
    resfile.open ("result1.txt");

    std::chrono::steady_clock::time_point begin, end; 
    
        
    for (size_t i = 0; i < 1073741824; i = i + 1024*4096){
        resfile << i*4 << " ";
        for (int type = 3; type <= 3; type ++){
            
            // begin = std::chrono::steady_clock::now();
            void* ptr = callAlocator(type, i);
            // end = std::chrono::steady_clock::now();
            // resfile << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << " ";
            
            begin = std::chrono::steady_clock::now();
            //callFree(type, ptr);
            ptr = sbrk((-1)*sizeof(int) * i);
            end = std::chrono::steady_clock::now();
            resfile << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << " ";
        }
        resfile << std::endl;
    }
    
    resfile.close();
    return 0;
}

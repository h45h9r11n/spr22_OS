#include <chrono>
#include <fstream>
#include <stdlib.h>   
#include <linux/kernel.h>

void* callAlocator(int num, size_t size){
    if (num == 1){
        return malloc (sizeof(int) * size);
    }

    if (num == 2){
        return new int[size]; 
    }

    if (num == 3){
        return farmalloc(size * sizeof(int));
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

    if (num == 3){
        farfree(ptr);
        return;
    }

}

int main () {
    std::ofstream resfile;
    resfile.open ("result.txt");

    std::chrono::steady_clock::time_point begin, end; 
    
        
    for (size_t i = 0; i < 1073741; i = i + 1024*4096){
        resfile << i*4 << " ";
        for (int type = 1; type <= 3; type ++){
            
            begin = std::chrono::steady_clock::now();
            void* ptr = callAlocator(type, i);
            end = std::chrono::steady_clock::now();
            resfile << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << std::endl;
            
            // begin = std::chrono::steady_clock::now();
            // callFree(type, ptr);
            // end = std::chrono::steady_clock::now();
            // resfile << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << " ";
        }
        resfile << std::endl;
    }
    
    resfile.close();
    return 0;
}

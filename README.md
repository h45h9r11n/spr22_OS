# Operating System
## Лаб 1. Forkbomb
    Требование
    1. Написать программу forkbomb для Linux, Windows
    2. Составить график числа процессов в ОС
    3. Как ОС реагирует на форкбомбу

-	In computing, a fork bomb (also called rabbit virus or wabbit) is a denial-of-service attack wherein a process continually replicates itself to deplete available system resources, slowing down or crashing the system due to resource starvation.
-	 Count the number of processes running on your system by any user:
   `ps aux | wc –l` 
-	Windows using PowerShell, the following two commands will get that information:
    + Number of processes running: `(Get-Process).Count` 
    + Number of threads running: `(Get-Process|Select-Object -ExpandProperty Threads).Count`
-	Routine, Required header
  `system, <process.h> or <stdlib.h>`
-	Write data to text file in powershell `Add-Content -Path `
  `C:\Users\hanhnguyen26\countProcess.txt -Value (Get-Process).Count`
## Лаб 2. Membomb
    Требование
    1. Написать программу выделения памяти и заполнения ее нулями с шагом, равным размеру страницы памяти (mmap, VirtualAlloc)
    2. Составить график свободной памяти
    3. Ознакомиться с работой демона OOM Killer в Linux
    4. Достичь сообщения о невозможности выделить память в Windows
### mmap
    void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
- Trả về địa chỉ đầu tiên của mapping, hoặc MAP_FAILED nếu lỗi
- `addr` chỉ định địa chỉ đầu tiên của vùng nhớ mapping trong bộ nhớ ảo của tiến trình. Nếu `addr` được truyền NULL (cách này được sử dụng rất thường xuyên), kernel sẽ chọn 1 địa chỉ thích hợp để đặt vùng nhớ mapping này.
- `length` chỉ định kích thước của vùng nhớ mapping theo đơn vị byte. Kernel tạo memory mapping theo đơn vị là trang (page - thường là 4096 byte).
- `prot` là bit mask chỉ định chế độ bảo vệ truy cập của vùng mapping. Nó có thể là `PROT_NONE` hoặc kết hợp (toán tử OR) với các cờ sau đây:
    + `PROT_EXEC` cho phép execute.
    + `PROT_READ`  cho phép đọc.
    + `PROT_WRITE` cho phép ghi.
    + `PROT_NONE` không cho phép truy cập.
### Difference between `memFree` and `memAvailable`
   + `memFree` The amount of physical RAM, in kilobytes, left unused by the system.
   + `memAvailable` An estimate of how much memory is available for starting new applications, without swapping. Calculated from MemFree, SReclaimable, the size of the file LRU lists, and the low watermarks in each zone. The estimate takes into account that the system needs some page cache to function well, and that not all reclaimable slab will be reclaimable, due to items being in use. The impact of those factors will vary from system to system.

## Лаб 3.
    Простой вариант
        Найти и скомпилировать программу linpack для оценки производительности компьютера (Flops) и протестировать ее при различных режимах работы ОС:
        1.	С различными приоритетами задачи в планировщике
        2.	С наличием и отсутствием привязки к процессору
        3.	Провести несколько тестов, сравнить результаты по 3 сигма или другим статистическим критериям
    Усиленный вариант
        То же самое, плюс изменить параметры на уровне ядра (выбрать одно): 
        1.	Запретить выполнение всех потоков кроме того, который тестируется (путем запрета прерываний) (cli sti)
        2.	Найти другие планировщики процессов для Linux и сравнить результаты работы вычислительной задачи на них
        3.	Повлиять на настройки имеющегося планировщика
        4.	Вмешаться в работу планировщика на уровне ядра


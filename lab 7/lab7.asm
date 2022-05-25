;nasm -felf64 lab7.asm -o a.o
;ld -g a.o
;./a.out
global _start

section .data
        VM:     db 'Virtual Machine',0xA
        VM_l:  equ $-VM
        PM:     db 'Physical Machine',0xA
        PM_l:  equ $-PM

section .bss
section .text

_start:
        xor eax, eax
        mov eax, 1
        cpuid
        bt ecx, 0x1f
        jc .VM 
        jnc .PM

.VM:
        mov     edx, VM_l     ; Arg three: the length of the string
        mov     ecx, VM        ; Arg two: the address of the string
        call .print
.PM:
        mov     edx, PM_l     ; Arg three: the length of the string
        mov     ecx, PM        ; Arg two: the address of the string

.print:
        mov     ebx, 1          ; Arg one: file descriptor, in this case stdout
        mov     eax, 4          ; Syscall number, in this case the write(2) syscall: 
        int     0x80            ; Interrupt 0x80        

        mov     ebx, 0          ; Arg one: the status
        mov     eax, 1          ; Syscall number:
        int     0x80

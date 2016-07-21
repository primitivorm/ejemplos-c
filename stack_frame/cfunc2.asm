        ;FILE "cfunc2.c"
gcc2_compiled.: 
SECTION .text
        ALIGN 4
GLOBAL add
        GLOBAL add:function
add: 
        push  ebp
        mov  ebp,esp
        sub  esp,4
        mov  dword [ebp-4],22
        mov  eax, [ebp+8]
        mov  edx, [ebp+12]
        lea  ecx, [edx+eax]
        mov  [ebp-4],ecx
        mov  edx, [ebp-4]
        mov  eax,edx
        jmp L1
        ;ALIGN 1<<4 ; IF < 7
L1:
        leave
        ret
.Lfe1: 
        GLOBAL   add:function (.Lfe1-add)
        ALIGN 4
GLOBAL times5
        GLOBAL times5:function
times5: 
        push  ebp
        mov  ebp,esp
        sub  esp,12
        mov  dword [ebp-4],43
        mov  dword [ebp-8],45
        mov  dword [ebp-12],49
        mov  eax, [ebp+8]
        push  eax
        mov  eax, [ebp+8]
        push  eax
        call add
        add  esp,8
        mov  eax,eax
        mov  [ebp-4],eax
        mov  eax, [ebp+8]
        push  eax
        mov  eax, [ebp-4]
        push  eax
        call add
        add  esp,8
        mov  eax,eax
        mov  [ebp-8],eax
        mov  eax, [ebp-8]
        push  eax
        mov  eax, [ebp-4]
        push  eax
        call add
        add  esp,8
        mov  eax,eax
        mov  [ebp-12],eax
        mov  edx, [ebp-12]
        mov  eax,edx
        jmp L2
        ;ALIGN 1<<4 ; IF < 7
L2:
        leave
        ret
.Lfe2: 
        GLOBAL   times5:function (.Lfe2-times5)
SECTION         .rodata
.LC0: 
        db      'b = %d',10,''
SECTION .text
        ALIGN 4
GLOBAL main
        GLOBAL main:function
main: 
        push  ebp
        mov  ebp,esp
        sub  esp,8
        mov  dword [ebp-4],13
        mov  dword [ebp-8],17
        mov  eax, [ebp-4]
        push  eax
        call times5
        add  esp,4
        mov  eax,eax
        mov  [ebp-8],eax
        mov  eax, [ebp-8]
        push  eax
        push  dword .LC0
        call printf
        add  esp,8
L3:
        leave
        ret
.Lfe3: 
        GLOBAL   main:function (.Lfe3-main)
        ;IDENT "GCC: (GNU) egcs-2.91.66 19990314/Linux (egcs-1.1.2 release)"


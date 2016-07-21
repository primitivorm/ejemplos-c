        ;FILE "cfunc3.c"
gcc2_compiled.:
SECTION .text
        ALIGN 4
GLOBAL foo
        GLOBAL foo:function
foo:                                    ; comments and white space added
        push  ebp                       ; set up stack frame
        mov  ebp,esp

        mov  eax, [ebp+8]               ; addr to store return value
        add  dword [ebp+12],4           ; r.part1 = [ebp+12]
        add  dword [ebp+16],3           ; r.part2 = [ebp+16]

        ; return value
        ;
        mov  edx, [ebp+12]              ; get r.part1
        mov  ecx, [ebp+16]              ; get r.part2
        mov  [eax],edx                  ; store r.part1 in return value
        mov  [eax+4],ecx                ; store r.part2 in return value
        jmp L1
L1:
        mov  eax,eax                    ; does nothing
        leave                           ; bye-bye
        ret 4                           ; pop off 4 bytes after return
.Lfe1:



        GLOBAL   foo:function (.Lfe1-foo)
SECTION         .rodata
.LC0:
        db      'r2.part1 = %d, r2.part2 = %d',10,''
SECTION .text
        ALIGN 4
GLOBAL main
        GLOBAL main:function
main:                                   ; comments and white space added
        push  ebp                       ; set up stack frame
        mov  ebp,esp
        sub  esp,36                     ; space for local variables

        ; initialize variables
        ;
        mov  dword [ebp-28],17          ; n = [ebp-28]
        mov  dword [ebp-8],74           ; r1 = [ebp-8]
        mov  dword [ebp-4],75
        mov  dword [ebp-16],84          ; r2 = [ebp-16]
        mov  dword [ebp-12],85
        mov  dword [ebp-24],93          ; r3 = [ebp-24]
        mov  dword [ebp-20],99

        ; call foo
        ;
        lea  eax, [ebp-16]              ; get addr of r2
        mov  edx, [ebp-8]               ; get r1.part1
        mov  ecx, [ebp-4]               ; get r1.part2
        push  ecx                       ; push r1.part2
        push  edx                       ; push r1.part1
        push  eax                       ; push addr of r2
        call foo
        add  esp,8                      ; pop r1, ret 4 popped r2's addr

        ; call printf
        ;
        mov  eax, [ebp-12]              ; get r2.part2
        push  eax                       ; push it
        mov  eax, [ebp-8]               ; get r2.part1
        push  eax                       ; push it
        push  dword .LC0                ; string constant's addr
        call printf
        add  esp,12                     ; pop off arguments

        ; call foo again
        ;
        lea  eax, [ebp-36]              ; addr of temp variable
        mov  edx, [ebp-24]              ; get r3.part1
        mov  ecx, [ebp-20]              ; get r3.part2
        push  ecx                       ; push r3.part2
        push  edx                       ; push r3.part1
        push  eax                       ; push addr of temp var
        call foo
        add  esp,8                      ; pop off arguments

        ; assign to n
        ;
        mov  eax, [ebp-32]              ; get part2 of temp var
        mov  [ebp-28],eax               ; store in n

L2:
        leave                           ; bye-bye
        ret
.Lfe2:
        GLOBAL   main:function (.Lfe2-main)
        ;IDENT "GCC: (GNU) egcs-2.91.66 19990314/Linux (egcs-1.1.2 release)"


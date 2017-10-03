	.file	"tmp.c"
	.section	.rodata
.LC1:
	.string	"%f"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movabsq	$8026099884445561421, %rax
	movq	%rax, -14(%rbp)
	movw	$116, -6(%rbp)
	movss	.LC0(%rip), %xmm0
	movss	%xmm0, -4(%rbp)
	leaq	-14(%rbp), %rax
	movq	%rax, %rdi
	call	puts@PLT
	cvtss2sd	-4(%rbp), %xmm0
	leaq	.LC1(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC0:
	.long	1078530000
	.ident	"GCC: (Debian 7.2.0-7) 7.2.0"
	.section	.note.GNU-stack,"",@progbits

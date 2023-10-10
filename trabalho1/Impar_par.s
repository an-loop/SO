.file	"Impar_par.c"
	.text
	.section	.rodata
.LC0:
	.string	"%d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1104, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movabsq	$8439857252351306052, %rax
	movabsq	$8243115341881679981, %rdx
	movq	%rax, -1072(%rbp)
	movq	%rdx, -1064(%rbp)
	movabsq	$8244232143621398639, %rax
	movq	%rax, -1056(%rbp)
	movl	$2112111, -1048(%rbp)
	movabsq	$3346844607301927712, %rax
	movq	%rax, -1095(%rbp)
	movw	$10, -1087(%rbp)
	movabsq	$8101322358287614752, %rax
	movq	%rax, -1085(%rbp)
	movl	$170816097, -1077(%rbp)
	movb	$0, -1073(%rbp)
	leaq	-1072(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movq	%rax, %rdx
	leaq	-1072(%rbp), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	call	write@PLT
	leaq	-1040(%rbp), %rax
	movl	$1024, %edx
	movq	%rax, %rsi
	movl	$0, %edi
	call	read@PLT
	leaq	-1104(%rbp), %rdx
	leaq	-1040(%rbp), %rax
	leaq	.LC0(%rip), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_sscanf@PLT
	movl	-1104(%rbp), %edx
	leaq	-1040(%rbp), %rax
	leaq	.LC0(%rip), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	sprintf@PLT
	movl	%eax, -1100(%rbp)
	movl	-1104(%rbp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	.L2
	movl	-1100(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-1040(%rbp), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	call	write@PLT
	leaq	-1095(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movq	%rax, %rdx
	leaq	-1095(%rbp), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	call	write@PLT
	jmp	.L3
.L2:
	movl	-1100(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-1040(%rbp), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	call	write@PLT
	leaq	-1085(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movq	%rax, %rdx
	leaq	-1085(%rbp), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	call	write@PLT
.L3:
	movl	$0, %edi
	call	_exit@PLT
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
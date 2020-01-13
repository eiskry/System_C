	.file	"test1.c"
	.text
	.globl	fact
	.type	fact, @function
fact:
.LFB0:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$8, %esp
	.cfi_def_cfa_offset 16
	movl	16(%esp), %ebx
	cmpl	$1, %ebx
	jne	.L4
.L2:
	movl	%ebx, %eax
	addl	$8, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
.L4:
	.cfi_restore_state
	subl	$12, %esp
	.cfi_def_cfa_offset 28
	leal	-1(%ebx), %eax
	pushl	%eax
	.cfi_def_cfa_offset 32
	call	fact
	addl	$16, %esp
	.cfi_def_cfa_offset 16
	imull	%eax, %ebx
	jmp	.L2
	.cfi_endproc
.LFE0:
	.size	fact, .-fact
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits

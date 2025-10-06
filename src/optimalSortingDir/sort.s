	.file	"sort.c"
	.text
	.p2align 4
	.globl	sort
	.type	sort, @function
sort:
.LFB11:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	movslq	%esi, %r12
	movl	$4, %esi
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movq	%rdi, %rbx
	movq	%r12, %rdi
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	call	calloc@PLT
	movq	%rax, %r8
	testl	%r12d, %r12d
	jle	.L9
	movl	%r12d, %edx
	movq	%rbx, %rsi
	leal	-1(%r12), %ebp
	movq	%rax, %rdi
	salq	$2, %rdx
	call	memcpy@PLT
	leaq	0(,%r12,4), %rdi
	movq	%rax, %r8
	leaq	-4(%rbx,%rdi), %rsi
	.p2align 4
	.p2align 3
.L3:
	movq	%rbx, %rax
	testl	%ebp, %ebp
	jle	.L7
	.p2align 6
	.p2align 4
	.p2align 3
.L5:
	movq	(%rax), %xmm0
	pshufd	$0xe5, %xmm0, %xmm1
	movd	%xmm0, %ecx
	movd	%xmm1, %edx
	cmpl	%edx, %ecx
	jle	.L4
	pshufd	$225, %xmm0, %xmm0
	movq	%xmm0, (%rax)
.L4:
	addq	$4, %rax
	cmpq	%rsi, %rax
	jne	.L5
.L7:
	subl	$1, %ebp
	cmpq	%rbx, %rsi
	je	.L10
	subq	$4, %rsi
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L10:
	xorl	%eax, %eax
	xorl	%ebp, %ebp
	.p2align 5
	.p2align 4
	.p2align 3
.L6:
	movl	(%r8,%rax), %esi
	cmpl	%esi, (%rbx,%rax)
	je	.L8
	addl	$1, %ebp
.L8:
	addq	$4, %rax
	cmpq	%rdi, %rax
	jne	.L6
.L2:
	movq	%r8, %rdi
	call	free@PLT
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	movl	%ebp, %eax
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
.L9:
	.cfi_restore_state
	xorl	%ebp, %ebp
	jmp	.L2
	.cfi_endproc
.LFE11:
	.size	sort, .-sort
	.ident	"GCC: (GNU) 15.2.1 20250813"
	.section	.note.GNU-stack,"",@progbits

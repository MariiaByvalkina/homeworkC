	.file	"sort.c"
	.text
	.p2align 4
	.globl	bubbleSort
	.type	bubbleSort, @function
bubbleSort:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r13
	pushq	%r12
	.cfi_offset 13, -24
	.cfi_offset 12, -32
	movslq	%esi, %r12
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -40
	movq	%fs:40, %r13
	movq	%r13, -40(%rbp)
	movq	%r12, %r13
	salq	$2, %r12
	leaq	15(%r12), %rax
	andq	$-16, %rax
	subq	%rax, %rsp
	testl	%r13d, %r13d
	jle	.L10
	movl	%r13d, %edx
	movq	%rdi, %rsi
	movq	%rdi, %rbx
	movq	%rsp, %rdi
	salq	$2, %rdx
	call	memcpy@PLT
	movq	%rsp, %r8
	cmpl	$1, %r13d
	jne	.L19
.L3:
	xorl	%eax, %eax
	xorl	%edx, %edx
	.p2align 5
	.p2align 4
	.p2align 3
.L8:
	movl	(%rbx,%rax), %edi
	cmpl	%edi, (%r8,%rax)
	je	.L7
	addl	$1, %edx
.L7:
	addq	$4, %rax
	cmpq	%rax, %r12
	jne	.L8
.L1:
	movq	-40(%rbp), %rax
	subq	%fs:40, %rax
	jne	.L20
	leaq	-24(%rbp), %rsp
	movl	%edx, %eax
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.L10:
	.cfi_restore_state
	xorl	%edx, %edx
	jmp	.L1
.L19:
	leal	-2(%r13), %eax
	xorl	%edi, %edi
	leaq	4(%rbx,%rax,4), %rsi
	.p2align 4
	.p2align 3
.L6:
	movq	%rbx, %rax
	.p2align 6
	.p2align 4
	.p2align 3
.L5:
	movq	(%rax), %xmm0
	pshufd	$0xe5, %xmm0, %xmm1
	movd	%xmm0, %edx
	movd	%xmm1, %ecx
	cmpl	%edx, %ecx
	jge	.L4
	pshufd	$225, %xmm0, %xmm0
	movq	%xmm0, (%rax)
.L4:
	addq	$4, %rax
	cmpq	%rsi, %rax
	jne	.L5
	addl	$1, %edi
	cmpl	%edi, %r13d
	jne	.L6
	jmp	.L3
.L20:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE0:
	.size	bubbleSort, .-bubbleSort
	.ident	"GCC: (GNU) 15.2.1 20250813"
	.section	.note.GNU-stack,"",@progbits

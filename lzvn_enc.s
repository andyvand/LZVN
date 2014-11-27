.text
.align 8

.extern _memcpy
.globl _lzvn_encode_partial
.globl _lzvn_encode

_lzvn_encode:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	pushq	%rax
	movq	%r8, %rax
	movq	%rcx, %rbx
	movq	$0x0, -0x10(%rbp)
	leaq	-0x10(%rbp), %r8
	movq	%rax, %r9
	callq	_lzvn_encode_partial
	xorl	%ecx, %ecx
	cmpq	%rbx, -0x10(%rbp)
	cmoveq	%rax, %rcx
	movq	%rcx, %rax
	addq	$0x8, %rsp
	popq	%rbx
	popq	%rbp
	retq

_lzvn_encode_partial:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$0xc8, %rsp
	movq	%r9, -0xc0(%rbp)
	movq	%r8, -0xe8(%rbp)
	movq	%rdx, %r12
	movq	%r12, -0xb0(%rbp)
	movq	%rdi, -0xd8(%rbp)
	xorl	%edx, %edx
	cmpq	$0x8, %rsi
	jb		L103
	cmpq	$0x8, %rcx
	movl	$0x0, %ebx
	jb		L114
	movl	$0xffffffff, %eax
	addq	$-0x8, %rsi
	movl	(%r12), %r10d
	movd	%r10d, %xmm0
	pshufd	$0x0, %xmm0, %xmm0
	pxor	%xmm1, %xmm1
	xorl	%edx, %edx

L1:
	movdqa	%xmm1, (%r9,%rdx)
	movdqa	%xmm0, 0x10(%r9,%rdx)
	addq	$0x20, %rdx
	cmpq	$0x80000, %rdx
	jne		L1
	cmpq	%rax, %rcx
	cmovaq	%rax, %rcx
	movq	%rcx, -0x68(%rbp)
	leaq	(%rdi,%rsi), %r11
	movq	%r11, -0xc8(%rbp)
	xorl	%eax, %eax
	cmpq	$0x9, %rcx
	jb		L104
	testq	%rsi, %rsi
	movq	%rdi, %r8
	jle		L105
	movq	%r11, %r14
	movq	%rcx, -0x68(%rbp)
	leaq	-0x1(%r12), %rax
	movq	%rax, -0xe0(%rbp)
	xorl	%eax, %eax
	movq	%rax, -0x90(%rbp)
	movq	%rdi, -0x78(%rbp)
	xorl	%r13d, %r13d
	xorl	%esi, %esi
	xorl	%eax, %eax
	movq	%rax, -0x50(%rbp)
	xorl	%eax, %eax
	movq	%rax, -0xb8(%rbp)
	movq	%rdi, -0xd0(%rbp)
	movq	%rdi, -0xd8(%rbp)
	xorl	%edi, %edi
	xorl	%r8d, %r8d
	xorl	%r11d, %r11d
	xorl	%edx, %edx
	xorl	%ecx, %ecx
	movl	%r10d, %eax
	jmp		L3

L2:
	movq	%r11, %r14
	incq	%rsi
	movl	(%r12,%rsi), %eax
	decq	-0x90(%rbp)
	movq	%rdi, %rcx
	movq	%rcx, -0x50(%rbp)
	movq	%rdx, %rdi
	movq	-0x40(%rbp), %r8
	movq	%rbx, %r11
	movq	%r10, %rdx
	movq	%r15, %rcx

L3:
	movl	%eax, -0x84(%rbp)
	movl	%eax, %ebx
	andl	$0xffffff, %eax
	imull	$0x1041, %eax, %eax
	shrl	$0xc, %eax
	andl	$0x3fff, %eax
	shlq	$0x5, %rax
	movdqa	(%r9,%rax), %xmm0
	movdqa	0x10(%r9,%rax), %xmm1
	pshufd	$-0x70, %xmm1, %xmm3
	pshufd	$-0x70, %xmm0, %xmm4
	movd	%esi, %xmm2
	movss	%xmm2, %xmm4
	movd	%ebx, %xmm2
	movss	%xmm2, %xmm3
	movaps	%xmm3, 0x10(%r9,%rax)
	movaps	%xmm4, (%r9,%rax)
	testq	%rsi, %rsi
	je		L5
	cmpq	%r13, %rsi
	jb		L5
	movq	%rdi, -0xa8(%rbp)
	movq	%rcx, -0x80(%rbp)
	movq	%r11, -0xa0(%rbp)
	movq	-0x68(%rbp), %r10
	pshufd	$0x0, %xmm2, %xmm2
	pxor	%xmm2, %xmm1
	movd	%xmm1, %ecx
	testl	%ecx, %ecx
	movl	$0x4, %eax
	je		L4
	movq	%rdx, -0x70(%rbp)
	movl	%ecx, %eax
	bsfq	%rax, %rax
	cmpq	$0x18, %rax
	movl	$0x0, %ecx
	movq	%rcx, -0x48(%rbp)
	movl	$0x0, %ecx
	movq	%rcx, -0x60(%rbp)
	movl	$0x0, %edi
	movl	$0x0, %r11d
	movl	$0x0, %ecx
	jb		L13
	shrq	$0x3, %rax
	movq	-0x70(%rbp), %rdx

L4:
	movq	%rdx, -0x70(%rbp)
	movd	%xmm0, %ecx
	movl	%ecx, %r14d
	movq	%rsi, %r15
	subq	%r14, %r15
	cmpq	$0xffff, %r15
	movl	$0x0, %ecx
	movq	%rcx, -0x48(%rbp)
	movl	$0x0, %ecx
	movq	%rcx, -0x60(%rbp)
	movl	$0x0, %edi
	movl	$0x0, %r11d
	movl	$0x0, %ecx
	ja		L13
	leaq	(%rax,%rsi), %r11
	cmpq	$0x4, %rax
	jne		L9
	movq	%r8, -0x40(%rbp)
	leaq	0x4(%rax,%rsi), %rax
	jmp		L7

L5:
	movq	%rcx, %r15
	movq	%rdx, %r10
	movq	%r11, %rbx
	movq	%r8, -0x40(%rbp)
	movq	%rdi, %rdx
	movq	-0x50(%rbp), %rcx
	movq	%rcx, %rdi
	movq	-0x68(%rbp), %rcx
	movq	%r14, %r11
	jmp		L101

L6:
	leaq	0x4(%rdx,%rax), %rax

L7:
	cmpq	%r10, %rax
	movq	%r11, %rax
	jae		L10
	movq	%rax, %rdx
	subq	%r15, %rdx
	movl	(%r12,%rax), %ebx
	movl	(%r12,%rdx), %edi
	cmpl	%edi, %ebx
	movl	$0x4, %edx
	je		L8
	xorl	%ebx, %edi
	bsfq	%rdi, %rdx
	shrq	$0x3, %rdx

L8:
	leaq	(%rdx,%rax), %r11
	cmpq	$0x4, %rdx
	je		L6
	jmp		L10

L9:
	movq	%r8, -0x40(%rbp)

L10:
	movq	-0xe0(%rbp), %rax
	leaq	(%rax,%rsi), %rdx
	leaq	(%rax,%r14), %rdi
	xorl	%ebx, %ebx

L11:
	movq	%rbx, %rax
	leaq	(%rsi,%rax), %rcx
	movq	%r14, %rbx
	addq	%rax, %rbx
	je		L12
	cmpq	%r13, %rcx
	jbe		L12
	movq	%rcx, %r8
	movq	%rsi, %rcx
	movzbl	(%rdi,%rax), %esi
	movzbl	(%rdx,%rax), %r9d
	leaq	-0x1(%rax), %rbx
	cmpl	%esi, %r9d
	movq	%rcx, %rsi
	movq	%r8, %rcx
	je		L11

L12:
	cmpq	$0x5ff, %r15
	seta	%dl
	movzbl	%dl, %r8d
	movq	%rsi, %r9
	leaq	0x2(%r8,%r9), %rsi
	subq	%r11, %rsi
	addq	%rax, %rsi
	setne	%sil
	cmpq	$0x1, %r11
	seta	%bl
	movq	-0x90(%rbp), %rdi
	leaq	(%r11,%rdi), %rdi
	movq	$-0x2, %rdx
	subq	%r8, %rdx
	addq	%rdi, %rdx
	subq	%rax, %rdx
	subq	%rax, %rdi
	orb		%sil, %bl
	movq	%r9, %rsi
	movl	$0x0, %eax
	cmoveq	%rax, %rdx
	movq	%rdx, -0x48(%rbp)
	cmoveq	%rax, %r15
	cmoveq	%rax, %rdi
	cmoveq	%rax, %r11
	cmoveq	%rax, %rcx
	movq	%r15, -0x60(%rbp)
	movq	-0x40(%rbp), %r8

L13:
	movq	%rdi, -0x58(%rbp)
	movq	%rcx, -0x40(%rbp)
	pshufd	$0x1, %xmm1, %xmm2
	movd	%xmm2, %eax
	testl	%eax, %eax
	movl	$0x4, %edx
	je		L14
	movl	%eax, %eax
	bsfq	%rax, %rdx
	cmpq	$0x18, %rdx
	jb		L15
	shrq	$0x3, %rdx

L14:
	pshufd	$0x1, %xmm0, %xmm2
	movd	%xmm2, %eax
	movl	%eax, %eax
	movq	%rsi, %rcx
	subq	%rax, %rcx
	cmpq	$0xffff, %rcx
	jbe		L16

L15:
	movq	%rsi, %r15
	movq	%r10, %r9
	jmp		L25

L16:
	movq	%rsi, %rdi
	leaq	(%rdx,%rdi), %rsi
	cmpq	$0x4, %rdx
	jne		L20
	leaq	0x4(%rdx,%rdi), %rdx
	movq	%rdi, %r15
	jmp		L18

L17:
	leaq	0x4(%rdi,%rdx), %rdx

L18:
	cmpq	%r10, %rdx
	movq	%rsi, %rdx
	jae		L21
	movq	%rdx, %rsi
	subq	%rcx, %rsi
	movl	(%r12,%rdx), %ebx
	movl	(%r12,%rsi), %esi
	cmpl	%esi, %ebx
	movl	$0x4, %edi
	je		L19
	xorl	%ebx, %esi
	bsfq	%rsi, %rdi
	shrq	$0x3, %rdi

L19:
	leaq	(%rdi,%rdx), %rsi
	cmpq	$0x4, %rdi
	je		L17
	jmp		L21

L20:
	movq	%rdi, %r15

L21:
	movq	%r10, %r9
	movq	%r15, %rdx

L22:
	movq	%rdx, %r14
	testq	%rax, %rax
	je		L23
	cmpq	%r13, %r14
	jbe		L23
	leaq	-0x1(%r14), %rdx
	movzbl	-0x1(%r12,%rax), %edi
	decq	%rax
	movzbl	-0x1(%r12,%r14), %ebx
	cmpl	%edi, %ebx
    je		L22

L23:
	movq	%rsi, %rax
	subq	%r14, %rax
	cmpq	$0x5ff, %rcx
	seta	%dl
	movzbl	%dl, %edi
	orq		$0x2, %rdi
	movq	%rax, %rdx
	subq	%rdi, %rdx
	cmpq	-0x48(%rbp), %rdx
	ja		L24
	cmpq	-0x48(%rbp), %rdx
	jne		L25
	leaq	0x1(%r11), %rdi
	cmpq	%rdi, %rsi
	jbe		L25

L24:
	movq	%rdx, -0x48(%rbp)
	movq	%rcx, -0x60(%rbp)
	movq	%rax, -0x58(%rbp)
	movq	%rsi, %r11
	movq	%r14, -0x40(%rbp)

L25:
	movdqa	%xmm1, %xmm2
	punpckhdq	%xmm2, %xmm2
	movd	%xmm2, %eax
	testl	%eax, %eax
	movl	$0x4, %edx
	movq	%r9, %r14
	je		L26
	movl	%eax, %eax
	bsfq	%rax, %rdx
	cmpq	$0x18, %rdx
	jb		L27
	shrq	$0x3, %rdx

L26:
	movdqa	%xmm0, %xmm2
	punpckhdq	%xmm2, %xmm2
	movd	%xmm2, %eax
	movl	%eax, %eax
	movq	%r15, %r9
	subq	%rax, %r9
	cmpq	$0xffff, %r9
	jbe		L28

L27:
	movq	%r15, %r10
	movq	-0x70(%rbp), %r15
	jmp		L37

L28:
	leaq	(%rdx,%r15), %rsi
	cmpq	$0x4, %rdx
	jne		L32
	leaq	0x4(%rdx,%r15), %rdx
	movq	%r15, %r10
	jmp		L30

L29:
	leaq	0x4(%rdi,%rdx), %rdx

L30:
	cmpq	%r14, %rdx
	movq	%rsi, %rdx
	jae		L33
	movq	%rdx, %rsi
	subq	%r9, %rsi
	movl	(%r12,%rdx), %ebx
	movl	(%r12,%rsi), %esi
	cmpl	%esi, %ebx
	movl	$0x4, %edi
	je		L31
	xorl	%ebx, %esi
	bsfq	%rsi, %rdi
	shrq	$0x3, %rdi

L31:
	leaq	(%rdi,%rdx), %rsi
	cmpq	$0x4, %rdi
	je		L29
	jmp		L33

L32:
	movq	%r15, %r10

L33:
	movq	%r10, %rdi
	movq	-0x70(%rbp), %r15

L34:
	movq	%rdi, %rdx
	testq	%rax, %rax
	je		L35
	cmpq	%r13, %rdx
	jbe		L35
	leaq	-0x1(%rdx), %rdi
	movzbl	-0x1(%r12,%rax), %ebx
	decq	%rax
	movzbl	-0x1(%r12,%rdx), %ecx
	cmpl	%ebx, %ecx
	je		L34

L35:
	movq	%rsi, %rax
	subq	%rdx, %rax
	cmpq	$0x5ff, %r9
	seta	%cl
	movzbl	%cl, %ecx
	orq	$0x2, %rcx
	movq	%rax, %rdi
	subq	%rcx, %rdi
	cmpq	-0x48(%rbp), %rdi
	ja		L36
	cmpq	-0x48(%rbp), %rdi
	jne		L37
	leaq	0x1(%r11), %rcx
	cmpq	%rcx, %rsi
	jbe		L37

L36:
	movq	%rdi, -0x48(%rbp)
	movq	%r9, -0x60(%rbp)
	movq	%rax, -0x58(%rbp)
	movq	%rsi, %r11
	movq	%rdx, -0x40(%rbp)

L37:
	movq	%r11, -0x98(%rbp)
	pshufd	$0x3, %xmm1, %xmm1
	movd	%xmm1, %eax
	testl	%eax, %eax
	movl	$0x4, %edx
	je		L38
	movl	%eax, %eax
	bsfq	%rax, %rdx
	cmpq	$0x18, %rdx
	jb		L39
	shrq	$0x3, %rdx

L38:
	pshufd	$0x3, %xmm0, %xmm0
	movd	%xmm0, %eax
	movl	%eax, %eax
	movq	%r10, %r9
	subq	%rax, %r9
	cmpq	$0xffff, %r9
	jbe		L40

L39:
	movq	%r10, -0x38(%rbp)
	jmp		L49

L40:
	leaq	(%rdx,%r10), %rsi
	cmpq	$0x4, %rdx
	jne		L44
	leaq	0x4(%rdx,%r10), %rdx
	movq	%r10, -0x38(%rbp)
	jmp		L42

L41:
	leaq	0x4(%rdi,%rdx), %rdx

L42:
	cmpq	%r14, %rdx
	movq	%rsi, %rdx
	jae		L45
	movq	%rdx, %rsi
	subq	%r9, %rsi
	movl	(%r12,%rdx), %ebx
	movl	(%r12,%rsi), %esi
	cmpl	%esi, %ebx
	movl	$0x4, %edi
	je		L43
	xorl	%ebx, %esi
	bsfq	%rsi, %rdi
	shrq	$0x3, %rdi

L43:
	leaq	(%rdi,%rdx), %rsi
	cmpq	$0x4, %rdi
	je		L41
	jmp		L45

L44:
	movq	%r10, -0x38(%rbp)

L45:
	movq	-0x38(%rbp), %rdi

L46:
	movq	%rdi, %rdx
	testq	%rax, %rax
	je		L47
	cmpq	%r13, %rdx
	jbe		L47
	leaq	-0x1(%rdx), %rdi
	movzbl	-0x1(%r12,%rax), %ebx
	decq	%rax
	movzbl	-0x1(%r12,%rdx), %ecx
	cmpl	%ebx, %ecx
	je		L46

L47:
	movq	%rsi, %rax
	subq	%rdx, %rax
	cmpq	$0x5ff, %r9
	seta	%cl
	movzbl	%cl, %ecx
	orq	$0x2, %rcx
	movq	%rax, %rdi
	subq	%rcx, %rdi
	cmpq	-0x48(%rbp), %rdi
	ja		L48
	cmpq	-0x48(%rbp), %rdi
	jne		L49
	movq	-0x98(%rbp), %rcx
	leaq	0x1(%rcx), %rcx
	cmpq	%rcx, %rsi
	jbe		L49

L48:
	movq	%rdi, -0x48(%rbp)
	movq	%r9, -0x60(%rbp)
	movq	%rax, -0x58(%rbp)
	movq	%rsi, -0x98(%rbp)
	movq	%rdx, -0x40(%rbp)

L49:
	movq	%r14, %r11
	movq	-0x50(%rbp), %rbx
	testq	%rbx, %rbx
	je		L51
	movq	-0x38(%rbp), %rcx
	movq	%rcx, %r14
	subq	%rbx, %r14
	movl	(%r12,%r14), %edx
	movl	-0x84(%rbp), %esi
	cmpl	%edx, %esi
	movl	$0x4, %eax
	movq	-0x58(%rbp), %r10
	je		L50
	xorl	%esi, %edx
	bsfq	%rdx, %rax
	cmpl	$0x18, %eax
	jb		L59
	shrq	$0x3, %rax

L50:
	cmpq	$0xffff, %rbx
	ja		L59
	leaq	(%rax,%rcx), %rsi
	cmpq	$0x4, %rax
	jne		L55
	leaq	0x4(%rax,%rcx), %rax
	jmp		L53

L51:
	movq	-0x58(%rbp), %r10
	jmp		L59

L52:
	leaq	0x4(%rdx,%rax), %rax

L53:
	cmpq	%r11, %rax
	movq	%rsi, %rax
	jae		L55
	movq	%rax, %rcx
	subq	%rbx, %rcx
	movl	(%r12,%rax), %edi
	movl	(%r12,%rcx), %esi
	cmpl	%esi, %edi
	movl	$0x4, %edx
	je		L54
	xorl	%edi, %esi
	bsfq	%rsi, %rdx
	shrq	$0x3, %rdx

L54:
	leaq	(%rdx,%rax), %rsi
	cmpq	$0x4, %rdx
	je		L52

L55:
    movq	-0xe0(%rbp), %rax
    movq	-0x38(%rbp), %rcx
    leaq	(%rax,%rcx), %r9
    leaq	(%rax,%r14), %rbx
    xorl	%ecx, %ecx

L56:
	movq	%rcx, %rdx
	movq	-0x38(%rbp), %rax
	leaq	(%rax,%rdx), %rax
	movq	%r14, %rcx
	addq	%rdx, %rcx
	je		L57
	cmpq	%r13, %rax
	jbe		L57
	movzbl	(%rbx,%rdx), %edi
	movzbl	(%r9,%rdx), %r15d
	leaq	-0x1(%rdx), %rcx
	cmpl	%edi, %r15d
	je		L56

L57:
	movq	-0x90(%rbp), %rcx
	leaq	(%rcx,%rsi), %rcx
	subq	%rdx, %rcx
	leaq	-0x1(%rcx), %r14
	cmpq	-0x48(%rbp), %r14
	movq	-0x70(%rbp), %r15
	movq	-0x50(%rbp), %rbx
	movq	-0x58(%rbp), %rdi
	ja		L58
	movq	%rdi, %r9
	movq	-0x48(%rbp), %rdi
	leaq	0x1(%rdi), %rdi
	subq	%rsi, %rdi
	addq	-0x38(%rbp), %rdi
	addq	%rdx, %rdi
	jne 	L77
	movq	-0x98(%rbp), %rdx
	leaq	0x1(%rdx), %rdx
	cmpq	%rdx, %rsi
	movq	%r9, %r10
	jbe		L59

L58:
	movq	%r14, -0x48(%rbp)
	movq	%rbx, %rdx
	movq	%rdx, -0x60(%rbp)
	movq	%rcx, %r10
	movq	%rsi, -0x98(%rbp)
	movq	%rax, -0x40(%rbp)

L59:
	testq	%r10, %r10
	je	L67
	testq	%r15, %r15
	movq	-0x38(%rbp), %rsi
	movq	-0xa0(%rbp), %rax
	movq	-0x80(%rbp), %rcx
	je		L68
	movq	-0x40(%rbp), %rdx
	cmpq	%rdx, %rax
	movq	-0xc8(%rbp), %r11
	movq	-0x98(%rbp), %rbx
	jbe		L69
	movq	-0xa8(%rbp), %rsi
	cmpq	%rsi, -0x48(%rbp)
	cmovaq	-0x60(%rbp), %rcx
	movq	%rcx, -0x80(%rbp)
	cmovaq	%r10, %r15
	cmovaq	%rbx, %rax
	movq	%rax, %r10
	cmovaq	%rdx, %r8
	leaq	(%r12,%r13), %rsi
	subq	%r13, %r8
	cmpq	$0x10, %r8
	movq	-0xc0(%rbp), %r9
	movq	-0x78(%rbp), %r13
	jb		L63

L60:
	cmpq	$0x10f, %r8
	movl	$0x10f, %eax
	cmovbq	%r8, %rax
	leaq	0xa(%rax,%r13), %rcx
	cmpq	%r11, %rcx
	jae		L90
	movq	%rax, %rcx
	shlq	$0x8, %rcx
	addl	$0xf0e0, %ecx
	movw	%cx, (%r13)
	testq	%rax, %rax
	je		L62
	leaq	0x2(%r13), %rcx
	xorl	%edx, %edx

L61:
	movq	(%rsi,%rdx), %rdi
	movq	%rdi, -0x30(%rbp)
	movq	%rdi, (%rcx,%rdx)
	addq	$0x8, %rdx
	cmpq	%rax, %rdx
	jb		L61

L62:
	subq	%rax, %r8
	leaq	0x2(%rax,%r13), %r13
	addq	%rax, %rsi
	cmpq	$0xf, %r8
	ja		L60

L63:
	cmpq	$0x4, %r8
	jb		L66
	leaq	0xa(%r8,%r13), %rax
	cmpq	%r11, %rax
	movq	%r11, %rbx
	jae		L92
	leal	0xe0(%r8), %eax
	movb	%al, (%r13)
	testq	%r8, %r8
	je		L65
	leaq	0x1(%r13), %rax
	xorl	%ecx, %ecx

L64:
	movq	(%rsi,%rcx), %rdx
	movq	%rdx, -0x30(%rbp)
	movq	%rdx, (%rax,%rcx)
	addq	$0x8, %rcx
	cmpq	%r8, %rcx
	jb		L64

L65:
	leaq	0x1(%r8,%r13), %r13
	addq	%r8, %rsi
	xorl	%r8d, %r8d

L66:
	leaq	(%r8,%r8), %rax
	movl	$0xa, %edi
	subq	%rax, %rdi
	cmpq	%r15, %rdi
	cmovaeq	%r15, %rdi
	leaq	0x8(%r13), %rax
	cmpq	%r11, %rax
	movq	%r11, %rbx
	jae		L92
	movq	%r15, %rcx
	subq	%rdi, %rcx
	leaq	-0x3(%rdi), %rax
	movl	(%rsi), %ebx
	movq	-0x80(%rbp), %rsi
	cmpq	-0x50(%rbp), %rsi
	jne		L78
	testq	%r8, %r8
	je		L82
	movq	%r8, %rdx
	shlq	$0x6, %rdx
	leaq	0x6(%rdx,%rax,8), %rdi
	jmp		L83

L67:
	movq	-0x80(%rbp), %rax
	movq	%r15, %r10
	movq	%rax, %r15
	movq	-0xa0(%rbp), %rax
	movq	%r8, -0x40(%rbp)
	movq	-0xa8(%rbp), %rdx
	movq	%rbx, %rdi
	movq	%r11, %rcx
	movq	%rax, %rbx
	movq	-0xc8(%rbp), %r11
	movq	-0xc0(%rbp), %r9
	movq	-0x38(%rbp), %rsi
	jmp		L101

L68:
	movq	%rbx, %rdi
	movq	-0xc8(%rbp), %r11
	movq	-0xc0(%rbp), %r9
	movq	-0x48(%rbp), %rdx
	movq	-0x60(%rbp), %r15
	movq	-0x98(%rbp), %rbx
	jmp		L100

L69:
	movq	%r10, -0x58(%rbp)
	leaq	(%r12,%r13), %rsi
	subq	%r13, %r8
	cmpq	$0x10, %r8
	movq	-0xc0(%rbp), %r9
	movq	-0x78(%rbp), %r13
	jb		L73

L70:
	cmpq	$0x10f, %r8
	movl	$0x10f, %eax
	cmovbq	%r8, %rax
	leaq	0xa(%rax,%r13), %rcx
	cmpq	%r11, %rcx
	jae		L97
	movq	%rax, %rcx
	shlq	$0x8, %rcx
	addl	$0xf0e0, %ecx
	movw	%cx, (%r13)
	testq	%rax, %rax
	je		L72
	leaq	0x2(%r13), %rcx
	xorl	%edx, %edx

L71:
	movq	(%rsi,%rdx), %rdi
	movq	%rdi, -0x30(%rbp)
	movq	%rdi, (%rcx,%rdx)
	addq	$0x8, %rdx
	cmpq	%rax, %rdx
	jb		L71

L72:
	subq	%rax, %r8
	leaq	0x2(%rax,%r13), %r13
	addq	%rax, %rsi
	cmpq	$0xf, %r8
	ja		L70

L73:
	cmpq	$0x4, %r8
	jb		L76
	leaq	0xa(%r8,%r13), %rax
	cmpq	%r11, %rax
	movq	%r11, %rdx
	jae		L99
	leal	0xe0(%r8), %eax
	movb	%al, (%r13)
	testq	%r8, %r8
	je		L75
	leaq	0x1(%r13), %rax
	xorl	%ecx, %ecx

L74:
	movq	(%rsi,%rcx), %rdx
	movq	%rdx, -0x30(%rbp)
	movq	%rdx, (%rax,%rcx)
	addq	$0x8, %rcx
	cmpq	%r8, %rcx
	jb		L74

L75:
	leaq	0x1(%r8,%r13), %r13
	addq	%r8, %rsi
	xorl	%r8d, %r8d

L76:
	leaq	(%r8,%r8), %rcx
	movl	$0xa, %eax
	subq	%rcx, %rax
	cmpq	%r15, %rax
	cmovaeq	%r15, %rax
	movq	%r15, %rdi
	leaq	0x8(%r13), %rcx
	cmpq	%r11, %rcx
	movq	%r11, %rdx
	jae		L99
	movq	%rdi, %rcx
	subq	%rax, %rcx
	leaq	-0x3(%rax), %rdx
	movl	(%rsi), %r15d
	movq	-0x80(%rbp), %rsi
	cmpq	-0x50(%rbp), %rsi
	jne		L79
	testq	%r8, %r8
	je		L84
	movq	%r8, %rax
	shlq	$0x6, %rax
	leaq	0x6(%rax,%rdx,8), %rax
	jmp		L85

L77:
	movq	%r9, %r10
	jmp		L59

L78:
	cmpq	$0x5ff, %rsi
	ja		L80
	movq	%r8, %rdx
	shlq	$0x6, %rdx
	movl	%esi, %edi
	shrl	$0x8, %edi
	addl	%edi, %edx
	shlq	$0x3, %rax
	addl	%edx, %eax
	movb	%al, (%r13)
	movb	%sil, 0x1(%r13)
	movl	%ebx, 0x2(%r13)
	leaq	0x2(%r8,%r13), %rax
	jmp     L87

L79:
	cmpq	$0x5ff, %rsi
	ja      L81
	movq	%r8, %rax
	shlq	$0x6, %rax
	movl	%esi, %edi
	shrl	$0x8, %edi
	addl	%edi, %eax
	shlq	$0x3, %rdx
	addl	%eax, %edx
	movb	%dl, (%r13)
	movb	%sil, 0x1(%r13)
	movl	%r15d, 0x2(%r13)
	leaq	0x2(%r8,%r13), %rax
	jmp		L94

L80:
	cmpq	$0x3fff, %rsi
	movq	%r15, %rdx
	ja		L86
	cmpq	%rdi, %rdx
	je		L86
	cmpq	$0x23, %rdx
	jae		L86
	addl	$-0x3, %edx
	movl	%edx, %eax
	shrl	$0x2, %eax
	leaq	(,%r8,8), %rcx
	leal	0xa0(%rax,%rcx), %eax
	movb	%al, (%r13)
	movq	-0x80(%rbp), %rax
	leaq	(,%rax,4), %rax
	andl	$0x3, %edx
	orl		%edx, %eax
	movw	%ax, 0x1(%r13)
	movl	%ebx, 0x3(%r13)
	leaq	0x3(%r8,%r13), %rbx
	jmp		L92

L81:
	cmpq	$0x3fff, %rsi
	ja		L93
	cmpq	%rax, %rdi
	je		L93
	cmpq	$0x23, %rdi
	jae		L93
	addl	$-0x3, %edi
	movl	%edi, %eax
	shrl	$0x2, %eax
	leaq	(,%r8,8), %rcx
	leal	0xa0(%rax,%rcx), %eax
	movb	%al, (%r13)
	movq	-0x80(%rbp), %rax
	leaq	(,%rax,4), %rax
	andl	$0x3, %edi
	orl		%edi, %eax
	movw	%ax, 0x1(%r13)
	movl	%r15d, 0x3(%r13)
	leaq	0x3(%r8,%r13), %rdx
	jmp		L99

L82:
	addq	$0xf0, %rdi

L83:
	movb	%dil, (%r13)
	movl	%ebx, 0x1(%r13)
	leaq	0x1(%r8,%r13), %rax
	jmp		L87

L84:
	addq	$0xf0, %rax

L85:
	movb	%al, (%r13)
	movl	%r15d, 0x1(%r13)
	leaq	0x1(%r8,%r13), %rax
	jmp		L94

L86:
	movq	%r8, %rdx
	shlq	$0x6, %rdx
	shlq	$0x3, %rax
	leal	0x7(%rax,%rdx), %eax
	movb	%al, (%r13)
	movq	-0x80(%rbp), %rax
	movw	%ax, 0x1(%r13)
	movl	%ebx, 0x3(%r13)
	leaq	0x3(%r8,%r13), %rax

L87:
	cmpq	$0x10, %rcx
	jb		L89

L88:
	leaq	0x2(%rax), %rdx
	cmpq	%r11, %rdx
	jae		L90
	cmpq	$0x10f, %rcx
	movl	$0x10f, %esi
	cmovbq	%rcx, %rsi
	subq	%rsi, %rcx
	shlq	$0x8, %rsi
	addl	$0xf0f0, %esi
	movw	%si, (%rax)
	cmpq	$0xf, %rcx
	movq	%rdx, %rax
	ja		L88

L89:
	testq	%rcx, %rcx
	je		L91
	leaq	0x1(%rax), %rsi
	cmpq	%r11, %rsi
	movq	%r11, %rbx
	jae		L92
	addl	$0xf0, %ecx
	movb	%cl, (%rax)
	movq	%rsi, %rbx
	jmp		L92

L90:
	movq	%r11, %rbx
	jmp	L92

L91:
	movq	%rax, %rbx

L92:
	cmpq	%r11, %rbx
	movq	-0xd0(%rbp), %rax
	cmovbq	%rbx, %rax
	movq	%rax, -0xd0(%rbp)
	movq	-0xb8(%rbp), %rax
	movq	%r10, %r13
	cmovbq	%r13, %rax
	movq	%rax, -0xb8(%rbp)
	xorl	%r15d, %r15d
	xorl	%r10d, %r10d
	xorl	%eax, %eax
	movq	%rax, -0x40(%rbp)
	xorl	%edx, %edx
	movq	%rbx, -0x78(%rbp)
	xorl	%ebx, %ebx
	movq	-0x38(%rbp), %rsi
	movq	-0x80(%rbp), %rcx
	movq	%rcx, %rdi
	jmp		L100

L93:
	movq	%r8, %rax
	shlq	$0x6, %rax
	shlq	$0x3, %rdx
	leal	0x7(%rdx,%rax), %eax
	movb	%al, (%r13)
	movq	-0x80(%rbp), %rax
	movw	%ax, 0x1(%r13)
	movl	%r15d, 0x3(%r13)
	leaq	0x3(%r8,%r13), %rax

L94:
	cmpq	$0x10, %rcx
	jb		L96

L95:
	leaq	0x2(%rax), %rdx
	cmpq	%r11, %rdx
	jae		L97
	cmpq	$0x10f, %rcx
	movl	$0x10f, %esi
	cmovbq	%rcx, %rsi
	subq	%rsi, %rcx
	shlq	$0x8, %rsi
	addl	$0xf0f0, %esi
	movw	%si, (%rax)
	cmpq	$0xf, %rcx
	movq	%rdx, %rax
	ja		L95

L96:
	testq	%rcx, %rcx
	je		L98
	leaq	0x1(%rax), %rsi
	cmpq	%r11, %rsi
	movq	%r11, %rdx
	jae		L99
	addl	$0xf0, %ecx
	movb	%cl, (%rax)
	movq	%rsi, %rdx
    jmp		L99

L97:
	movq	%r11, %rdx
    jmp		L99

L98:
	movq	%rax, %rdx

L99:
	cmpq	%r11, %rdx
	movq	-0xd0(%rbp), %rax
	cmovbq	%rdx, %rax
	movq	%rax, -0xd0(%rbp)
	movq	-0xb8(%rbp), %rax
	movq	-0xa0(%rbp), %r13
	cmovbq	%r13, %rax
	movq	%rax, -0xb8(%rbp)
	movq	%rdx, -0x78(%rbp)
	movq	-0x38(%rbp), %rsi
	movq	-0x80(%rbp), %rcx
	movq	%rcx, %rdi
	movq	-0x58(%rbp), %r10
	movq	-0x48(%rbp), %rdx
	movq	-0x60(%rbp), %r15

L100:
	movq	-0x68(%rbp), %rcx

L101:
	leaq	0x9(%rsi), %rax
	cmpq	%rcx, %rax
	jae		L102
	cmpq	%r11, -0x78(%rbp)
	jb		L2

L102:
	movq	-0xb8(%rbp), %rax
	movq	-0xd0(%rbp), %r8
	movq	-0xd8(%rbp), %rdi
	jmp		L105

L103:
	xorl	%ebx, %ebx
	jmp		L114

L104:
	movq	%rdi, %r8

L105:
	movq	%rdi, -0xd8(%rbp)
	cmpq	%rax, %rcx
	jbe		L111
	cmpq	%r11, %r8
	jae		L111
	movq	%rax, %rdx
	movq	%r8, %rbx

L106:
	movq	%rbx, -0x40(%rbp)
	movq	%rdx, -0x38(%rbp)
	movq	%rax, -0xb8(%rbp)
	movq	%rcx, %rdx
	subq	%rax, %rdx
	cmpq	$0x10f, %rdx
	movl	$0x10f, %ecx
	cmovaq	%rcx, %rdx
	movq	%rdx, -0x48(%rbp)
	leaq	(%r12,%rax), %r15
	cmpq	$0x10, %rdx
	movq	%rdx, %r14
	jb		L109

L107:
	cmpq	$0x10f, %r14
	movl	$0x10f, %r13d
	cmovbq	%r14, %r13
	leaq	0xa(%r13,%r8), %rax
	cmpq	%r11, %rax
	jae		L112
	movq	%r13, %rax
	shlq	$0x8, %rax
	addl	$0xf0e0, %eax
	movw	%ax, (%r8)
	subq	%r13, %r14
	testq	%r13, %r13
	je		L108
	leaq	0x2(%r8), %rdi
	movq	%r15, %rsi
	movq	%r13, %rdx
	movq	%r11, %rbx
	movq	%r8, %r12
	callq	_memcpy
	movq	%r12, %r8
	movq	-0xb0(%rbp), %r12
	movq	%rbx, %r11

L108:
	leaq	0x2(%r13,%r8), %r8
	addq	%r13, %r15
	cmpq	$0xf, %r14
	ja		L107

L109:
	testq	%r14, %r14
	je		L110
	leaq	0xa(%r14,%r8), %rax
	cmpq	%r11, %rax
	jae		L112
	leal	0xe0(%r14), %eax
	leaq	0x1(%r8), %rdi
	movb	%al, (%r8)
	movq	%r15, %rsi
	movq	%r14, %rdx
	movq	%r11, %r15
	movq	%r8, %rbx
	callq	_memcpy
	movq	%rbx, %r8
	movq	%r15, %r11
	leaq	0x1(%r14,%r8), %r8

L110:
	movq	-0xb8(%rbp), %rax
	addq	-0x48(%rbp), %rax
	cmpq	%r11, %r8
	movq	-0x40(%rbp), %rbx
	cmovbq	%r8, %rbx
	movq	-0x38(%rbp), %rdx
	cmovbq	%rax, %rdx
	movq	-0x68(%rbp), %rcx
	cmpq	%rax, %rcx
	jbe		L113
	cmpq	%r11, %r8
	jb		L106
	jmp		L113

L111:
	movq	%rax, %rdx
	movq	%r8, %rbx
	jmp		L113

L112:
	movq	-0x38(%rbp), %rdx
	movq	-0x40(%rbp), %rbx

L113:
	movq	$0x6, -0x30(%rbp)
	movq	$0x6, (%rbx)
	addq	$0x8, %rbx
	subq	-0xd8(%rbp), %rbx

L114:
	movq	-0xe8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	%rbx, %rax
	addq	$0xc8, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq

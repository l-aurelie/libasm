; RETURN | 1st param | 2d param | 3d param | 4th param | 5th param | 6th param
; RAX    | RDI       | RSI      | RDX      | RCX       | R8        | R9
					 
					 ; char *strdup(char *s(RDI))
					 ; pointeur sur la chaîne dupliquée, ou NULL si erreur
bits 64

	global ft_strdup
	extern malloc
	extern __errno_location
	extern ft_strlen
	extern ft_strcpy

section .text
ft_strdup:
	call ft_strlen
	push rdi
	add rax, 1
	mov rdi, rax
	call malloc wrt ..plt
	cmp rax, 0
	jz return
	mov rdi, rax
	pop rsi
	call ft_strcpy
return:
	ret




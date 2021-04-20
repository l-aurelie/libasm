; RETURN | 1st param | 2d param | 3d param | 4th param | 5th param | 6th param
; RAX    | RDI       | RSI      | RDX      | RCX       | R8        | R9
					 
					 ; ft_strcmp(char *str1(RDI), char *str2(RSI))
					 ; return (rax) 0 si ==, int positif ou neg si !=
bits 64

	global ft_strcmp

section .text
ft_strcmp:
	xor rcx, rcx			; rcx = 0 , index
	push rbx				; registre a preserver
cmp:	
	mov al, byte [rdi + rcx]; oblige de passer par un registre intermediaire
	cmp al, 0				; s1[i] == \0? 
	jz return
	cmp byte [rsi + rcx], 0 ; s2[i] == \0?
	jz return
	cmp al, byte [rsi + rcx]; cmp s1[i] s2[i]
	jne return				; non equal jump return
	inc rcx					; passe au char suivant
	jmp cmp					; retourne debut de cmp
return:
	movzx rax, al				; mov valeur plus petite avec extension a 0
	movzx rbx, byte [rsi + rcx]
	sub rax, rbx				; rax -= rdx, la difference est placee dans rax
	pop rbx
	ret							; la fonction return la diff

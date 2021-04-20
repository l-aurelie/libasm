; RETURN | 1st param | 2d param | 3d param | 4th param | 5th param | 6th param
; RAX    | RDI       | RSI      | RDX      | RCX       | R8        | R9
					 
					 ; ft_strcpy(char *dest(RDI), char *src(RSI))
					 ; return copie src dans dest(rax)
bits 64

	global ft_strcpy

section .text
ft_strcpy:
	xor rcx, rcx			; rcx = 0 , index
copy:	
	mov al, byte [rsi + rcx]; copier le contenu de src dans dest, al (rax)1octet
	mov byte [rdi + rcx], al; on ne peut copier l'un dans lautre-> registre intermediaire
	cmp byte [rsi + rcx], 0	; src[i] == \0?
	jz return				; on jump a return si flag zero = 1
	inc rcx					; rcx ++
	jmp copy				; on retourne au debut de copy
return:
mov rax, rdi				; on place dest dans rax pour return
ret							; la fonction return rax soit l'index

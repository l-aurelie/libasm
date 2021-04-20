; RETURN | 1st param | 2d param | 3d param | 4th param | 5th param | 6th param
; RAX    | RDI       | RSI      | RDX      | RCX       | R8        | R9
					 
					 ; char *strdup(char *str(RDI))
					 ; pointeur sur la chaîne dupliquée, ou NULL si erreur
bits 64

	global ft_strdup
	extern malloc
	extern __errno_location
	extern ft_strlen
	extern ft_strcpy

section .text
ft_strdup:
	call ft_strlen	; strlen sera appelle avec rdi en param (soit str)
	push rdi		; on push rdi pour conserver car on doit l'utiliser
	add rax, 1		; on incremente de 1 pour le \0
	mov rdi, rax	; on place la taille a malloc dans rdi pour lenvoyer a malloc
	call malloc wrt ..plt
	cmp rax, 0		; on regarde si la chaine allouee est nulle
	jz return		; si ou on return Null
	mov rdi, rax	; on place le pointeur alloue dans rdi (dest de strcpy)
	pop rsi			; on a push str (push rdi), on la pop dans rsi (src de srtrcpy)
	call ft_strcpy	; on appelle strcpy avec les arguments prepares avant
return:
	ret




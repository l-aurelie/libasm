; RETURN | 1st param | 2d param | 3d param | 4th param | 5th param | 6th param
; RAX    | RDI       | RSI      | RDX      | RCX       | R8        | R9
					 
			;read(int fd(RDI), void *buf(RSI), int count(RDX))
			;return (rax) le nb de char lu, -1 si erreur(+errno set)
bits 64

	global ft_read
	extern __errno_location

section .text
ft_read:
	xor rax, rax   ; 0 code de read, a placer dans rax pour l'appel system
	syscall        ; appelle read
	cmp rax, 0
	jl error       ; si return < 0 go gestion d'erreurs
	ret 		   ; sinon return rax qui contient le retour du syscall
error:
	neg rax	       ; en cas d'erreur contient le errno mais negatif
	mov rdi, rax   ; passer le num d'erreur a rdi pour le passer en 1parametre
	call __errno_location wrt ..plt ;renvoie l'addresse de errno
	mov [rax], rdi ; placer le num d'erreur a addresse errno(contenue dans rax)
	mov rax, -1    ; remettre rax a -1 pour le renvoyer retour d'erreur read
	ret


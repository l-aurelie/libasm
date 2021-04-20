; RETURN | 1st param | 2d param | 3d param | 4th param | 5th param | 6th param
; RAX    | RDI       | RSI      | RDX      | RCX       | R8        | R9
					 
					 ; ft_strlen(char *str)
					 ; RDI contient str

bits 64				 ; indiquer que prevu pour architecture 64bits

	global ft_strlen ; pour pouvoir appeler dans d'autres fichiers avec extern

; section .data pour les donnees initialisees : pas besoin ici
; section .bss pour variables allouees non initialisees : idem

section .text				; segment contenant les instructions
ft_strlen:
	xor rax, rax			; rax = 0 (index et resultat)
count:	
	cmp byte [rdi + rax], 0	; byte pour comparer juste 1octet(char)
							; [] pour dereferencer
							; [la variable rdi + index] \0 ? si oui ZF = 1
	jz return				; on jump a return si flag zero = 1
	inc rax					; rax ++
	jmp count				; on jump au debut de count
return:
ret							; la fonction return rax soit l'index



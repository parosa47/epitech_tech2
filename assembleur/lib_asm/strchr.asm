;
; EPITECH PROJECT, 2022
; assembleur
; File description:
; strchr.asm
;
BITS 64
global strchr
section .text
strchr:
    xor rax,rax
    search_loop:
        cmp byte [rdi], 0 ; test si fin de chaîne
            je end_search ; si oui, sortir de la boucle
        cmp sil, byte [rdi] ; test si le caractère est trouvé
            je is_finded ; si oui, sortir de la boucle
            jne next_char ; si non, passer à l'adresse suivante
    next_char:
        inc rdi ; passer à l'adresse suivante
        jmp search_loop ; boucle
    is_finded:
        mov rax, rdi ; copier l'adresse à retourner sur la pile
        ret ; retourner
    end_search:
        ret ; retourner

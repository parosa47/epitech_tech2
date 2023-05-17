;
; EPITECH PROJECT, 2022
; assembleur
; File description:
; strncmp.asm
;

BITS 64
global strchr
section .text
strcmp:
    xor rax,rax
search_loop:
    mov cl, byte [rdi]
    cmp byte [rdi], cl
    jne not_equal
    cmp byte [rdi], 0
    je equal
    inc rdi
    inc rsi
    jmp search_loop
equal:
    mov rax, 0
    ret
not_equal:
    mov rax, rdi
    ret
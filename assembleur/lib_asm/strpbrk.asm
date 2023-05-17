;
; EPITECH PROJECT, 2022
; assembleur
; File description:
; strpbrk.asm
;

section .text
global strpbrk
strpbrk:
    xor rcx, rcx
    jmp endl
endl:
    ret
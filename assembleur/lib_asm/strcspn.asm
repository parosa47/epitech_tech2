;
; EPITECH PROJECT, 2022
; assembleur
; File description:
; strcspn.asm
;

section .text
global strncmp
strncmp:
    xor rcx, rcx
    jmp endl
endl:
    ret
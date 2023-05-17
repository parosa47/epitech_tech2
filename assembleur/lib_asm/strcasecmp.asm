;
; EPITECH PROJECT, 2022
; assembleur
; File description:
; strcasecmp.asm
;

section .text
global strcasecmp
strcasecmp:
    xor rcx, rcx
    jmp endl
endl:
    ret
;
; EPITECH PROJECT, 2022
; assembleur
; File description:
; ffs.asm
;

section .text
global ffs
ffs:
    xor rcx, rcx
    jmp endl
endl:
    ret
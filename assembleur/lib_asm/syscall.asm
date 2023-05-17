;
; EPITECH PROJECT, 2022
; assembleur
; File description:
; syscall.asm
;

section .text
global syscall
syscall:
    xor rcx, rcx
    jmp endl
endl:
    ret
/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** error.c
*/

#include "include.h"

int error_handling(int argc, char **argv)
{
    if (argc != 5)
        return 84;
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    int d = atoi(argv[4]);
    if (a <= 0 || b <= 0 || c <= 0 || d <= 0){
        fprintf(stderr, "Values must be >0.\n");
        return 84;
    }
    return 0;
}

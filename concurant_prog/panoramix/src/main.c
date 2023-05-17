/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** main.c
*/

#include "include.h"

int main(int argc, char **argv)
{
    if (error_handling(argc, argv) == 84)
        return 84;
    panoramix(argv);
    return 0;
}

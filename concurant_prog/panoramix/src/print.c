/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** print.c
*/

#include "include.h"

void print_villager_sleep(int id)
{
    printf("Villager %d: I'm going to sleep now.\n", id);
}

void print_villager_start(int id)
{
    printf("Villager %d: Going into battle!\n", id);
}

void print_druid_out(void)
{
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
}

void print_druid_start(void)
{
    printf("Druid: I'm ready... but sleepy...\n");
}

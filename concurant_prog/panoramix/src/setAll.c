/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** setAll.c
*/

#include "include.h"

void setArgs(char **argv, args_t *args)
{
    args->nb_fights = atoi(argv[3]);
    args->nb_refills = atoi(argv[4]);
    args->nb_villagers = atoi(argv[1]);
    args->pot_size = atoi(argv[2]);
    args->soup_last = args->pot_size;
}

void set_pano(args_t *args, pano_t *pano, mutex_t *mutex, sema_t *sem)
{
    druid_t *druid = malloc(sizeof(druid_t));
    druid->nb_refills_last = args->nb_refills;
    for (int i = 0; i < args->nb_villagers; i++) {
        pano[i].args = args;
        pano[i].villager = malloc(sizeof(villager_t));
        pano[i].villager->id = i;
        pano[i].villager->nb_fights = args->nb_fights;
        pano[i].druid = druid;
        pano[i].mutex = mutex;
        pano[i].sem = sem;
    }
}

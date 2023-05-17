/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** panoramix.c
*/

#include "include.h"

int panoramix(char **argv)
{
    args_t *args = malloc(sizeof(args_t));
    setArgs(argv, args);
    pano_t *pano = malloc(sizeof(pano_t) * args->nb_villagers);
    mutex_t *mutex = malloc(sizeof(mutex_t));
    pthread_mutex_init(&mutex->druid_mutex, NULL);
    pthread_mutex_init(&mutex->vilager_mutex, NULL);
    sema_t *sem = malloc(sizeof(sema_t));
    sem_init(&sem->druid_sem, 0, 0);
    sem_init(&sem->villager_sem, 0, 0);
    set_pano(args, pano, mutex, sem);
    fight(pano);
    return 0;
}

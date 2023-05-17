/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** villager.c
*/

#include "include.h"

void *villager_thread(void *arg)
{
    pano_t *pano = (pano_t *)arg;
    print_villager_start(pano->villager->id);
    while (pano->villager->nb_fights > 0) {
        pthread_mutex_lock(&pano->mutex->vilager_mutex);
        drink_potion(pano);
        pthread_mutex_unlock(&pano->mutex->vilager_mutex);
    }
    print_villager_sleep(pano->villager->id);
    for (int i = 0; i < pano->args->nb_villagers; i++) {
        if (pano->villager[i].nb_fights > 0)
            return NULL;
    }
    sem_post(&pano->sem->druid_sem);
    return NULL;
}

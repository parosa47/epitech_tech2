/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** druid.c
*/

#include "include.h"

void *druid_function(void *arg)
{
    pano_t *pano = (pano_t *)arg;
    int nb = 0;
    for (int i = 0; i < pano->args->nb_villagers; i++) {
        if (pano->villager[i].nb_fights > 0)
            nb++;
    }
    if (nb == 0)
        return NULL;
    print_druid_start();
    while (pano->druid->nb_refills_last > 0) {
        sem_wait(&pano->sem->druid_sem);
        pthread_mutex_lock(&pano->mutex->druid_mutex);
        refill_pot(pano);
        pthread_mutex_unlock(&pano->mutex->druid_mutex);
        sem_post(&pano->sem->villager_sem);
    }
    print_druid_out();
    return NULL;
}

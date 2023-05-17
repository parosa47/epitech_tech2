/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** actions.c
*/

#include "include.h"

void drink_potion(pano_t *pano)
{
    printf("Villager %d: I need a drink... ", pano->villager->id);
    printf("I see %d servings left.\n", pano->args->soup_last);
    if (pano->args->soup_last <= 0) {
        printf("Villager %d: Hey Pano wake up! We need more potion.\n",
        pano->villager->id);
        sem_post(&pano->sem->druid_sem);
        sem_wait(&pano->sem->villager_sem);
    }
    pano->args->soup_last--;
    pano->villager->nb_fights--;
    printf("Villager %d: Take that ", pano->villager->id);
    printf("roman scum! Only %d left.\n", pano->villager->nb_fights);
}

void refill_pot(pano_t *pano)
{
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware");
    printf(" I can only make %i more refills after this one.\n",
    pano->druid->nb_refills_last - 1);
    pano->args->soup_last = pano->args->pot_size;
    pano->druid->nb_refills_last -= 1;
}

void fight(pano_t *pano)
{
    pthread_t *villagers_threads = malloc(sizeof(pthread_t)
    * pano->args->nb_villagers);
    pthread_t druid_thread;

    pthread_create(&druid_thread, NULL, &druid_function, &pano[0]);
    for (int i = 0; i < pano->args->nb_villagers; i++) {
        pthread_create(&villagers_threads[i], NULL, &villager_thread, &pano[i]);
    }
    for (int i = 0; i < pano->args->nb_villagers; i++) {
        pthread_join(villagers_threads[i], NULL);
    }
    pthread_join(druid_thread, NULL);
}

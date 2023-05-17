/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** struct.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include "include.h"

typedef struct args_s {
    int nb_villagers;
    int pot_size;
    int nb_fights;
    int nb_refills;
    int soup_last;
} args_t;

typedef struct villager_s {
    int id;
    int nb_fights;
} villager_t;

typedef struct druid_s {
    int nb_refills_last;
} druid_t;

typedef struct mutex_s {
    pthread_mutex_t vilager_mutex;
    pthread_mutex_t druid_mutex;
} mutex_t;

typedef struct semaphore_s {
    sem_t villager_sem;
    sem_t druid_sem;
} sema_t;

typedef struct pano_s {
    args_t *args;
    villager_t *villager;
    druid_t *druid;
    mutex_t *mutex;
    sema_t *sem;
} pano_t;

#endif /* !STRUCT_H_ */

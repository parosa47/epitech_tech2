/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** include.h
*/

#ifndef INCLUDE_H_
    #define INCLUDE_H_

    #include <pthread.h>
    #include <semaphore.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <fcntl.h>
    #include "struct.h"

int error_handling(int argc, char **argv);
void *druid_function(void *arg);
void *villager_thread(void *arg);
void setArgs(char **argv, args_t *args);
void fight(pano_t *pano);
void drink_potion(pano_t *pano);
void refill_pot(pano_t *pano);
void print_villager_start(int id);
void print_villager_sleep(int id);
void print_druid_start(void);
void print_druid_out(void);
void *villager_thread(void *arg);
void set_pano(args_t *args, pano_t *pano, mutex_t *mutex, sema_t *sem);
int panoramix(char **argv);

#endif /* !INCLUDE_H_ */

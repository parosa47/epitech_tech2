/*
** EPITECH PROJECT, 2023
** assembleur
** File description:
** main.c
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "Hello World!";
    char str4[] = "Hello World!";
    char str2[] = "HelloaWorld!";
    char str3[] = "oaW";
    int len = strlen(str1);
    char* pos = strchr(str1, 'o');
    char* pos2 = strchr(str1, 'W');
    int a = strcmp(str2, str1);
    int c = strcmp(str1, str4);
    char *strst = strstr(str2, str3);
    int b = strncmp(str2, str1, 5);

    //strlen
    printf("strlen:\nThe length of the string '%s' is %d\n\n", str1, len);
    //strchr
    printf("strchr:\nThe first occurrence of the character 'o' in the string '%s' is at position %p : %d\n", str1, pos, pos - str1);
    printf("The first occurrence of the character 'W' in the string '%s' is at position %p : %d\n\n", str1, pos, pos2 - str1);
    //strcmp
    printf("strcmp:\nLa comparaison entre la string %s et %s = %d\n", str1, str2, a);
    printf("La comparaison entre la string %s et %s = %d\n\n", str1, str4, c);
    //strstr
    printf ("strstr:\nLa premiere apparition de str3:%s dans str2:%s est a la position %d\n", str3, str2, strst - str2);
    return 0;
}
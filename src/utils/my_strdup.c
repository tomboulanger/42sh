/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** my_strdup
*/

#include "../../include/my.h"

char *my_strdup(char *src)
{
    int i = 0;
    int c = 0;
    char *dest;

    while (src[i] != '\0') {
        i++;
    }
    dest = malloc(i + 1);
    while (i != 0) {
        dest[c] = src[c];
        c++;
        i--;
    }
    dest[c] = '\0';
    return (dest);
}
/*
** EPITECH PROJECT, 2021
** get
** File description:
** env
*/

#include "../../include/my.h"

char *my_strdup_env(char *src)
{
    int i = 0;
    int c = 0;
    char *dest;

    while (src[i] != '\0' && src[i] != ' ') {
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

char **get_env(char **env)
{
    int i  = 0;
    char **res;
    int f = 0;

    while (env[i] != NULL)
        i += 1;
    res = malloc(sizeof(char *)*i+1000);
    for (int j = 0; j != i; j += 1) {
        res[j] = my_strdup(env[j]);
        f = j;
    }
    res[f+1] = NULL;
    return (res);
}
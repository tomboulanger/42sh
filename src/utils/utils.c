/*
** EPITECH PROJECT, 2021
** t
** File description:
** t
*/

#include "../../include/my.h"

char **get_arg(char **res, int nb)
{
    char **post = malloc(sizeof(char *)*nb);

    for (int i = 0; i != nb-1; i += 1) {
        post[i] = my_strdup(res[i+1]);
    }
    free (res);
    return (post);
}
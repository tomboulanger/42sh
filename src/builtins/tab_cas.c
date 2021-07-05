/*
** EPITECH PROJECT, 2021
** spaces
** File description:
** tab
*/

#include "../../include/my.h"

char *space_first(char *str)
{
    while (str[0] == 32 || str[0] == 9) {
        str += 1;
    }
    return (str);
}

int check_end_tab(char *str, int i)
{
    while (str[i+1] != '\n') {
        if (str[i+1] != 32 && str[i+1] != 9 &&
        str[i+1] != 10)
            return (1);
        i += 1;
    }
    return (0);
}

char *reduc_end(char *src)
{
    int c = 0;
    char *dest;

    dest = malloc(sizeof(char)*my_strlen(src)*2);
    for (int i = 0; src[i] != '\0'; i += 1) {
        if (check_end_tab(src, i) == 0) {
            i = space_case(src, i);
        }
        dest[i] = src[i];
        c += 1;
    }
    dest[c] = '\0';
    if (dest[c-2] != '\n') {
        dest[c-1] = '\n';
        dest[c] = '\0';
    }
    return (dest);
}
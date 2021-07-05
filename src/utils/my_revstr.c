/*
** EPITECH PROJECT, 2020
** my
** File description:
** revstr
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int f = 0;
    int hold = 0;

    while (str[i] != '\0') {
        i++;
    }
    i--;
    while (i >= f) {
        hold = str[i];
        str[i] = str[f];
        str[f] = hold;
        f++;
        i--;
    }
    return (str);
}

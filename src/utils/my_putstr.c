/*
** EPITECH PROJECT, 2020
** Day04task02
** File description:
** putstr
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

void my_putexit(void)
{
    exit (0);
}

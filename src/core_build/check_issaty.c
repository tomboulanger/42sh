/*
** EPITECH PROJECT, 2021
** check
** File description:
** issaty
*/

#include "../../include/my.h"

void check_issaty(void)
{
    if (isatty(0) == 1)
        printf("$> ");
}
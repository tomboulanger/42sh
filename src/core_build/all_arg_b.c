/*
** EPITECH PROJECT, 2021
** all
** File description:
** argc
*/

#include "../../include/my.h"

char **all_arg_b(int c, int d, char **result)
{
    result[c][d-1] = '\0';
    result[c+1] = NULL;
    return (result);
}
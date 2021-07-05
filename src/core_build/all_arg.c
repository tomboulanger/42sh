/*
** EPITECH PROJECT, 2020
** all
** File description:
** arg
*/

#include "../../include/my.h"

int space_case(char *str, int i)
{
    while (str[i] == 32 || str[i] == 9)
        i += 1;
    return (i);
}

int check_end(char *str, int i)
{
    while (str[i] != '\0') {
        if (str[i] != 32 && str[i] != 9)
            return 0;
        i += 1;
    }
    return (1);
}

int nb_arg(char *str)
{
    int nb = 1;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if ((str[i] == 32 && check_end(str, i) == 0) ||
        (str[i] == 9 && check_end(str, i) == 0)   ) {
            nb += 1;
            i = space_case(str, i);
        }
    }
    return (nb);
}

char **malloc_result(int nb, char *str)
{
    char **result = malloc(sizeof(char *)*(nb+1));

    for (int i = 0; i != nb; i += 1)
        result[i] = malloc(sizeof(char)*my_strlen(str)+1);
    return (result);
}

char **all_arg(char *str, int *ab)
{
    char **result = malloc_result(nb_arg(str), str);
    int c = 0;
    int d = 0;

    *ab = nb_arg(str);
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == 32 || str[i] == '\0' || str[i] == 9) {
            result[c][d] = '\0';
            c += 1;
            i = space_case(str, i);
            d = 0;
        }
        if (str[i] != 32 && str[i] != 9) {
            result[c][d] = str[i];
            d += 1;
            i = space_case(str, i);
        }
    }
    result = all_arg_b(c, d, result);
    return (result);
}
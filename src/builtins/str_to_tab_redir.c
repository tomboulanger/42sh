/*
** EPITECH PROJECT, 2021
** str_to_tab_redir.c
** File description:
** str_to_tab_redir
*/

#include "../../include/my.h"

char **fill_res_redir(char **res, char *str, char divisor)
{
    int i = 0;
    int a = 0;
    int b = 0;

    while (str[i] != '\0') {
        if (str[i] == divisor && (str[i + 1] != divisor ||
        str[i + 1] == divisor)) {
            res[a][b] = '\0';
            a += 1;
            b = 0;
        } else  {
            res[a][b] = str[i];
            b += 1;
        }
        i += 1;
    }
    res[a][b] = '\0';
    return (res);
}

char **str_to_tab_redir(char *str, char divisor)
{
    int nb_arg = 0;
    char **res = NULL;

    str = removing_spaces(str);
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == divisor)
            nb_arg += 1;
    }
    nb_arg += 2;
    res = malloc_res(res, nb_arg, strlen(str));
    res = fill_res_redir(res, str, divisor);
    for (int i = 0; res[i] != NULL; i += 1){
        res[i] = removing_spaces(res[i]);
        res[i] = removing_spaces_middle(res[i]);
    }
    return (res);
}
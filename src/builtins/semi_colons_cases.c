/*
** EPITECH PROJECT, 2021
** semi
** File description:
** colons
*/

#include "../../include/my.h"

int get_nb_args(char **tmp)
{
    int nb = 0;

    for (int i = 0; tmp[i] != NULL; i += 1)
        nb += 1;
    return (nb);
}

void semi_colons_cases(t_envp *envp)
{
    char **res = str_to_tab(envp->argv, ';');
    char **tmp = NULL;
    int nb_arg = 0;

    for (int i = 0; res[i] != NULL; i += 1) {
        tmp = str_to_tab(res[i], ' ');
        nb_arg = get_nb_args(tmp);
        all_cases(tmp, envp, nb_arg);
    }
}
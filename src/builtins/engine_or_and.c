/*
** EPITECH PROJECT, 2021
** engine
** File description:
** orhand
*/

#include "../../include/my.h"

void engine_or_and(char **tmp, int *inst, t_envp *envp)
{
    int c = 0;
    char **total = NULL;
    int nb_arg = 0;

    for (int i = 0; tmp[i] != NULL; i += 1) {
        total = str_to_tab(tmp[i], ' ');
        nb_arg = get_nb_args(total);
        all_cases(total, envp, nb_arg);
        if (envp->return_value == 0) {
            if (inst[c] != 0)
                tmp[i] = NULL;
        } else {
            if (inst[c] == 0)
                tmp[i] = NULL;
        }
        if (tmp[i] == NULL)
            return;
        c += 1;
    }
}
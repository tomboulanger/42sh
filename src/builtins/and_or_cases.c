/*
** EPITECH PROJECT, 2021
** andor
** File description:
** casehan
*/

#include "../../include/my.h"

int nb_inst(t_envp *envp)
{
    int nb_malloc = 0;

    for (int i = 0; envp->argv[i + 1] != '\0'; i += 1) {
        if ((envp->argv[i] == '|' && envp->argv[i + 1] == '|') ||
        (envp->argv[i] == '&' && envp->argv[i + 1] == '&'))
            nb_malloc += 1;
    }
    if (nb_malloc != 0)
        return (nb_malloc + 1);
    return (0);
}

int *get_inst(t_envp *envp)
{
    int *nb = malloc(sizeof(int) * nb_inst(envp));
    int c = 0;

    for (int i = 0; envp->argv[i + 1] != '\0'; i += 1) {
        if (envp->argv[i] == '|' && envp->argv[i + 1] == '|') {
            nb[c] = 1;
            c += 1;
            envp->argv[i] = '~';
            envp->argv[i + 1] = ' ';
        } else if (envp->argv[i] == '&' && envp->argv[i + 1] == '&') {
            nb[c] = 0;
            c += 1;
            envp->argv[i] = '~';
            envp->argv[i + 1] = ' ';
        }
    }
    nb[c] = -1;
    return (nb);
}

int and_handling(t_envp *envp)
{
    int *inst = NULL;
    char **tmp = NULL;
    int nb = nb_inst(envp);

    if (nb > 0) {
        inst = get_inst(envp);
        tmp = str_to_tab(envp->argv, '~');
        engine_or_and(tmp, inst, envp);
        return (0);
    }
    return (1);
}
/*
** EPITECH PROJECT, 2021
** env
** File description:
** case
*/

#include "../../include/my.h"

void env(t_envp *envp)
{
    int cas = 0;

    for (int i = 0; envp->env[i] != NULL; i += 1) {
        cas = 0;
        if (envp->env[i][0] == 'O' && envp->env[i][1] == 'L' &&
        envp->env[i][2] == 'D' && envp->f_pre_dir != 1) {
            printf("OLDPWD=%s\n", envp->pre_dir);
            cas = 1;
        }
        else if (envp->env[i][0] == 'P' &&
        envp->env[i][1] == 'W' && envp->env[i][2] == 'D' &&
        envp->f_actual_dir != 1) {
            printf("PWD=%s\n", envp->actual_dir);
            cas = 1;
        }
        if (envp->env[i][0] != '1' && cas == 0) {
            printf("%s\n", envp->env[i]);
        }
    }
}

void env_handling(char **av, t_envp *envp, int nb_arg)
{
    if (str_cmp(av[0], "setenv") == 0)
        setenv_case(envp, av, nb_arg);
    if (str_cmp(av[0], "env") == 0)
        env(envp);
}
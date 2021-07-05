/*
** EPITECH PROJECT, 2020
** exit
** File description:
** case
*/

#include "../../include/my.h"

void free_shell(t_envp *envp)
{
    for (int i = 0; envp->env[i] != NULL; i += 1)
        free (envp->env[i]);
    free (envp->pre_dir);
    free (envp->actual_dir);
    free (envp->argv);
    free (envp);
}

void exit_case(char **av, int nb_arg, t_envp *envp)
{
    if (str_cmp(av[0], "exit") == 0 && nb_arg == 1) {
        printf("exit\n");
        free_shell(envp);
        exit (0);
    } else if (str_cmp(av[0], "exit") == 0 && nb_arg == 2) {
        printf("exit\n");
        envp->return_value = atoi(av[1]);
    }
    if (str_cmp(av[0], "exit") == 0 && nb_arg > 2) {
        printf("exit: Expression Syntax.\n");
        envp->return_value = -1;
    }

}
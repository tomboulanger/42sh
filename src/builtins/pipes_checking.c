/*
** EPITECH PROJECT, 2021
** pipe_checking
** File description:
** t
*/

#include "../../include/my.h"

void lunch_binary_pipe(t_envp *envp, char **pro)
{
    int nb_arg;

    all_binaries_cases(envp, pro[0], envp->env, pro);
    nb_arg = get_nb_args(pro);
    echo_cases(pro, envp, nb_arg);
    if (str_cmp(pro[0], "env") == 0)
        env(envp);
    binaries_case(pro, envp->env, envp);
}

int detect_pipe(t_envp *envp, char **av)
{
    envp->pipe = 0;
    for (int i = 0; av[i] != NULL; i += 1) {
        for (int y = 0; av[i][y] != '\0'; y += 1) {
            if (av[i][y] == '|' && av[i][y + 1] != '|' &&
            av[i][y - 1] != '|') {
                envp->pipe = i;
                return (1);
            }
        }
    }
    return (0);
}

int check_fd_pid(int pfd[2], int pid)
{
    if (pipe(pfd) == -1) {
        exit(1);
    }
    if ((pid = fork()) < 0) {
        exit(1);
    }
    return (pid);
}
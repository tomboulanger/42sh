/*
** EPITECH PROJECT, 2021
** pipe
** File description:
** t
*/

#include "../../include/my.h"

void child_process(int save_fd, int pfd[2], char *argv)
{
    dup2(save_fd, 0);
    if (argv != NULL)
        dup2(pfd[1], 1);
    close(pfd[0]);
}

void close_all(int i, int pfd[2])
{
    int status = 0;

    while (i != 0) {
        wait(&status);
        i -= 1;
    }
    close(pfd[0]);
    close(pfd[1]);
}

void lunch_pipe(t_envp *envp)
{
    char **argv = str_to_tab(envp->argv, '|');
    char **pro = NULL;
    int pfd[2];
    int i = 0;
    int pid = 0;
    int save_fd = 0;

    for (i = 0; argv[i] != NULL; i += 1) {
        pro = str_to_tab(argv[i], ' ');
        pid = check_fd_pid(pfd, pid);
        if (pid == 0) {
            child_process(save_fd, pfd, argv[i+1]);
            lunch_binary_pipe(envp, pro);
            exit(1);
        } else {
            close(pfd[1]);
            save_fd = pfd[0];
        }
    }
    close_all(i, pfd);
}

int pipe_case(t_envp *envp, char **av)
{
    if (detect_pipe(envp, av) == 0)
        return (1);
    envp->my_pipe = 1;
    lunch_pipe(envp);
    envp->my_pipe = 0;
    return (0);
}
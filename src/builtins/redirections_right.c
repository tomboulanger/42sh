/*
** EPITECH PROJECT, 2021
** redirections_right.c
** File description:
** redirections_right
*/

#include "../../include/my.h"

int gest_redirections_right(char **av, t_envp *envp)
{
    if (detect_rafter(av, envp) == 0)
        return (1);
    redirections_right(av, envp);
    return (0);
}

void redirections_right(char **av, t_envp *envp)
{
    pid_t pid;
    int status = 0;
    int save = dup(1);

    pid = fork();
    if (pid == -1)
        exit(1);
    else if (pid == 0) {
        my_redirections_right(av, envp);
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        dup2(1, save);
    }
    close(save);
}

void my_redirections_right(char **av, t_envp *envp)
{
    int fd = 0;
    char **argv = str_to_tab_redir(envp->argv, '>');
    char **pro = str_to_tab(argv[0], ' ');

    if (detect_rafter(av, envp) == 1)
        fd = open(av[envp->redirection_right + 1],
        O_CREAT | O_RDWR | O_TRUNC, 0777);
    else if (detect_rafter(av, envp) == 2)
        fd = open(av[envp->redirection_right + 1],
        O_CREAT | O_RDWR | O_APPEND, 0777);
    dup2(fd, 1);
    launch_redir(envp, pro);
}

int detect_rafter(char **av, t_envp *envp)
{
    envp->redirection_right = 0;
    for (int i = 0; av[i] != NULL; i += 1) {
        for (int y = 0; av[i][y] != '\0'; y += 1) {
            if (av[i][0] == '>' && i >= 2 && av[i][1] == '\0') {
                envp->redirection_right = i;
                return (1);
            }
            else if (av[i][0] == '>' && av[i][1] == '>' &&
            i >= 2 && av[i][2] == '\0') {
                envp->redirection_right = i;
                return (2);
            }
        }
    }
    return (0);
}

void launch_redir(t_envp *envp, char **pro)
{
    all_cases(pro, envp, get_nb_args(pro));
}
/*
** EPITECH PROJECT, 2021
** binaries
** File description:
** case
*/

#include "../../include/my.h"

void bi_b(char **av, char **envp, t_envp *envpp)
{
    if (execve(av[0], av, envp) == -1) {
        fprintf(stderr, "%s%s", av[0], ": Exec ");
        fprintf(stderr, "format error. Wrong Architecture.\n");
        envpp->return_value = 1;
    }
}

bool test_folder(char **av, t_envp *envp)
{
    char *str = my_strdup(av[0]);
    struct stat buf;

    stat(str, &buf);
    if (S_ISDIR(buf.st_mode)) {
        fprintf(stderr, "%s: Permission denied.\n", str);
        envp->return_value = 1;
        return (true);
    }
    return (false);
}

bool is_binarie(char *cmd)
{
    struct stat buf;

    stat(cmd, &buf);
    if (S_ISREG(buf.st_mode)) {
        return (true);
    }
    return (false);
}

bool check_command(char *cmd)
{
    for (int i = 0; cmd[i] != '\0'; i += 1) {
        if (cmd[i] == '.' || cmd[i] == '/')
            return (true);
    }
    return (false);
}

int binaries_case(char **av, char **env_p, t_envp *envp)
{
    int status;

    if (check_command(av[0]) == false)
        return (1);
    if (test_folder(av, envp) == true)
        return (0);
    if (((av[0][0] == '.' && av[0][1] == '/') ||
    av[0][1] == '/') || !access(av[0], X_OK)) {
        if (envp->my_pipe == 1) {
            bi_b(av, env_p, envp);
        }
        if (fork() == 0)
            bi_b(av, env_p, envp);
        else {
            waitpid(0, &status, 0);
            signal_handling(status, envp);
        }
        return (0);
    }
    return (1);
}
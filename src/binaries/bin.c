/*
** EPITECH PROJECT, 2021
** test
** File description:
** main
*/

#include "../../include/my.h"

int detect_bin(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == ':')
            nb += 1;
    }
    nb += 1;
    return (nb);
}

char *my_str_find(char **env)
{
    for (int i = 0; env[i] != NULL; i += 1) {
        if (env[i][1] == 'A' &&
        env[i][2] == 'T' && env[i][3] == 'H')
            return (my_strdup(env[i]));
    }
    return ("\0");
}

char **bin_find(char **env)
{
    char *copy = my_str_find(env);
    char **res = malloc(sizeof(char *) * (detect_bin(copy) + 1));
    int i = 0;

    copy += 5;
    while (copy[0] != '\0') {
        if (copy[0] == ':')
            copy += 1;
        res[i] = my_str_bin(copy);
        while (copy[0] != '\0' && copy[0] != ':')
            copy += 1;
        i += 1;
    }
    res[i] = NULL;
    return (res);
}

char *verify_bin(char **res, char *cmd, t_envp *envp)
{
    int i = 0;
    char *temp;

    for (int c = 0; cmd[c] != '\0'; c += 1) {
        if (cmd[c] == '/')
            i = 1;
    }
    if (i == 1) {
        if (access(cmd, F_OK) == 0)
            return (cmd);
        not_found_case(cmd, envp);
        return ("\0");
    }
    for (int j = 0; res[j] != NULL; j += 1) {
        temp = my_strcat((my_strcat(res[j], "/")), cmd);
        if (access(temp, F_OK) == 0)
            return (temp);
    }
    not_found_case(cmd, envp);
    return ("\0");
}

void all_binaries_cases(t_envp *envp, char *cmd, char **env, char **av)
{
    char *str;
    int status;

    if (cmd[0] == 46 && cmd[1] == 47)
        return;
    if (verify_cmd(cmd) == true)
        return;
    str = verify_bin(bin_find(env), cmd, envp);
    if (str[0] != '\0') {
        if (envp->my_pipe == 1)
            execve(str, av, env);
        if (fork() == 0)
            execve(str, av, env);
        else {
            waitpid(0, &status, 0);
            signal_handling(status, envp);
        }
    }
}
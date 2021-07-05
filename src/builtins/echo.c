/*
** EPITECH PROJECT, 2021
** echo
** File description:
** handling
*/

#include "../../include/my.h"

void display_find(char *str, char **env)
{
    char *copy = NULL;

    str += 1;
    for (int i = 0; env[i] != NULL; i += 1) {
        if (strncmp(str, env[i], strlen(str)) == 0 &&
        env[i][strlen(str)] == '=') {
            copy = my_strdup(env[i]);
            copy += (strlen(str) + 1);
            printf("%s\n", copy);
            return;
        }
    }
}

void display_echo(char *str, t_envp *envp, char *next)
{
    if (str[0] == '$' && str[1] == '?')
        printf("%d\n", envp->return_value);
    else if (str[0] == '$' && str[1] != '?')
        display_find(str, envp->env);
    else {
        if (next == NULL) {
            printf("%s\n", str);
        } else {
            printf("%s ", str);
        }
    }
}

void echo_cases(char **av, t_envp *envp, int nb_arg)
{
    if (str_cmp(av[0], "echo") == 0) {
        if (nb_arg == 1)
            printf("\n");
        for (int i = 1; av[i] != NULL; i += 1)
            display_echo(av[i], envp, av[i + 1]);
        envp->return_value = 0;
    }
}
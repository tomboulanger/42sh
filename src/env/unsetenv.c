/*
** EPITECH PROJECT, 2021
** unset
** File description:
** env
*/

#include "../../include/my.h"

int my_str_unset(char const *str)
{
    int i = 0;

    while (str[i] != '=' && str[i] != '\0') {
        i++;
    }
    return (i);
}

int str_un(char *src, char *new)
{
    if (my_str_unset(src) != my_str_unset(new))
        return (1);
    for (int i = 0; src[i] != '=' && src[i] != '\0'; i += 1) {
        if (src[i] != new[i])
            return (1);
    }
    return (0);
}

void unset(char *env_line, char *str)
{
    if (str_un(env_line, str) == 0) {
        env_line[0] = '1';
    }
}

void unsetenv_b(char **envp, char **av, int nb)
{
    for (int i = 0; envp[i] != NULL; i += 1) {
        for (int j = 1; j != nb; j += 1) {
            unset(envp[i], av[j]);
        }
    }
}

void unsetenv_case(char **envp, char **av, int nb)
{
    if (str_cmp(av[0], "unsetenv") == 0) {
        unsetenv_b(envp, av, nb);
    }
}
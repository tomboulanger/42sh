/*
** EPITECH PROJECT, 2021
** t
** File description:
** t
*/

#include "../../include/my.h"

int my_where(char **av, t_envp *envp)
{
    if (str_cmp(av[0], "where") != 0)
        return (0);
    if (str_cmp(av[1], "cd") == 0 || str_cmp(av[1], "setenv") == 0 ||
    str_cmp(av[1], "unsetenv") == 0 || str_cmp(av[1], "env") == 0 ||
    str_cmp(av[1], "exit") == 0 ||  str_cmp(av[1], "\0") == 0 ||
    str_cmp(av[1], "echo") == 0) {
        printf("%s: shell built-in command.", av[1]);
        return (1);
    }
    find_alias(av, envp, 2);
    display_env(av[1], envp);
    return (1);
}
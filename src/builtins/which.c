/*
** EPITECH PROJECT, 2021
** t
** File description:
** t
*/

#include "../../include/my.h"

void my_which(char **av, t_envp *envp)
{
    char *str = NULL;

    if (str_cmp(av[0], "which") != 0)
        return;
    if (str_cmp(av[1], "cd") == 0 || str_cmp(av[1], "setenv") == 0 ||
    str_cmp(av[1], "unsetenv") == 0 || str_cmp(av[1], "env") == 0 ||
    str_cmp(av[1], "exit") == 0
    ||  str_cmp(av[1], "\0") == 0 ||  str_cmp(av[1], "echo") == 0) {
        printf("%s: shell built-in command.", av[1]);
        return;
    }
    str = verify_bin(bin_find(envp->env), av[1], envp);

    if (str[0] != '\0') {
        printf("%s\n", str);
        return;
    }
    envp->return_value = 1;
}
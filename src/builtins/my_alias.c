/*
** EPITECH PROJECT, 2021
** t
** File description:
** t
*/

#include "../../include/my.h"

void alias_open(char **av)
{
    int fd = 0;

    fd = open(".alias", O_CREAT | O_RDWR | O_APPEND, 0777);
    write(fd, "~", 1);
    write(fd, strcat(av[1], "~"), strlen(av[1]) + 1);
    for (int i = 2; av[i] != NULL; i += 1)
        write(fd, strcat(av[i], " "), strlen(av[i]) + 1);
    close (fd);
}

int my_alias(char **av, t_envp *envp)
{
    if (av[0][0] == 0) {
        return (0);
    }
    if (str_cmp(av[0], "alias") == 0 || find_alias(av, envp, 0) == 1) {
        if (str_cmp(av[0], "alias") == 0 && av[1] != NULL && av[2] != NULL)
            alias_open(av);
        if (str_cmp(av[0], "alias") == 0 && av[1] == NULL)
            return (0);
        if (str_cmp(av[0], "alias") == 0 && av[1] != NULL && av[2] == NULL)
            find_alias(av, envp, 1);
        return (1);
    }
    return (0);
}
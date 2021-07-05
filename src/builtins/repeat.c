/*
** EPITECH PROJECT, 2021
** repeat.c
** File description:
** repeat
*/

#include "../../include/my.h"

int check_nb_repeat(char **av)
{
    char *str = av[1];
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            printf("repeat: Badly formed number.\n");
            return (1);
        }
    }
    return (0);
}

int exec_repeat(char **av, t_envp *envp)
{
    int i = 0;
    int nb_arg = -2;
    int nb_repeat = atoi(av[1]);
    char **pro = NULL;
    char **tab = NULL;

    for (i = 0; av[i] != NULL; i++)
        nb_arg++;
    tab = my_repeat_tab(av);
    my_repeat_create_tab(av, tab, nb_arg);
    for (i = 0; i < nb_repeat; i++) {
        pro = str_to_tab(tab[0], ' ');
        all_cases(pro, envp, get_nb_args(pro));
    }
    free(tab[0]);
    return (0);
}

char **my_repeat_tab(char **av)
{
    int i = 0;
    int len = 0;
    char **tab = NULL;
    int y = 0;

    for (i = 2; av[i] != NULL; i++) {
        for (y = 0; av[i][y] != '\0'; y++)
            len++;
    }
    tab = malloc(sizeof(char *) * 1);
    tab[0] = malloc(sizeof(char) * len + 1);
    return (tab);
}

int my_repeat_create_tab(char **av, char **tab, int nb_arg)
{
    int i = 0;
    int y = 0;
    int e = 0;

    for (i = 2; av[i] != NULL; i++) {
        for (y = 0; av[i][y] != '\0'; y++) {
            tab[0][e] = av[i][y];
            e++;
        }
        if (i <= nb_arg) {
            tab[0][e] = ' ';
            e++;
        }
    }
    return (0);
}

int my_repeat(char **av, t_envp *envp)
{
    char *str = av[0];

    if (str_cmp(str, "repeat") == 0 && check_nb_repeat(av) == 0) {
        exec_repeat(av, envp);
        return (1);
    }
    return (0);
}
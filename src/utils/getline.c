/*
** EPITECH PROJECT, 2020
** get
** File description:
** line
*/

#include "../../include/my.h"

int str_cmp(char *sa, char *sb)
{
    if (my_strlen(sa) != my_strlen(sb))
        return (1);
    for (int i = 0; sa[i] != '\0'; i += 1) {
        if (sa[i] != sb[i])
            return (1);
    }
    return (0);
}

int check_doub_lef(char **av)
{
    for (int i = 0; av[i] != NULL; i += 1) {
        if (av[i][0] == '<' && av[i][1] == '<')
            return (0);
    }
    return (1);
}

char *end_word(char *string, int i)
{
    while (string[i] != '\0' && string[i] != '\n' && string[i] != 32)
        i += 1;
    string[i] = '\0';
    return (string);
}

void free_result(char **result, int nb)
{
    for (int i = 0; i != nb; i += 1) {
        free (result[i]);
    }
    free (result);
}

char **my_getline(t_envp *envp, int *nb)
{
    size_t size = 2;
    char *string = NULL;
    char **result = NULL;
    int nb_arg = 0;
    envp->argv = NULL;

    check_issaty();
    if (getline(&string, &size, stdin) == -1)
        envp->end = 0;
    result = all_arg(reduc_end(space_first(string)), &nb_arg);
    envp->argv = reduc_end(space_first(string));
    envp->argv[strlen(envp->argv) - 1] = '\0';
    *nb = nb_arg;
    return (result);
}
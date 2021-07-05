/*
** EPITECH PROJECT, 2021
** setenv
** File description:
** add
*/

#include "../../include/my.h"

int check_first(char *str, t_envp *envp)
{
    if (str[0] >= '0' && str[0] <= '9') {
        printf("setenv: Variable name must");
        printf(" begin with a letter.\n");
        envp->return_value = -1;
        return (1);
    }
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (!((str[i] > 47 && str[i] < 58) || ( str[i] > 64 &&
        str[i] < 91) || (str[i] > 96 && str[i] < 123))) {
            printf("setenv: Variable name must");
            printf(" contain alphanumeric characters.\n");
            envp->return_value = -1;
            return (1);
        }
    }
    return (0);
}

bool check(char *sa, char *env_var, t_envp *envpp)
{
    size_t lg = 0;

    for (int i = 0; env_var[i] != '='; i += 1) {
        lg += 1;
    }
    if (strlen(sa) != lg)
        return (false);
    if (strncmp(sa, env_var, lg) == 0) {
        if (str_cmp(sa, "PWD") == 0)
            envpp->f_actual_dir = 1;
        if (str_cmp(sa, "OLDPWD") == 0)
            envpp->f_pre_dir = 1;
        return true;
    }
    return (false);
}

void path_case(t_envp *envpp)
{
    for (int i = 0; envpp->env[i] != NULL; i += 1) {
        if (envpp->env[i][0] == '1' && envpp->env[i][1] == 'A' &&
        envpp->env[i][2] == 'T' && envpp->env[i][3] == 'H' &&
        envpp->env[i][4] == '=')
            envpp->env[i][1] = '2';
    }
}

void add_env(char **envp, char *sa, char *sb, t_envp *envpp)
{
    int c = 0;
    int last = 0;

    if (str_cmp(sa, "PATH") == 0)
        path_case(envpp);
    while (envp[c] != NULL && check(sa, envp[c], envpp) == false)
        c += 1;
    if (envp[c] == NULL)
        last = 1;
    else {
        free (envp[c]);
    }
    if (sb == NULL)
        envp[c] = my_strcat(sa, "=");
    else
        envp[c] = my_strcat(my_strcat(sa, "="), sb);
    if (last == 1)
        envp[c + 1] = NULL;
    envpp->return_value = 0;
}

void setenv_case(t_envp *envp, char **av, int nb)
{
    if (nb == 1)
        env(envp);
    if (nb == 2) {
        if (check_first(av[1], envp) == 0)
            add_env(envp->env, av[1], NULL, envp);
    }
    if (nb == 3) {
        if (check_first(av[1], envp) == 0)
            add_env(envp->env, av[1], av[2], envp);
    }
    if (nb != 1 && nb != 2 && nb != 3) {
        fprintf(stderr, "setenv: Too many arguments.\n");
        envp->return_value = -1;
    }
}
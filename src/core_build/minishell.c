/*
** EPITECH PROJECT, 2020
** mini
** File description:
** shell
*/

#include "../../include/my.h"

char *get_user(char **env)
{
    char *res = NULL;
    char *str = "user";

    for (int i = 0; env[i] != NULL; i += 1) {
        if (env[i][0] == 'U' && env[i][1] == 'S' &&
        env[i][2] == 'E' && env[i][3] == 'R') {
            res = my_strdup(env[i]);
            res += 5;
            return (res);
        }
    }
    return (str);
}

int first_cases(char **av, t_envp *envp, int nb_arg)
{
    if (pipe_case(envp, av) == 0)
        return (1);
    if (and_handling(envp) == 0)
        return (1);
    if (gest_redirections_right(av, envp) == 0)
        return (1);
    if (check_doub_lef(av) == 0)
        av = double_red_lef(av, &nb_arg, envp);
    if (check_redir_left(envp) == 1) {
        my_redir_left(av, envp);
        return (1);
    }
    if (my_repeat(av, envp) == 1)
        return (1);
    if (my_alias(av, envp) == 1)
        return (1);
    return (0);
}

void all_cases(char **av, t_envp *envp, int nb_arg)
{
    envp->c_tinue = 0;
    if (first_cases(av, envp, nb_arg) == 1)
        return;
    if (envp->c_tinue == 1)
        return;
    if (my_where(av, envp) == 1)
        return;
    my_which(av, envp);
    if (binaries_case(av, envp->env, envp) == 0)
        return;
    all_binaries_cases(envp, av[0], envp->env, av);
    exit_case(av, nb_arg, envp);
    cd(av, nb_arg, envp, get_user(envp->env));
    echo_cases(av, envp, nb_arg);
    env_handling(av, envp, nb_arg);
    unsetenv_case(envp->env, av, nb_arg);
    for (int i = 0; i != nb_arg; i += 1)
        free (av[i]);
}

int nb_semicolons(char **res)
{
    for (int i = 0; res[i] != NULL; i += 1) {
        for (int j = 0; res[i][j] != '\0'; j += 1)
            if (res[i][j] == ';')
                return (0);
    }
    return (1);
}

int minishell(char **environ)
{
    char **result;
    int nb_arg = 0;
    t_envp *envp = malloc(sizeof(t_envp)*2);
    envp->my_pipe = 0;

    envp->env = get_env(environ);
    envp->actual_dir = get_pwd(envp->env, false);
    envp->pre_dir = get_pwd(envp->env, true);
    envp->cd_ = false;
    envp->return_value = 0;
    envp->end = 1;
    while (envp->end) {
        result = my_getline(envp, &nb_arg);
        if (result == NULL)
            envp->end = 0;
        else {
            minishell_b(result, envp, nb_arg);
        }
    }
    return (envp->return_value);
}
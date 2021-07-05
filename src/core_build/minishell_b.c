/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** handling
*/

#include "../../include/my.h"

void minishell_b(char **result, t_envp *envp, int nb_arg)
{
    if (nb_semicolons(result))
        all_cases(result, envp, nb_arg);
    else
        semi_colons_cases(envp);
}
/*
** EPITECH PROJECT, 2020
** main_shell
** File description:
** my_ls
*/

#include "../../include/my.h"

int main(int ac, char **av, char **env)
{
    if (ac != 1) {
        my_putstr("Error, no arguments needed.\n");
        return (84);
    }
    av += 0;
    open_alias();
    return (minishell(env));
}
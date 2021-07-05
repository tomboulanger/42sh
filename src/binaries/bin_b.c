/*
** EPITECH PROJECT, 2021
** bin
** File description:
** cmd
*/

#include "../../include/my.h"

bool are_redit(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '>')
            return (true);
    }
    return (false);
}

void not_found_case(char *cmd, t_envp *envp)
{
    fprintf(stderr, "%s: Command not found.\n", cmd);
    envp->return_value = 127;
}

bool verify_cmd(char *cmd)
{
    if (str_cmp(cmd, "cd") == 0 || str_cmp(cmd, "setenv") == 0 || str_cmp(cmd,
    "unsetenv") == 0 || str_cmp(cmd, "env") == 0 || str_cmp(cmd, "exit") == 0
    ||  str_cmp(cmd, "\0") == 0 ||  str_cmp(cmd, "echo") == 0 ||
    str_cmp(cmd, "which") == 0 || str_cmp(cmd, "alias") == 0)
        return (true);
    return (false);
}

char *my_str_bin(char *src)
{
    int i = 0;
    int c = 0;
    char *dest;

    while (src[i] != '\0' && src[i] != ':') {
        i++;
    }
    dest = malloc(i + 1);
    while (i != 0) {
        dest[c] = src[c];
        c++;
        i--;
    }
    dest[c] = '\0';
    return (dest);
}
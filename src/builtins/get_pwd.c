/*
** EPITECH PROJECT, 2021
** getpwd
** File description:
** getp
*/

#include "../../include/my.h"

char *pwd_case(char **env, char *res)
{
    for (int i = 0; env[i] != NULL; i += 1) {
        if (env[i][0] == 'P' && env[i][1] == 'W' && env[i][2] == 'D') {
            res = my_strdup(env[i]);
            res += 4;
            return (res);
        }
    }
    return (get_user(env));
}

char *old_pwd_case(char **env, char *res)
{
    for (int i = 0; env[i] != NULL; i += 1) {
        if (env[i][0] == 'O' && env[i][1] == 'L' && env[i][2] == 'D' &&
        env[i][3] == 'P' && env[i][4] == 'W' && env[i][5] == 'D') {
            res = my_strdup(env[i]);
            res += 7;
            return (res);
        }
    }
    return (get_user(env));
}

char *get_pwd(char **env, bool old)
{
    char *res = NULL;

    if (old == false)
        return (res = pwd_case(env, res));
    else
        return (res = old_pwd_case(env, res));
    return (get_user(env));
}
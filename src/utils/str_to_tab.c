/*
** EPITECH PROJECT, 2021
** pipi
** File description:
** handling
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <grp.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>

char *removing_spaces(char *str)
{
    int lg = strlen(str) - 1;

    while (str[0] == ' ' || str[0] == '\t') {
        str += 1;
        lg -= 1;
    }
    while (str[lg] == ' ' || str[lg] == '\t') {
        str[lg] = '\0';
        lg -= 1;
    }
    return (str);
}

char *removing_spaces_middle(char *str)
{
    char *copy = malloc(sizeof(char) * (strlen(str) + 2));
    int c = 0;
    int i = 0;

    for (; str[i + 1] != '\0'; i += 1) {
        if (str[i] == ' ' || str[i] == '\t') {
            copy[c] = ' ';
            c += 1;
        }
        while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
            i += 1;
        copy[c] = str[i];
        c += 1;
    }
    copy[c] = str[i];
    copy[c + 1] = '\0';
    return (copy);
}

char **malloc_res(char **res, int nb_arg, int lg)
{
    res = malloc(sizeof(char *) * (nb_arg + 1));

    for (int i = 0; i != nb_arg; i += 1)
        res[i] = malloc(sizeof(char) * (lg + 2));
    res[nb_arg - 1] = NULL;
    return (res);
}

char **fill_res(char **res, char *str, char divisor)
{
    int i = 0;
    int a = 0;
    int b = 0;

    while (str[i + 1] != '\0') {
        if (str[i] == divisor && str[i + 1] != divisor) {
            res[a][b] = '\0';
            a += 1;
            b = 0;
        } else  {
            res[a][b] = str[i];
            b += 1;
        }
        i += 1;
    }
    res[a][b] = str[i];
    res[a][b + 1] = '\0';
    return (res);
}

char **str_to_tab(char *str, char divisor)
{
    int nb_arg = 0;
    char **res = NULL;

    str = removing_spaces(str);
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == divisor)
            nb_arg += 1;
    }
    nb_arg += 2;
    res = malloc_res(res, nb_arg, strlen(str));
    res = fill_res(res, str, divisor);
    for (int i = 0; res[i] != NULL; i += 1){
        res[i] = removing_spaces(res[i]);
        res[i] = removing_spaces_middle(res[i]);
    }
    return (res);
}
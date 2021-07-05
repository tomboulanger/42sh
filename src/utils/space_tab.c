/*
** EPITECH PROJECT, 2021
** t
** File description:
** t
*/

#include "../../include/my.h"

char *take_off_space(char *argv)
{
    char *res = malloc(sizeof(char) * (my_strlen(argv)));
    int a = 0;

    for (int i = 0; argv[i] != '\0'; i += 1) {
        if (argv[i] == ' ' && argv[i+1] == ' ') {
            res[a] = argv[i];
            i += 1;
            a += 1;
        }
        while (argv[i] == ' ')
            i += 1;
        res[a] = argv[i];
        a += 1;
    }
    res[a] = '\0';
    return (res);
}
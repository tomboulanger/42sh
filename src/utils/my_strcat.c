/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** concatstring
*/

#include "../../include/my.h"

char *my_strcat(char *path, char *src)
{
    int i = 0;
    int j = 0;
    char *result = malloc(sizeof(char)*(my_strlen(path) +
    my_strlen(src))+2);

    while (path[i] != '\0') {
        result[i] = path[i];
        i++;
    }
    while (src[j] != '\0') {
        result[i] = src[j];
        i++;
        j++;
    }
    result[i] = '\0';
    return (result);
}
/*
** EPITECH PROJECT, 2021
** tff
** File description:
** tfff
*/

#include "../../include/my.h"

void open_alias(void)
{
    int fd = 0;

    fd = open(".alias", O_CREAT | O_RDWR | O_TRUNC, 0777);
    write (fd, "~", 1);
}
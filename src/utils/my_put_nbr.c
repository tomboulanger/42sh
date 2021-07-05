/*
** EPITECH PROJECT, 2020
** Day03task07
** File description:
** put_nbr
*/

#include "../../include/my.h"

int get_number(int nb)
{
    if (nb == -2147483648) {
        my_putstr("-2147483648");
    }
    if (nb < 0 && nb != -2147483648) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb == 0)
        my_putchar('0');
    return (nb);
}

void negpos(int origin)
{
    if (origin > 0)
        my_putchar(origin %10 + 48);
    else {
        origin = -origin;
        my_putchar(origin %10 + 48);
    }
}

void my_put_nbr(int nb)
{
    int origin = nb;
    int hold = 1;

    nb = get_number(nb);
    if (nb == -2147483648 || nb == 0)
        return;
    nb /= 10;
    while (nb != 0) {
        hold = hold * 10;
        hold = hold + nb %10;
        nb = nb / 10;
    }
    while (hold >=  10) {
        my_putchar(hold %10 + 48);
        hold = hold / 10;
    }
    negpos(origin);
}

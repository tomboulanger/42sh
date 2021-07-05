/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** lgtstring
*/

void my_putchar(char c);

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Infos
*/
#include "../src/my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    int c = 0;

    while (str[c] != '\0') {
        my_putchar(str[c]);
        c = c + 1;
    }
    return 0;
}

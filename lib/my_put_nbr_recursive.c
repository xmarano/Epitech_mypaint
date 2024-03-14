/*
** EPITECH PROJECT, 2023
** my_put_nbr_recursive
** File description:
** Infos
*/
#include "../src/my.h"
#include <unistd.h>

int my_put_nbr_recursive(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_nbr_recursive(nb / 10);
    }
    my_putchar('0' + nb % 10);
    return 0;
}

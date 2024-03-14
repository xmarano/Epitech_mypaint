/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** Infos
*/
#include "../src/my.h"
#include <unistd.h>

int my_put_nbr(int nb)
{
    if (nb == 0) {
        my_putchar('0');
    } else {
        my_put_nbr_recursive(nb);
    }
    return 0;
}

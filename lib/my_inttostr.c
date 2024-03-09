/*
** EPITECH PROJECT, 2023
** my_inttostr
** File description:
** my_inttostr.c
*/
#include "../src/my.h"

int length(int num)
{
    int len = 0;

    while (num != 0) {
        num /= 10;
        len++;
    }
    return len;
}

char *my_inttostr(int num)
{
    int len = length(num);
    char *str = malloc(len + 1);

    for (int i = len - 1; i >= 0; i--) {
        str[i] = (num % 10) + '0';
        num /= 10;
    }
    str[len] = '\0';
    return str;
}

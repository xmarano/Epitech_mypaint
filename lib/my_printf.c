/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Infos
*/
#include "../src/my.h"

int verify_printf(char ltr, va_list *args)
{
    char *str;
    char c;
    int nb = 0;

    if (ltr == 'd' || ltr == 'i') {
        nb = va_arg(*args, int);
        my_put_nbr(nb);
    }
    if (ltr == 'c') {
        c = va_arg(*args, int);
        my_putchar(c);
    }
    if (ltr == 's') {
        str = va_arg(*args, char *);
        my_putstr(str);
    }
    return 0;
}

int my_printf(const char *format, ...)
{
    int result = 0;
    va_list args;

    va_start(args, format);
    while (*format != '\0') {
        if (*format == '%') {
            verify_printf(*(++format), &args);
        } else {
            result += write(1, format, 1);
        }
        ++format;
    }
    va_end(args);
    return result;
}

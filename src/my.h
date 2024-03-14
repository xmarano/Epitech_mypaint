/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** my.h
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#ifndef MY_H
    #define MY_H
int my_atoi(char *str);
int my_put_nbr(int nb);
void my_putchar(char c);
char *my_inttostr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_nbr_recursive(int nb);
int my_printf(const char *format, ...);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
#endif

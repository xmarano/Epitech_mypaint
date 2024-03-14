/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** Infos
*/
#include "../src/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *str = malloc((my_strlen(dest) + my_strlen(src) + 1) * sizeof(char));

    while (dest[j] != '\0') {
        str[i] = dest[j];
        i++;
        j++;
    }
    j = 0;
    while (src[j] != '\0') {
        str[i] = src[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return str;
}

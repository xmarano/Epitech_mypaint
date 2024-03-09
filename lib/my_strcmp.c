/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** my_strcmp.c
*/
int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

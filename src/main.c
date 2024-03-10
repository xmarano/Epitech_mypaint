/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** main.c
*/
#include "paint.h"

void initialisation(Sprite_t *s)
{
    s->pixel = sfRectangleShape_create();
}

void set_st(sfRenderWindow *window, Sprite_t *s)
{
    sfRectangleShape_setSize(s->pixel, (sfVector2f){10, 10});
    sfRectangleShape_setFillColor(s->pixel, sfRed);
}

int main(int argc, char **argv)
{
    S_t st;
    Sprite_t s;
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;

    if (argc != 1)
        return 84;
    initialisation(&s);
    window = sfRenderWindow_create(mode, "My Paint", sfResize | sfClose, NULL);
    set_st(window, &s);
    sfRenderWindow_clear(window, sfColor_fromRGB(49, 54, 63));
    while (sfRenderWindow_isOpen(window))
        paint(window, &s);
    sfRenderWindow_destroy(window);
    return 0;
}

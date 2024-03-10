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
    s->background = sfRectangleShape_create();
}

void set_st(sfRenderWindow *window, Sprite_t *s)
{
    sfRectangleShape_setSize(s->pixel, (sfVector2f){10, 10});
    sfRectangleShape_setFillColor(s->pixel, sfRed);
    sfRectangleShape_setSize(s->background, (sfVector2f){940, 510});
    sfRectangleShape_setFillColor(s->background, sfWhite);
    sfRectangleShape_setPosition(s->background, (sfVector2f){250, 150});
}

int main(int argc, char **argv)
{
    S_t st;
    Sprite_t s;
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;

    if (argc != 1)
        return 84;
    window = sfRenderWindow_create(mode, "My Paint", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    initialisation(&s);
    set_st(window, &s);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawRectangleShape(window, s.background, NULL);
    while (sfRenderWindow_isOpen(window))
        paint(window, &s);
    sfRenderWindow_destroy(window);
    return 0;
}

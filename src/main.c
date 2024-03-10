/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** main.c
*/
#include "paint.h"

void initialisation(Sprite_t *s)
{
    s->brush_t = sfTexture_createFromFile("assets/brush.png", NULL);
    s->brush_s = sfSprite_create();
    s->eraser_t = sfTexture_createFromFile("assets/eraser.png", NULL);
    s->eraser_s = sfSprite_create();
    s->scale.x = 0.02;
    s->scale.y = 0.02;
}

void set_st(sfRenderWindow *window, Sprite_t *s)
{
    sfSprite_setTexture(s->brush_s, s->brush_t, sfTrue);
    sfSprite_setScale(s->brush_s, s->scale);
    sfSprite_setTexture(s->eraser_s, s->eraser_t, sfTrue);
    sfSprite_setScale(s->eraser_s, s->scale);
    sfRenderWindow_setFramerateLimit(window, 60);
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
    while (sfRenderWindow_isOpen(window))
        paint(window, &s);
    sfRenderWindow_destroy(window);
    return 0;
}

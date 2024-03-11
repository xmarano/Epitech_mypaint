/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** main.c
*/
#include "paint.h"

void initialisation(Sprite_t *s)
{
    s->image = sfImage_createFromColor(1000, 500, sfWhite);
    s->background_t = sfTexture_createFromImage(s->image, NULL);
    s->background_s = sfSprite_create();
    s->red_pen = sfRectangleShape_create();
    s->blue_pen = sfRectangleShape_create();
    s->green_pen = sfRectangleShape_create();
    s->size.x = 50;
    s->size.y = 50;
    s->pixel_size = 5;
    s->color = sfBlack;
}

void set_square(sfRectangleShape *shape, sfVector2f size,
    sfColor color, sfVector2f pos)
{
    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setFillColor(shape, color);
    sfRectangleShape_setPosition(shape, pos);
}

void set_st(sfRenderWindow *window, Sprite_t *s)
{
    sfVector2u canvas_size = sfRenderWindow_getSize(window);
    sfVector2f pos_c = {(canvas_size.x - 1000) / 2, (canvas_size.y - 500) / 2};

    sfSprite_setTexture(s->background_s, s->background_t, sfTrue);
    sfSprite_setPosition(s->background_s, pos_c);
    set_square(s->red_pen, s->size, sfRed, (sfVector2f){10, 10});
    set_square(s->blue_pen, s->size, sfBlue, (sfVector2f){70, 10});
    set_square(s->green_pen, s->size, sfGreen, (sfVector2f){130, 10});
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
    while (sfRenderWindow_isOpen(window))
        paint(window, &s);
    sfRenderWindow_destroy(window);
    return 0;
}

/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** main.c
*/
#include "paint.h"

static void initialisation(Sprite_t *s)
{
    s->image = sfImage_createFromColor(1000, 500, sfWhite);
    s->background_t = sfTexture_createFromImage(s->image, NULL);
    s->background_s = sfSprite_create();
    s->red_pen = sfRectangleShape_create();
    s->blue_pen = sfRectangleShape_create();
    s->green_pen = sfRectangleShape_create();
    s->size.x = 50;
    s->size.y = 50;
    s->pixel_size = 3;
    s->color = sfBlack;
    s->save_t = sfTexture_createFromFile("assets/save.png", NULL);
    s->save_s = sfSprite_create();
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
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f pos_c = {(window_size.x - 1000) / 2, (window_size.y - 500) / 2};
    sfVector2u save_get_size = sfTexture_getSize(s->save_t);
    sfVector2f save_size = {80.0f / save_get_size.x, 80.0f / save_get_size.y};
    sfVector2f save_pos = {window_size.x - 100, 20};

    sfSprite_setTexture(s->background_s, s->background_t, sfTrue);
    sfSprite_setPosition(s->background_s, pos_c);
    set_square(s->red_pen, s->size, sfRed, (sfVector2f){10, 10});
    set_square(s->blue_pen, s->size, sfBlue, (sfVector2f){70, 10});
    set_square(s->green_pen, s->size, sfGreen, (sfVector2f){130, 10});
    sfSprite_setTexture(s->save_s, s->save_t, sfTrue);
    sfSprite_setScale(s->save_s, save_size);
    sfSprite_setPosition(s->save_s, save_pos);
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

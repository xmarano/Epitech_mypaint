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
    s->pixel_size = 5;
}

void set_st(sfRenderWindow *window, Sprite_t *s)
{
    sfVector2u canvas_size = sfRenderWindow_getSize(window);
    sfVector2f pos_c = {(canvas_size.x - 1000) / 2, (canvas_size.y - 500) / 2};

    sfSprite_setTexture(s->background_s, s->background_t, sfTrue);
    sfSprite_setPosition(s->background_s, pos_c);
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

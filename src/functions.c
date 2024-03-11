/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** functions.c
*/
#include "paint.h"

void draw_square_pen(Sprite_t *s, int i)
{
    for (int j = s->pos.y - s->pixel_size; j < s->pos.y + s->pixel_size; j++) {
        if (i >= 220 && j >= 140 && i < 1220)
            sfImage_setPixel(s->image, i - 220, j - 140, s->color);
    }
}

void draw(sfRenderWindow *window, Sprite_t *s)
{
    for (int i = s->pos.x - s->pixel_size; i < s->pos.x + s->pixel_size; i++)
        draw_square_pen(s, i);
    sfTexture_updateFromImage(s->background_t, s->image, 0, 0);
}

void get_global_bounds(Sprite_t *s)
{
    s->gb_red = sfRectangleShape_getGlobalBounds(s->red_pen);
    s->gb_blue = sfRectangleShape_getGlobalBounds(s->blue_pen);
    s->gb_green = sfRectangleShape_getGlobalBounds(s->green_pen);
}

void draw_square_sprites(sfRenderWindow *window, Sprite_t *s)
{
    sfRenderWindow_drawSprite(window, s->background_s, NULL);
    sfRenderWindow_drawRectangleShape(window, s->red_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->blue_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->green_pen, NULL);
}

void hover(Sprite_t *s, sfRectangleShape *shape, sfFloatRect *rect)
{
    if (sfFloatRect_contains(rect, s->pos.x, s->pos.y))
        sfRectangleShape_setOutlineThickness(shape, 4);
    else
        sfRectangleShape_setOutlineThickness(shape, 0);
}

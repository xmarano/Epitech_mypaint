/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** functions.c
*/
#include "paint.h"

void draw_square_pen(Sprite_t *s, int i)
{
    sfVector2f sprite_pos = sfSprite_getPosition(s->background_s);

    for (int j = s->pos.y - s->pixel_size; j < s->pos.y + s->pixel_size; j++) {
        if (i >= sprite_pos.x && j >= sprite_pos.y && i < sprite_pos.x + 1000)
            sfImage_setPixel(s->image, i - sprite_pos.x,
            j - sprite_pos.y, s->color);
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
    sfRenderWindow_drawSprite(window, s->save_s, NULL);
    sfRenderWindow_drawRectangleShape(window, s->red_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->blue_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->green_pen, NULL);
}

void hover(Sprite_t *s, sfRectangleShape *shape, sfFloatRect *rect)
{
    if (sfFloatRect_contains(rect, s->pos.x, s->pos.y)) {
        sfRectangleShape_setOutlineThickness(shape, 4);
        sfRectangleShape_setOutlineColor(shape, sfWhite);
    }
    if (sfFloatRect_contains(rect, s->pos.x, s->pos.y)
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfRectangleShape_setOutlineThickness(shape, 4);
        sfRectangleShape_setOutlineColor(shape, sfBlack);
        s->selected = shape;
    }
    if (sfFloatRect_contains(rect, s->pos.x, s->pos.y) != 1) {
        if (shape != s->selected)
            sfRectangleShape_setOutlineThickness(shape, 0);
        else {
            sfRectangleShape_setOutlineThickness(shape, 4);
            sfRectangleShape_setOutlineColor(shape, sfBlack);
        }
    }
}

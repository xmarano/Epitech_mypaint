/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** draw.c
*/
#include "paint.h"

void draw_pixel(Sprite_t *s, int x, int y)
{
    sfVector2f s_pos = sfSprite_getPosition(s->background_s);

    if (x >= s_pos.x && y >= s_pos.y && x < s_pos.x + 1000
    && y < s_pos.y + 1000)
        sfImage_setPixel(s->image, x - s_pos.x, y - s_pos.y, s->color);
}

void draw_filled_circle2(int *err, int *x, int *y)
{
    if (*err <= 0) {
        *y += 1;
        *err += 2 * (*y) + 1;
    }
    if (*err > 0) {
        *x -= 1;
        *err -= 2 * (*x) + 1;
    }
}

void draw_filled_circle(Sprite_t *s, sfRenderWindow *window, int radius)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        for (int i = mouse_pos.x - x; i <= mouse_pos.x + x; i++) {
            draw_pixel(s, i, mouse_pos.y + y);
            draw_pixel(s, i, mouse_pos.y - y);
        }
        for (int i = mouse_pos.x - y; i <= mouse_pos.x + y; i++) {
            draw_pixel(s, i, mouse_pos.y + x);
            draw_pixel(s, i, mouse_pos.y - x);
        }
        draw_filled_circle2(&err, &x, &y);
    }
}

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
    if (s->pen == 0)
        draw_filled_circle(s, window, s->pixel_size);
    else {
        for (int i = s->pos.x - s->pixel_size; i < s->pos.x +
        s->pixel_size; i++)
            draw_square_pen(s, i);
    }
    sfTexture_updateFromImage(s->background_t, s->image, 0, 0);
}

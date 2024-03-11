/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** paint.c
*/
#include "paint.h"

void static draw2(Sprite_t *s, int i)
{
    for (int j = s->pos.y - s->pixel_size; j < s->pos.y + s->pixel_size; j++) {
        if (i >= 220 && j >= 140 && i < 1220)
            sfImage_setPixel(s->image, i - 220, j - 140, sfRed);
    }
}

void draw(sfRenderWindow *window, Sprite_t *s)
{
    for (int i = s->pos.x - s->pixel_size; i < s->pos.x + s->pixel_size; i++)
        draw2(s, i);
    sfTexture_updateFromImage(s->background_t, s->image, 0, 0);
}

void event_click(sfRenderWindow *window, sfEvent event, Sprite_t *s)
{
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        sfRenderWindow_drawSprite(window, s->background_s, NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        draw(window, s);
    if (sfKeyboard_isKeyPressed(sfKeyDown) && s->pixel_size > 1)
        s->pixel_size --;
    if (sfKeyboard_isKeyPressed(sfKeyUp) && s->pixel_size < 100)
        s->pixel_size++;
}

void paint(sfRenderWindow *window, Sprite_t *s)
{
    sfEvent event;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    s->pos = sfRenderWindow_mapPixelToCoords(window, mouse, NULL);
    sfRenderWindow_clear(window, sfColor_fromRGB(49, 54, 63));
    while (sfRenderWindow_pollEvent(window, &event))
        event_click(window, event, s);
    sfRenderWindow_drawSprite(window, s->background_s, NULL);
    sfRenderWindow_display(window);
}

/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** paint.c
*/
#include "paint.h"

void draw(sfRenderWindow *window, Sprite_t *s)
{
    return;
}

void event_click(sfRenderWindow *window, sfEvent event, Sprite_t *s)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (sfKeyboard_isKeyPressed(sfKeyE))
        s->tool = 1;
    if (sfKeyboard_isKeyPressed(sfKeyB))
        s->tool = 0;
    if (event.type == sfEvtMouseButtonPressed)
        draw(window, s);
}

void paint(sfRenderWindow *window, Sprite_t *s)
{
    sfEvent event;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f brush = sfRenderWindow_mapPixelToCoords(window, mouse, NULL);
    sfVector2f brush_pos = {(float)brush.x - 8, (float)brush.y - 8};

    sfRenderWindow_clear(window, sfColor_fromRGB(49, 54, 63));
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    if (s->tool == 0) {
        sfRenderWindow_drawSprite(window, s->brush_s, NULL);
        sfSprite_setPosition(s->brush_s, brush_pos);
    } else {
        sfRenderWindow_drawSprite(window, s->eraser_s, NULL);
        sfSprite_setPosition(s->eraser_s, brush_pos);
    }
    while (sfRenderWindow_pollEvent(window, &event))
        event_click(window, event, s);
    sfRenderWindow_display(window);
}

/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** paint.c
*/
#include "paint.h"

void draw(sfRenderWindow *window, Sprite_t *s)
{
    sfRectangleShape_setPosition(s->pixel, s->mouse_pos);
    sfRenderWindow_drawRectangleShape(window, s->pixel, NULL);
    sfRenderWindow_display(window);
}

void event_click(sfRenderWindow *window, sfEvent event, Sprite_t *s)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        sfRenderWindow_clear(window, sfColor_fromRGB(49, 54, 63));
    if (sfMouse_isButtonPressed(sfMouseLeft))
        draw(window, s);
}

void paint(sfRenderWindow *window, Sprite_t *s)
{
    sfEvent event;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f brush = sfRenderWindow_mapPixelToCoords(window, mouse, NULL);

    s->mouse_pos.x = (float)brush.x - 8;
    s->mouse_pos.y = (float)brush.y - 8;
    while (sfRenderWindow_pollEvent(window, &event))
        event_click(window, event, s);
}

/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** paint.c
*/
#include "paint.h"

void draw(sfRenderWindow *window, Sprite_t *s)
{
    if (s->mouse_pos.x > 250 && s->mouse_pos.y > 150 &&
        s->mouse_pos.x < 1180 && s->mouse_pos.y < 650) {
        sfRectangleShape_setPosition(s->pixel, s->mouse_pos);
        sfRenderWindow_drawRectangleShape(window, s->pixel, NULL);
    }
}

void event_click(sfRenderWindow *window, sfEvent event, Sprite_t *s)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        sfRenderWindow_drawRectangleShape(window, s->background, NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        draw(window, s);
    if (sfKeyboard_isKeyPressed(sfKeyR))
        sfRectangleShape_setFillColor(s->pixel, sfRed);
    if (sfKeyboard_isKeyPressed(sfKeyB))
        sfRectangleShape_setFillColor(s->pixel, sfBlue);
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
    sfRenderWindow_display(window);
}

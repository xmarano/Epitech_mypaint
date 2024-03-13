/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** functions_buttons.c
*/
#include "paint.h"

void draw_rect_buttons(sfRenderWindow *window, Sprite_t *s)
{
    sfRenderWindow_drawRectangleShape(window, s->file, NULL);
    sfRenderWindow_drawRectangleShape(window, s->edition, NULL);
    sfRenderWindow_drawRectangleShape(window, s->help, NULL);
    sfRenderWindow_drawText(window, s->file_txt, NULL);
    sfRenderWindow_drawText(window, s->edition_txt, NULL);
    sfRenderWindow_drawText(window, s->help_txt, NULL);
}

sfRectangleShape *set_button(Sprite_t *s, sfVector2f pos)
{
    sfVector2f size = {90, 30};
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setFillColor(shape, s->grey);
    sfRectangleShape_setPosition(shape, pos);
    return shape;
}

sfText *set_text(Sprite_t *s, sfVector2f pos, char *str)
{
    sfVector2f size = {90, 30};
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/text.ttf");

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    sfText_setColor(text, sfBlack);
    sfText_setString(text, str);
    sfText_setPosition(text, pos);
    return text;
}

void hover_button(Sprite_t *s, sfRectangleShape *shape, sfFloatRect *rect)
{
    if (sfFloatRect_contains(rect, s->pos.x, s->pos.y)) {
        sfRectangleShape_setOutlineThickness(shape, 4);
        sfRectangleShape_setOutlineColor(shape, sfWhite);
    }
    if (sfFloatRect_contains(rect, s->pos.x, s->pos.y)
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfRectangleShape_setOutlineThickness(shape, 4);
        sfRectangleShape_setOutlineColor(shape, s->grey);
        s->current = shape;
    }
    if (sfFloatRect_contains(rect, s->pos.x, s->pos.y) != 1) {
        if (shape != s->current)
            sfRectangleShape_setOutlineThickness(shape, 0);
        else {
            sfRectangleShape_setOutlineThickness(shape, 4);
            sfRectangleShape_setOutlineColor(shape, sfBlack);
        }
    }
}

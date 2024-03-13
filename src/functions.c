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

void draw_square_sprites(sfRenderWindow *window, Sprite_t *s)
{
    sfRenderWindow_drawSprite(window, s->background_s, NULL);
    sfRenderWindow_drawSprite(window, s->save_s, NULL);
    sfRenderWindow_drawRectangleShape(window, s->red_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->blue_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->green_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->cyan_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->yellow_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->magenta_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->protanopie_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->orange_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->darkblue_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->file, NULL);
    sfRenderWindow_drawRectangleShape(window, s->edition, NULL);
    sfRenderWindow_drawRectangleShape(window, s->help, NULL);
    sfRenderWindow_drawText(window, s->file_txt, NULL);
    sfRenderWindow_drawText(window, s->edition_txt, NULL);
    sfRenderWindow_drawText(window, s->help_txt, NULL);
}

sfRectangleShape *set_palette(Sprite_t *s, sfVector2f pos, sfColor color)
{
    sfVector2f size = {40, 40};
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setFillColor(shape, color);
    sfRectangleShape_setPosition(shape, pos);
    return shape;
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

void hover(Sprite_t *s, sfRectangleShape *shape, sfFloatRect *rect)
{
    if (sfFloatRect_contains(rect, s->pos.x, s->pos.y)) {
        sfRectangleShape_setOutlineThickness(shape, 4);
        sfRectangleShape_setOutlineColor(shape, sfWhite);
    }
    if (sfFloatRect_contains(rect, s->pos.x, s->pos.y)
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfRectangleShape_setOutlineThickness(shape, 4);
        sfRectangleShape_setOutlineColor(shape, s->grey);
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
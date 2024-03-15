/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** functions_buttons.c
*/
#include "paint.h"

static void draw_save_choice(sfRenderWindow *window, Sprite_t *s)
{
    if (s->menu1 == 1 && s->check_save == 1) {
        sfRenderWindow_drawRectangleShape(window, s->jpg, NULL);
        sfRenderWindow_drawRectangleShape(window, s->png, NULL);
        sfRenderWindow_drawRectangleShape(window, s->bmp, NULL);
        sfRenderWindow_drawText(window, s->jpg_txt, NULL);
        sfRenderWindow_drawText(window, s->png_txt, NULL);
        sfRenderWindow_drawText(window, s->bmp_txt, NULL);
    }
}

static void draw_submenu(sfRenderWindow *window, Sprite_t *s)
{
    if (s->menu1 == 1) {
        sfRenderWindow_drawRectangleShape(window, s->new_file, NULL);
        sfRenderWindow_drawRectangleShape(window, s->open, NULL);
        sfRenderWindow_drawRectangleShape(window, s->save, NULL);
        sfRenderWindow_drawText(window, s->new_file_txt, NULL);
        sfRenderWindow_drawText(window, s->open_txt, NULL);
        sfRenderWindow_drawText(window, s->save_txt, NULL);
    }
    if (s->menu2 == 1) {
        sfRenderWindow_drawRectangleShape(window, s->plus, NULL);
        sfRenderWindow_drawRectangleShape(window, s->moins, NULL);
        sfRenderWindow_drawRectangleShape(window, s->eraser, NULL);
        sfRenderWindow_drawRectangleShape(window, s->square, NULL);
        sfRenderWindow_drawRectangleShape(window, s->circle, NULL);
        sfRenderWindow_drawText(window, s->plus_txt, NULL);
        sfRenderWindow_drawText(window, s->moins_txt, NULL);
        sfRenderWindow_drawText(window, s->eraser_txt, NULL);
        sfRenderWindow_drawText(window, s->square_txt, NULL);
        sfRenderWindow_drawText(window, s->circle_txt, NULL);
    }
}

void draw_rect_buttons(sfRenderWindow *window, Sprite_t *s)
{
    sfRenderWindow_drawRectangleShape(window, s->file, NULL);
    sfRenderWindow_drawRectangleShape(window, s->edition, NULL);
    sfRenderWindow_drawRectangleShape(window, s->help, NULL);
    sfRenderWindow_drawText(window, s->file_txt, NULL);
    sfRenderWindow_drawText(window, s->edition_txt, NULL);
    sfRenderWindow_drawText(window, s->help_txt, NULL);
    draw_submenu(window, s);
    draw_save_choice(window, s);
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

static void check_menu3(sfRenderWindow *window, Sprite_t *s)
{
    if (sfFloatRect_contains(&s->gb_help, s->pos.x, s->pos.y)) {
        if (s->menu3 == 1) {
            s->menu3 = 0;
            return;
        }
        s->menu1 = 0;
        s->menu2 = 0;
        s->menu3 = 1;
        s->check_save = 0;
    }
    if (sfFloatRect_contains(&s->gb_save, s->pos.x, s->pos.y))
        s->check_save = 1;
}

static void check_menu2(sfRenderWindow *window, Sprite_t *s)
{
    if (sfFloatRect_contains(&s->gb_edition, s->pos.x, s->pos.y)) {
        if (s->menu2 == 1) {
            s->menu2 = 0;
            return;
        }
        s->menu1 = 0;
        s->menu2 = 1;
        s->menu3 = 0;
        s->check_save = 0;
    }
    check_menu3(window, s);
}

void check_menu(sfRenderWindow *window, Sprite_t *s)
{
    if (sfFloatRect_contains(&s->gb_file, s->pos.x, s->pos.y)) {
        if (s->menu1 == 1) {
            s->menu1 = 0;
            return;
        }
        s->menu1 = 1;
        s->menu2 = 0;
        s->menu3 = 0;
        s->check_save = 0;
    }
    check_menu2(window, s);
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

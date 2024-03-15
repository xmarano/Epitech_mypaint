/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** functions.c
*/
#include "paint.h"

void help_click(sfRenderWindow *window, Sprite_t *s)
{
    sfFont *font = sfFont_createFromFile("assets/text.ttf");
    sfVector2f size = {800, 190};
    sfVector2f pos_rect = {206, 50};
    sfVector2f pos_text = {215, 60};
    char *str = "Bienvenue sur le paint, vous pouvez utiliser toutes les ";

    str = my_strcat(str, "differentes couleurs et formes\n\n\n Enregistrez v");
    str = my_strcat(str, "os magnifiques oeuvres d'art en .png .jpg ou .bmp");
    str = my_strcat(str, "\n\n Importez n'importe quel images XD avec 'open'");
    str = my_strcat(str, "\n\n Plutot formes carre ou rond ;)?");
    sfRectangleShape_setSize(s->help_info, size);
    sfRectangleShape_setFillColor(s->help_info, s->sky_blue);
    sfRectangleShape_setPosition(s->help_info, pos_rect);
    sfText_setFont(s->txt, font);
    sfText_setCharacterSize(s->txt, 15);
    sfText_setColor(s->txt, sfBlack);
    sfText_setString(s->txt, str);
    sfText_setPosition(s->txt, pos_text);
}

void edition_click(sfRenderWindow *window, Sprite_t *s)
{
    if (s->menu2 == 1) {
        if (sfFloatRect_contains(&s->gb_plus, s->pos.x, s->pos.y)
        && s->pixel_size < 75)
            s->pixel_size = s->pixel_size + 2;
        if (sfFloatRect_contains(&s->gb_moins, s->pos.x, s->pos.y)
        && s->pixel_size > 1)
            s->pixel_size = s->pixel_size - 2;
        if (sfFloatRect_contains(&s->gb_eraserb, s->pos.x, s->pos.y))
            s->color = sfTransparent;
        if (sfFloatRect_contains(&s->gb_square, s->pos.x, s->pos.y)) {
            s->pen = 1;
            s->color = sfBlack;
        }
        if (sfFloatRect_contains(&s->gb_circle, s->pos.x, s->pos.y)) {
            s->pen = 0;
            s->color = sfBlack;
        }
    }
}

void draw_rect_colors(sfRenderWindow *window, Sprite_t *s)
{
    sfRenderWindow_drawSprite(window, s->white_back_s, NULL);
    sfRenderWindow_drawSprite(window, s->background_s, NULL);
    sfRenderWindow_drawSprite(window, s->eraser_s, NULL);
    sfRenderWindow_drawRectangleShape(window, s->red_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->blue_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->green_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->cyan_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->yellow_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->magenta_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->protanopie_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->orange_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->black_pen, NULL);
    sfRenderWindow_drawRectangleShape(window, s->transparent, NULL);
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

void hover_color(Sprite_t *s, sfRectangleShape *shape, sfFloatRect *rect)
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

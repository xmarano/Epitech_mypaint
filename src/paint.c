/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** paint.c
*/
#include "paint.h"

void static get_global_bounds(Sprite_t *s)
{
    s->gb_red = sfRectangleShape_getGlobalBounds(s->red_pen);
    s->gb_blue = sfRectangleShape_getGlobalBounds(s->blue_pen);
    s->gb_green = sfRectangleShape_getGlobalBounds(s->green_pen);
    s->gb_cyan = sfRectangleShape_getGlobalBounds(s->cyan_pen);
    s->gb_magenta = sfRectangleShape_getGlobalBounds(s->magenta_pen);
    s->gb_yellow = sfRectangleShape_getGlobalBounds(s->yellow_pen);
    s->gb_orange = sfRectangleShape_getGlobalBounds(s->orange_pen);
    s->gb_protanopie = sfRectangleShape_getGlobalBounds(s->protanopie_pen);
    s->gb_black = sfRectangleShape_getGlobalBounds(s->black_pen);
    s->gb_eraser = sfSprite_getGlobalBounds(s->eraser_s);
    s->gb_file = sfRectangleShape_getGlobalBounds(s->file);
    s->gb_edition = sfRectangleShape_getGlobalBounds(s->edition);
    s->gb_help = sfRectangleShape_getGlobalBounds(s->help);
    s->gb_new_file = sfRectangleShape_getGlobalBounds(s->new_file);
    s->gb_open = sfRectangleShape_getGlobalBounds(s->open);
    s->gb_save = sfRectangleShape_getGlobalBounds(s->save);
    s->gb_jpg = sfRectangleShape_getGlobalBounds(s->jpg);
    s->gb_png = sfRectangleShape_getGlobalBounds(s->png);
    s->gb_bmp = sfRectangleShape_getGlobalBounds(s->bmp);
}

void static check_color(sfRenderWindow *window, Sprite_t *s)
{
    if (sfFloatRect_contains(&s->gb_red, s->pos.x, s->pos.y))
        s->color = sfRed;
    if (sfFloatRect_contains(&s->gb_blue, s->pos.x, s->pos.y))
        s->color = sfBlue;
    if (sfFloatRect_contains(&s->gb_green, s->pos.x, s->pos.y))
        s->color = sfGreen;
    if (sfFloatRect_contains(&s->gb_cyan, s->pos.x, s->pos.y))
        s->color = sfCyan;
    if (sfFloatRect_contains(&s->gb_magenta, s->pos.x, s->pos.y))
        s->color = sfMagenta;
    if (sfFloatRect_contains(&s->gb_yellow, s->pos.x, s->pos.y))
        s->color = sfYellow;
    if (sfFloatRect_contains(&s->gb_orange, s->pos.x, s->pos.y))
        s->color = sfColor_fromRGB(255, 149, 0);
    if (sfFloatRect_contains(&s->gb_protanopie, s->pos.x, s->pos.y))
        s->color = sfColor_fromRGB(0, 204, 153);
    if (sfFloatRect_contains(&s->gb_black, s->pos.x, s->pos.y))
        s->color = sfBlack;
    if (sfFloatRect_contains(&s->gb_eraser, s->pos.x, s->pos.y))
        s->color = sfWhite;
}

void event_click(sfRenderWindow *window, sfEvent event, Sprite_t *s)
{
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        sfRenderWindow_drawSprite(window, s->background_s, NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        draw(window, s);
        check_color(window, s);
        check_menu(window, s);
        //save_click(window, s);
        open_click(window, s);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && s->pixel_size > 1)
        s->pixel_size --;
    if (sfKeyboard_isKeyPressed(sfKeyUp) && s->pixel_size < 100)
        s->pixel_size++;
}

void check_hover_color(Sprite_t *s)
{
    hover_color(s, s->red_pen, &s->gb_red);
    hover_color(s, s->blue_pen, &s->gb_blue);
    hover_color(s, s->green_pen, &s->gb_green);
    hover_color(s, s->cyan_pen, &s->gb_cyan);
    hover_color(s, s->yellow_pen, &s->gb_yellow);
    hover_color(s, s->magenta_pen, &s->gb_magenta);
    hover_color(s, s->orange_pen, &s->gb_orange);
    hover_color(s, s->protanopie_pen, &s->gb_protanopie);
    hover_color(s, s->black_pen, &s->gb_black);
}

void check_hover_button(Sprite_t *s)
{
    hover_button(s, s->file, &s->gb_file);
    hover_button(s, s->edition, &s->gb_edition);
    hover_button(s, s->help, &s->gb_help);
    hover_button(s, s->new_file, &s->gb_new_file);
    hover_button(s, s->open, &s->gb_open);
    hover_button(s, s->save, &s->gb_save);
    hover_button(s, s->jpg, &s->gb_jpg);
    hover_button(s, s->png, &s->gb_png);
    hover_button(s, s->bmp, &s->gb_bmp);
}

void paint(sfRenderWindow *window, Sprite_t *s)
{
    sfEvent event;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    s->pos = sfRenderWindow_mapPixelToCoords(window, mouse, NULL);
    sfRenderWindow_clear(window, s->light_grey);
    get_global_bounds(s);
    check_hover_color(s);
    check_hover_button(s);
    while (sfRenderWindow_pollEvent(window, &event))
        event_click(window, event, s);
    draw_rect_colors(window, s);
    draw_rect_buttons(window, s);
    sfRenderWindow_display(window);
}

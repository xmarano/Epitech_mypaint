/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** paint.c
*/
#include "paint.h"

void get_global_bounds(Sprite_t *s)
{
    s->gb_red = sfRectangleShape_getGlobalBounds(s->red_pen);
    s->gb_blue = sfRectangleShape_getGlobalBounds(s->blue_pen);
    s->gb_green = sfRectangleShape_getGlobalBounds(s->green_pen);
    s->gb_cyan = sfRectangleShape_getGlobalBounds(s->cyan_pen);
    s->gb_magenta = sfRectangleShape_getGlobalBounds(s->magenta_pen);
    s->gb_yellow = sfRectangleShape_getGlobalBounds(s->yellow_pen);
    s->gb_orange = sfRectangleShape_getGlobalBounds(s->orange_pen);
    s->gb_protanopie = sfRectangleShape_getGlobalBounds(s->protanopie_pen);
    s->gb_darkblue = sfRectangleShape_getGlobalBounds(s->darkblue_pen);
}

void check_draw(sfRenderWindow *window, Sprite_t *s)
{
    draw(window, s);
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
    if (sfFloatRect_contains(&s->gb_darkblue, s->pos.x, s->pos.y))
        s->color = sfColor_fromRGB(102, 0, 102);
}

void save_click(sfRenderWindow *window, Sprite_t *s)
{
    sfFloatRect save_bounds = sfSprite_getGlobalBounds(s->save_s);
    sfTexture* texture;
    sfImage* image;

    if (sfFloatRect_contains(&save_bounds, s->pos.x, s->pos.y)) {
        texture = sfTexture_createFromImage(s->image, NULL);
        image = sfTexture_copyToImage(texture);
        sfImage_saveToFile(image, "draw.jpg");
        sfImage_destroy(image);
        sfTexture_destroy(texture);
    }
}

void event_click(sfRenderWindow *window, sfEvent event, Sprite_t *s)
{
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        sfRenderWindow_drawSprite(window, s->background_s, NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        check_draw(window, s);
        save_click(window, s);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && s->pixel_size > 1)
        s->pixel_size --;
    if (sfKeyboard_isKeyPressed(sfKeyUp) && s->pixel_size < 100)
        s->pixel_size++;
}

void check_hover(Sprite_t *s)
{
    hover(s, s->red_pen, &s->gb_red);
    hover(s, s->blue_pen, &s->gb_blue);
    hover(s, s->green_pen, &s->gb_green);
    hover(s, s->cyan_pen, &s->gb_cyan);
    hover(s, s->yellow_pen, &s->gb_yellow);
    hover(s, s->magenta_pen, &s->gb_magenta);
    hover(s, s->orange_pen, &s->gb_orange);
    hover(s, s->protanopie_pen, &s->gb_protanopie);
    hover(s, s->darkblue_pen, &s->gb_darkblue);
}

void paint(sfRenderWindow *window, Sprite_t *s)
{
    sfEvent event;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    s->pos = sfRenderWindow_mapPixelToCoords(window, mouse, NULL);
    sfRenderWindow_clear(window, s->light_grey);
    get_global_bounds(s);
    check_hover(s);
    while (sfRenderWindow_pollEvent(window, &event))
        event_click(window, event, s);
    draw_square_sprites(window, s);
    sfRenderWindow_display(window);
}

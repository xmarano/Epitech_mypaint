/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** paint.c
*/
#include "paint.h"

void check_draw(sfRenderWindow *window, Sprite_t *s)
{
    draw(window, s);
    if (sfFloatRect_contains(&s->gb_red, s->pos.x, s->pos.y))
        s->color = sfRed;
    if (sfFloatRect_contains(&s->gb_blue, s->pos.x, s->pos.y))
        s->color = sfBlue;
    if (sfFloatRect_contains(&s->gb_green, s->pos.x, s->pos.y))
        s->color = sfGreen;
}

void save_click(sfRenderWindow *window, Sprite_t *s)
{
    sfFloatRect save_bounds = sfSprite_getGlobalBounds(s->save_s);
    sfTexture* texture;
    sfImage* image;

    if (sfFloatRect_contains(&save_bounds, s->pos.x, s->pos.y)) {
        texture = sfTexture_createFromImage(s->image, NULL);
        image = sfTexture_copyToImage(texture);
        sfImage_saveToFile(image, "draw.png");
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
}

void paint(sfRenderWindow *window, Sprite_t *s)
{
    sfEvent event;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    s->pos = sfRenderWindow_mapPixelToCoords(window, mouse, NULL);
    sfRenderWindow_clear(window, sfColor_fromRGB(49, 54, 63));
    get_global_bounds(s);
    check_hover(s);
    while (sfRenderWindow_pollEvent(window, &event))
        event_click(window, event, s);
    draw_square_sprites(window, s);
    sfRenderWindow_display(window);
}

/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** main.c
*/
#include "paint.h"

static void initialisation(Sprite_t *s)
{
    s->image = sfImage_createFromColor(1000, 500, sfWhite);
    s->background_t = sfTexture_createFromImage(s->image, NULL);
    s->background_s = sfSprite_create();
    s->pixel_size = 3;
    s->color = sfBlack;
    s->save_t = sfTexture_createFromFile("assets/save.png", NULL);
    s->save_s = sfSprite_create();
    s->light_grey = sfColor_fromRGB(140, 140, 140);
    s->grey = sfColor_fromRGB(109, 112, 124);
    s->orange = sfColor_fromRGB(255, 149, 0);
    s->protanopie = sfColor_fromRGB(0, 204, 153);
}

void set_st(sfRenderWindow *window, Sprite_t *s)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f pos_c = {(window_size.x - 1000) / 2, (window_size.y - 500) / 2};
    sfVector2u save_get_size = sfTexture_getSize(s->save_t);
    sfVector2f save_size = {80.0f / save_get_size.x, 80.0f / save_get_size.y};
    sfVector2f save_pos = {window_size.x - 100, 20};

    sfSprite_setTexture(s->background_s, s->background_t, sfTrue);
    sfSprite_setPosition(s->background_s, pos_c);
    sfSprite_setTexture(s->save_s, s->save_t, sfTrue);
    sfSprite_setScale(s->save_s, save_size);
    sfSprite_setPosition(s->save_s, save_pos);
}

void palette(sfRenderWindow *window, Sprite_t *s)
{
    s->red_pen = set_palette(s, (sfVector2f){55, 270}, sfRed);
    s->blue_pen = set_palette(s, (sfVector2f){115, 270}, sfBlue);
    s->green_pen = set_palette(s, (sfVector2f){55, 335}, sfGreen);
    s->magenta_pen = set_palette(s, (sfVector2f){115, 335}, sfMagenta);
    s->yellow_pen = set_palette(s, (sfVector2f){55, 400}, sfYellow);
    s->cyan_pen = set_palette(s, (sfVector2f){115, 400}, sfCyan);
    s->orange_pen = set_palette(s, (sfVector2f){55, 465}, s->orange);
    s->protanopie_pen = set_palette(s, (sfVector2f){115, 465}, s->protanopie);
    s->black_pen = set_palette(s, (sfVector2f){55, 530}, sfBlack);
}

void button(sfRenderWindow *window, Sprite_t *s)
{
    s->file = set_button(s, (sfVector2f){10, 10});
    s->edition = set_button(s, (sfVector2f){110, 10});
    s->help = set_button(s, (sfVector2f){210, 10});
    return;
}

void text(sfRenderWindow *window, Sprite_t *s)
{
    s->file_txt = set_text(s, (sfVector2f){30, 12}, "File");
    s->edition_txt = set_text(s, (sfVector2f){120, 12}, "Option");
    s->help_txt = set_text(s, (sfVector2f){230, 12}, "Help");
    return;
}

int main(int argc, char **argv)
{
    S_t st;
    Sprite_t s;
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;

    if (argc != 1)
        return 84;
    window = sfRenderWindow_create(mode, "My Paint", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    initialisation(&s);
    set_st(window, &s);
    palette(window, &s);
    button(window, &s);
    text(window, &s);
    while (sfRenderWindow_isOpen(window))
        paint(window, &s);
    sfRenderWindow_destroy(window);
    return 0;
}

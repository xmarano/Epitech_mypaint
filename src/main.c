/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** main.c
*/
#include "paint.h"

static void initialisation(Sprite_t *s)
{
    s->white_back = sfImage_createFromColor(1000, 500, sfWhite);
    s->white_back_t = sfTexture_createFromImage(s->white_back, NULL);
    s->white_back_s = sfSprite_create();
    s->image = sfImage_createFromColor(1000, 500, sfTransparent);
    s->background_t = sfTexture_createFromImage(s->image, NULL);
    s->background_s = sfSprite_create();
    s->pixel_size = 3;
    s->color = sfBlack;
    s->eraser_t = sfTexture_createFromFile("assets/eraser.png", NULL);
    s->eraser_s = sfSprite_create();
    s->light_grey = sfColor_fromRGB(140, 140, 140);
    s->grey = sfColor_fromRGB(109, 112, 124);
    s->orange = sfColor_fromRGB(255, 149, 0);
    s->protanopie = sfColor_fromRGB(0, 204, 153);
    s->menu1 = 0;
    s->menu2 = 0;
    s->menu3 = 0;
    s->check_save = 0;
    s->pen = 0;
}

void set_st(sfRenderWindow *window, Sprite_t *s)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f pos_c = {(window_size.x - 1000) / 2, (window_size.y - 500) / 2};
    sfVector2u eraser_get = sfTexture_getSize(s->eraser_t);
    sfVector2f eraser_size = {42.0f / eraser_get.x, 40.0f / eraser_get.y};
    sfVector2f eraser_pos = {115, 530};

    sfSprite_setTexture(s->white_back_s, s->white_back_t, sfTrue);
    sfSprite_setPosition(s->white_back_s, pos_c);
    sfSprite_setTexture(s->background_s, s->background_t, sfTrue);
    sfSprite_setPosition(s->background_s, pos_c);
    sfSprite_setTexture(s->eraser_s, s->eraser_t, sfTrue);
    sfSprite_setScale(s->eraser_s, eraser_size);
    sfSprite_setPosition(s->eraser_s, eraser_pos);
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
    s->transparent = set_palette(s, (sfVector2f){115, 530}, sfWhite);
}

void button(sfRenderWindow *window, Sprite_t *s)
{
    s->file = set_button(s, (sfVector2f){10, 10});
    s->edition = set_button(s, (sfVector2f){110, 10});
    s->help = set_button(s, (sfVector2f){210, 10});
    s->new_file = set_button(s, (sfVector2f){10, 50});
    s->open = set_button(s, (sfVector2f){10, 90});
    s->save = set_button(s, (sfVector2f){10, 130});
    s->jpg = set_button(s, (sfVector2f){110, 130});
    s->png = set_button(s, (sfVector2f){110, 170});
    s->bmp = set_button(s, (sfVector2f){110, 210});
    s->plus = set_button(s, (sfVector2f){110, 50});
    s->moins = set_button(s, (sfVector2f){110, 90});
    s->eraser = set_button(s, (sfVector2f){110, 130});
    s->square = set_button(s, (sfVector2f){110, 170});
    s->circle = set_button(s, (sfVector2f){110, 210});
    return;
}

void text(sfRenderWindow *window, Sprite_t *s)
{
    s->file_txt = set_text(s, (sfVector2f){30, 12}, "File");
    s->edition_txt = set_text(s, (sfVector2f){113, 12}, "Edition");
    s->help_txt = set_text(s, (sfVector2f){230, 12}, "Help");
    s->new_file_txt = set_text(s, (sfVector2f){20, 52}, "New...");
    s->open_txt = set_text(s, (sfVector2f){15, 92}, "Open...");
    s->save_txt = set_text(s, (sfVector2f){15, 132}, "Save...");
    s->jpg_txt = set_text(s, (sfVector2f){115, 132}, ".jpg");
    s->png_txt = set_text(s, (sfVector2f){115, 172}, ".png");
    s->bmp_txt = set_text(s, (sfVector2f){115, 212}, ".bmp");
    s->plus_txt = set_text(s, (sfVector2f){148, 52}, "+");
    s->moins_txt = set_text(s, (sfVector2f){147, 92}, "-");
    s->eraser_txt = set_text(s, (sfVector2f){119, 132}, "eraser");
    s->square_txt = set_text(s, (sfVector2f){119, 172}, "square");
    s->circle_txt = set_text(s, (sfVector2f){119, 212}, "circle");
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

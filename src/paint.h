/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** paint.h
*/
#include "my.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#ifndef PAINT_H
    #define PAINT_H

typedef struct Sprite {
    sfImage *white_back;
    sfTexture *white_back_t;
    sfSprite *white_back_s;
    sfImage *image;
    sfTexture *background_t;
    sfSprite *background_s;
    sfVector2f pos;
    sfColor color;
    int pixel_size;
    sfVector2f size;
    sfRectangleShape *selected;
    sfRectangleShape *hover;
    sfSprite *eraser_s;
    sfTexture *eraser_t;
    sfFloatRect gb_eraser;
    sfRectangleShape *red_pen;
    sfRectangleShape *blue_pen;
    sfRectangleShape *green_pen;
    sfRectangleShape *yellow_pen;
    sfRectangleShape *magenta_pen;
    sfRectangleShape *cyan_pen;
    sfRectangleShape *orange_pen;
    sfRectangleShape *protanopie_pen;
    sfRectangleShape *black_pen;
    sfRectangleShape *transparent;
    sfFloatRect gb_red;
    sfFloatRect gb_blue;
    sfFloatRect gb_green;
    sfFloatRect gb_yellow;
    sfFloatRect gb_magenta;
    sfFloatRect gb_cyan;
    sfFloatRect gb_orange;
    sfFloatRect gb_protanopie;
    sfFloatRect gb_black;
    sfFloatRect gb_transparent;
    sfColor grey;
    sfColor light_grey;
    sfColor orange;
    sfColor protanopie;
    sfRectangleShape *file;
    sfRectangleShape *edition;
    sfRectangleShape *help;
    sfRectangleShape *new_file;
    sfRectangleShape *open;
    sfRectangleShape *save;
    int check_save;
    sfRectangleShape *jpg;
    sfRectangleShape *png;
    sfRectangleShape *bmp;
    sfRectangleShape *plus;
    sfRectangleShape *moins;
    sfRectangleShape *eraser;
    sfRectangleShape *square;
    sfRectangleShape *circle;
    sfText *file_txt;
    sfText *edition_txt;
    sfText *help_txt;
    sfText *new_file_txt;
    sfText *open_txt;
    sfText *save_txt;
    sfText *jpg_txt;
    sfText *png_txt;
    sfText *bmp_txt;
    sfText *plus_txt;
    sfText *moins_txt;
    sfText *eraser_txt;
    sfText *square_txt;
    sfText *circle_txt;
    sfFloatRect gb_file;
    sfFloatRect gb_edition;
    sfFloatRect gb_help;
    sfFloatRect gb_new_file;
    sfFloatRect gb_open;
    sfFloatRect gb_save;
    sfFloatRect gb_jpg;
    sfFloatRect gb_png;
    sfFloatRect gb_bmp;
    sfFloatRect gb_plus;
    sfFloatRect gb_moins;
    sfFloatRect gb_eraserb;
    sfFloatRect gb_square;
    sfFloatRect gb_circle;
    sfRectangleShape *current;
    int menu1;
    int menu2;
    int menu3;
    char *filename;
    int pen;
} Sprite_t;

typedef struct St {
} S_t;

void draw_square_pen(Sprite_t *s, int i);
void draw(sfRenderWindow *window, Sprite_t *s);
void paint(sfRenderWindow *window, Sprite_t *s);
void draw_rect_colors(sfRenderWindow *window, Sprite_t *s);
void draw_rect_buttons(sfRenderWindow *window, Sprite_t *s);
void hover_color(Sprite_t *s, sfRectangleShape *shape, sfFloatRect *rect);
void hover_button(Sprite_t *s, sfRectangleShape *shape, sfFloatRect *rect);
sfRectangleShape *set_palette(Sprite_t *s, sfVector2f pos, sfColor color);
sfRectangleShape *set_button(Sprite_t *s, sfVector2f pos);
sfText *set_text(Sprite_t *s, sfVector2f pos, char *str);
void check_menu(sfRenderWindow *window, Sprite_t *s);
void check_submenu(sfRenderWindow *window, Sprite_t *s);
void save_click(sfRenderWindow *window, Sprite_t *s);
void open_click(sfRenderWindow *window, Sprite_t *s);
void name_file(sfRenderWindow *window, Sprite_t *s);
void new_click(sfRenderWindow *window, Sprite_t *s);
void edition_click(sfRenderWindow *window, Sprite_t *s);
#endif

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
    sfImage *image;
    sfTexture *background_t;
    sfSprite *background_s;
    sfVector2f pos;
    sfColor color;
    int pixel_size;
    sfVector2f size;
    sfRectangleShape *selected;
    sfRectangleShape *hover;
    sfSprite *save_s;
    sfTexture *save_t;
    sfRectangleShape *file;
    sfRectangleShape *edition;
    sfRectangleShape *help;
    sfRectangleShape *red_pen;
    sfRectangleShape *blue_pen;
    sfRectangleShape *green_pen;
    sfRectangleShape *yellow_pen;
    sfRectangleShape *magenta_pen;
    sfRectangleShape *cyan_pen;
    sfRectangleShape *orange_pen;
    sfRectangleShape *protanopie_pen;
    sfRectangleShape *darkblue_pen;
    sfFloatRect gb_red;
    sfFloatRect gb_blue;
    sfFloatRect gb_green;
    sfFloatRect gb_yellow;
    sfFloatRect gb_magenta;
    sfFloatRect gb_cyan;
    sfFloatRect gb_orange;
    sfFloatRect gb_protanopie;
    sfFloatRect gb_darkblue;
    sfColor grey;
    sfColor light_grey;
    sfColor orange;
    sfColor protanopie;
    sfColor darkblue;
    sfText *file_txt;
    sfText *edition_txt;
    sfText *help_txt;
    sfFloatRect gb_file;
    sfFloatRect gb_edition;
    sfFloatRect gb_help;
    sfRectangleShape *current;
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
#endif

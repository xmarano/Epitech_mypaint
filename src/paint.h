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
    sfRectangleShape *red_pen;
    sfFloatRect gb_red;
    sfRectangleShape *blue_pen;
    sfFloatRect gb_blue;
    sfRectangleShape *green_pen;
    sfFloatRect gb_green;
    sfVector2f size;
    sfRectangleShape *selected;
    sfRectangleShape *hover;
    sfSprite *save_s;
    sfTexture *save_t;
} Sprite_t;

typedef struct St {
} S_t;

void get_global_bounds(Sprite_t *s);
void draw_square_pen(Sprite_t *s, int i);
void draw(sfRenderWindow *window, Sprite_t *s);
void paint(sfRenderWindow *window, Sprite_t *s);
void draw_square_sprites(sfRenderWindow *window, Sprite_t *s);
void hover(Sprite_t *s, sfRectangleShape *shape, sfFloatRect *rect);
#endif

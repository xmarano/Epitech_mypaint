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
    sfImage* image;
    sfTexture* background_t;
    sfSprite* background_s;
    sfVector2f pos;
    sfColor color;
    int pixel_size;
} Sprite_t;

typedef struct St {
} S_t;

void paint(sfRenderWindow *window, Sprite_t *s);
#endif

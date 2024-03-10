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
    sfTexture *brush_t;
    sfSprite *brush_s;
    sfTexture *eraser_t;
    sfSprite *eraser_s;
    sfVector2f scale;
    int tool;
} Sprite_t;

typedef struct St {
} S_t;

void paint(sfRenderWindow *window, Sprite_t *s);
#endif

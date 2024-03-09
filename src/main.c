/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** main.c
*/
#include "paint.h"

void event(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void paint(S_t *s)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "My Paint", sfResize | sfClose, NULL);
    while (sfRenderWindow_isOpen(window)) {
        event(window);
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}

int main(int argc, char **argv)
{
    S_t s;

    if (argc != 1)
        return 84;
    paint(&s);
    return 0;
}

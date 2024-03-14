/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** save.c
*/
#include "paint.h"

sfSprite* image_resize(sfImage *image)
{
    sfVector2u image_size = sfImage_getSize(image);
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f origin = {0, image_size.y};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setOrigin(sprite, origin);
    sfSprite_setScale(sprite,
    (sfVector2f){1000.0f / image_size.x, -500.0f / image_size.y});
    return sprite;
}

void open_click(sfRenderWindow *window, Sprite_t *s)
{
    sfImage *new_image;
    sfSprite *sprite;
    const sfTexture *new_texture;
    sfRenderTexture *renderTexture;

    if (s->menu1 % 2 != 0 &&
    sfFloatRect_contains(&s->gb_open, s->pos.x, s->pos.y)) {
        my_printf("\x1b[38;5;208m" "Name of the file to open : " "\x1b[0m");
        name_file(window, s);
        new_image = sfImage_createFromFile(s->filename);
        if (!new_image)
            return;
        sprite = image_resize(new_image);
        renderTexture = sfRenderTexture_create(1000, 500, sfFalse);
        sfRenderTexture_drawSprite(renderTexture, sprite, NULL);
        new_texture = sfRenderTexture_getTexture(renderTexture);
        new_image = sfTexture_copyToImage(new_texture);
        s->image = new_image;
        my_printf("\x1b[38;5;46m" "Your file has been opened\n\n" "\x1b[0m");
    }
}

static void save_image(sfRenderWindow *window, Sprite_t *s, char *str)
{
    sfTexture* texture;
    sfImage* image;
    char *f = malloc(my_strlen(s->filename) + my_strlen(str) * sizeof(char));

    f = my_strcat(f, s->filename);
    f = my_strcat(f, str);
    texture = sfTexture_createFromImage(s->image, NULL);
    image = sfTexture_copyToImage(texture);
    sfImage_saveToFile(image, f);
    sfImage_destroy(image);
    sfTexture_destroy(texture);
    my_printf("\x1b[38;5;46m" "-----------------------------\n");
    my_printf("|your file has been saved ✅|\n");
    my_printf("-----------------------------\n\n" "\x1b[0m");
}

void name_file(sfRenderWindow *window, Sprite_t *s)
{
    size_t input_size = 0;
    char *input = malloc(input_size);
    int i = 0;

    getline(&input, &input_size, stdin);
    s->filename = malloc(my_strlen(input) * sizeof(char));
    while (input[i] != '\n') {
        s->filename[i] = input[i];
        i++;
    }
    s->filename[i] = '\0';
}

void save_click(sfRenderWindow *window, Sprite_t *s)
{
    if (s->check_save != 0 && s->menu1 % 2 != 0 &&
    sfFloatRect_contains(&s->gb_jpg, s->pos.x, s->pos.y)) {
        my_printf("\x1b[38;5;208m" "Name of the file to save : " "\x1b[0m");
        name_file(window, s);
        save_image(window, s, ".jpg");
    }
    if (s->check_save != 0 && s->menu1 % 2 != 0 &&
    sfFloatRect_contains(&s->gb_png, s->pos.x, s->pos.y)) {
        my_printf("\x1b[38;5;208m" "Name of the file to save : " "\x1b[0m");
        name_file(window, s);
        save_image(window, s, ".png");
    }
    if (s->check_save != 0 && s->menu1 % 2 != 0 &&
    sfFloatRect_contains(&s->gb_bmp, s->pos.x, s->pos.y)) {
        my_printf("\x1b[38;5;208m" "Name of the file to save : " "\x1b[0m");
        name_file(window, s);
        save_image(window, s, ".bmp");
    }
}

void new_click(sfRenderWindow *window, Sprite_t *s)
{
    sfImage *new_file;

    if (s->menu1 % 2 != 0 &&
    sfFloatRect_contains(&s->gb_new_file, s->pos.x, s->pos.y)) {
        new_file = sfImage_createFromColor(1000, 500, sfTransparent);
        s->image = new_file;
    }
}

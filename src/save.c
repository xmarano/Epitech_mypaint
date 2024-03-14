/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-mypaint-tom.clerc
** File description:
** save.c
*/
#include "paint.h"

//static save_image(sfRenderWindow *window, Sprite_t *s, char *str, char *str2)
//{
//    sfTexture* texture;
//    sfImage* image;
//    char *file_name = malloc(my_strlen(str) + my_strlen(str2) * sizeof(char));
//
//    file_name = my_strcat(file_name, str);
//    file_name = my_strcat(file_name, str2);
//    texture = sfTexture_createFromImage(s->image, NULL);
//    image = sfTexture_copyToImage(texture);
//    sfImage_saveToFile(image, "draw.jpg");
//    sfImage_destroy(image);
//    sfTexture_destroy(texture);
//}
//
//void save_click(sfRenderWindow *window, Sprite_t *s)
//{
//    if (sfFloatRect_contains(&s->gb_jpg, s->pos.x, s->pos.y))
//        save_image()
//    if (sfFloatRect_contains(&s->gb_png, s->pos.x, s->pos.y))
//    if (sfFloatRect_contains(&s->gb_bmp, s->pos.x, s->pos.y))
//
//    sfFloatRect save_bounds = sfSprite_getGlobalBounds(s->save_s);
//    sfTexture* texture;
//    sfImage* image;
//
//    if (sfFloatRect_contains(&j, s->pos.x, s->pos.y)) {
//        texture = sfTexture_createFromImage(s->image, NULL);
//        image = sfTexture_copyToImage(texture);
//        sfImage_saveToFile(image, "draw.jpg");
//        sfImage_destroy(image);
//        sfTexture_destroy(texture);
//    }
//}

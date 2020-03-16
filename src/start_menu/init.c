/*
** EPITECH PROJECT, 2020
** init
** File description:
** init
*/

#include "my.h"

int init_startmenu(utils_t *utils, startmenu_t *startmenu)
{
    sfVector2f scale = {0.7, 0.7};

    startmenu->background_sprite = sfSprite_create();
    startmenu->background_texture = sfTexture_createFromFile
                            ("./utils/imgs/background_startmenu.png", NULL);
    sfSprite_setTexture(startmenu->background_sprite,
                            startmenu->background_texture, sfTrue);
    sfSprite_setScale(startmenu->background_sprite, scale);
}
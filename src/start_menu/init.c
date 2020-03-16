/*
** EPITECH PROJECT, 2020
** init
** File description:
** init
*/

#include "my.h"

int init_buttons(startmenu_t *startmenu)
{
    sfVector2f pos = {830, 680};
    sfVector2f pos_2 = {830, 820};
    sfVector2f scale = {0.7, 0.7};

    startmenu->quit_sprite = sfSprite_create();
    startmenu->start_sprite = sfSprite_create();
    startmenu->quit_texture = sfTexture_createFromFile
                            ("./utils/imgs/quit.png", NULL);
    startmenu->start_texture = sfTexture_createFromFile
                            ("./utils/imgs/start.png", NULL);
    sfSprite_setScale(startmenu->start_sprite, scale);
    sfSprite_setScale(startmenu->quit_sprite, scale);
    sfSprite_setPosition(startmenu->start_sprite, pos);
    sfSprite_setPosition(startmenu->quit_sprite, pos_2);
    sfSprite_setTexture(startmenu->quit_sprite,
                        startmenu->quit_texture, sfTrue);
    sfSprite_setTexture(startmenu->start_sprite,
                        startmenu->start_texture, sfTrue);
    return (0);
}

int init_startmenu(utils_t *utils, startmenu_t *startmenu)
{
    sfVector2f scale = {0.6, 0.6};

    init_buttons(startmenu);
    init_highlight(startmenu);
    startmenu->background_sprite = sfSprite_create();
    startmenu->background_texture = sfTexture_createFromFile
                            ("./utils/imgs/background_startmenu.png", NULL);
    sfSprite_setTexture(startmenu->background_sprite,
                            startmenu->background_texture, sfTrue);
    sfSprite_setScale(startmenu->background_sprite, scale);
    return (0);
}
/*
** EPITECH PROJECT, 2020
** display
** File description:
** display
*/

#include "my.h"

int display_startmenu(utils_t *utils, startmenu_t *startmenu)
{
    sfRenderWindow_clear(utils->window, sfBlack);
    sfRenderWindow_drawSprite(utils->window, startmenu->background_sprite, NULL);
    sfRenderWindow_drawSprite(utils->window, startmenu->start_sprite, NULL);
    sfRenderWindow_drawSprite(utils->window, startmenu->quit_sprite, NULL);
    return (0);
}
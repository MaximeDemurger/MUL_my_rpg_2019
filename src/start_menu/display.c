/*
** EPITECH PROJECT, 2020
** display
** File description:
** display
*/

#include "my.h"

int display_startmenu(utils_t *utils, startmenu_t *startmenu)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(utils->window);

    sfRenderWindow_clear(utils->window, sfBlack);
    display_highlight_quit(startmenu, mouse_pos);
    display_highlight_start(startmenu, mouse_pos);
    sfRenderWindow_drawSprite(utils->window, startmenu->background_sprite, NULL);
    sfRenderWindow_drawSprite(utils->window, startmenu->start_sprite, NULL);
    sfRenderWindow_drawSprite(utils->window, startmenu->quit_sprite, NULL);
    return (0);
}
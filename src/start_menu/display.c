/*
** EPITECH PROJECT, 2020
** display
** File description:
** display
*/

#include "my.h"

void event_start_menu(utils_t *utils)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(utils->window);

    if (utils->event.type == sfEvtMouseButtonPressed &&
            (pos.x >= 830 && pos.x <= 1006) &&
            (pos.y >= 683 && pos.y <= 774)) {
        utils->in_start = false;
        utils->lvl_selection = true;
        sfRenderWindow_clear(utils->window, sfBlack);
    }
    if (utils->event.type == sfEvtMouseButtonPressed &&
            (pos.x >= 830 && pos.x <= 1006) &&
            (pos.y >= 823 && pos.y <= 916)) {
        utils->in_start = false;
        utils->in_game = false;
        sfRenderWindow_close(utils->window);
    }
}

int display_startmenu(utils_t *utils, startmenu_t *startmenu)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(utils->window);

    sfRenderWindow_clear(utils->window, sfBlack);
    event_start_menu(utils);
    display_highlight_quit(startmenu, mouse_pos);
    display_highlight_start(startmenu, mouse_pos);
    sfRenderWindow_drawSprite(utils->window, startmenu->background_sprite,
                                                                    NULL);
    sfRenderWindow_drawSprite(utils->window, startmenu->start_sprite, NULL);
    sfRenderWindow_drawSprite(utils->window, startmenu->quit_sprite, NULL);
    return (0);
}
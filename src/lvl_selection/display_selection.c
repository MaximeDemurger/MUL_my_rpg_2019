/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** display selection
*/

#include "my.h"

void selection_events(utils_t *utils)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(utils->window);

    if (utils->event.type == sfEvtMouseButtonPressed &&
        pos.x > 300 && pos.x < 500 &&
        pos.y > 400 && pos.y < 600) {
        utils->lvl_selection = false;
        utils->in_game = true;
        sfRenderWindow_clear(utils->window, sfBlack);
    }
}

void display_selection(utils_t *utils, select_t *select)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(utils->window);

    sfRenderWindow_clear(utils->window, sfBlack);
    selection_events(utils);
    sfRenderWindow_drawSprite(utils->window, select->back, NULL);
    // if (pos.x > 300 && pos.x < 500 &&
    //     pos.y > 400 && pos.y < 600)
    //     sfRenderWindow_drawSprite(utils->window, select->hoover, NULL);
    sfRenderWindow_drawSprite(utils->window, select->lvls, NULL);
    sfRenderWindow_drawText(utils->window, select->welcomming, NULL);
    sfRenderWindow_drawText(utils->window, select->credits, NULL);
    sfRenderWindow_drawText(utils->window, select->version, NULL);
}
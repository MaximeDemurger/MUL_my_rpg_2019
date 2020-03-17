 /*
** EPITECH PROJECT, 2019
** runnner
** File description:
** open window
*/

#include "my.h"
#include <stdio.h>

void navigation_controller(utils_t *utils, game_t *game)
{
    // if (utils->pause == true)
    //     pause_menu(utils, game->pause);
    if (utils->in_start == true) {
        display_startmenu(utils, game->startmenu);
    }
    if (utils->in_game == true)
        draw_achivement(utils, game->achiv);
    if (utils->in_pause == true) {
        display_pausemenu(game);
    }
    //     death_menu(utils, game->death);
    // if (utils->settings == true)
    //     settings_menu(utils, game->settings);
}

int open_window(utils_t *utils, game_t *game)
{
    while (sfRenderWindow_isOpen(utils->window)) {
        navigation_controller(utils, game);
        capture_events(utils);
        if (utils->life <= 0) utils->death = true;
        sfRenderWindow_display(utils->window);
        sfRenderWindow_clear(utils->window, sfBlack);
    }
    return 0;
}
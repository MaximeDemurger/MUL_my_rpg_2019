 /*
** EPITECH PROJECT, 2019
** runnner
** File description:
** open window
*/

#include "my.h"

void check_utils(utils_t *utils)
{
    // if (utils->pause == true)
    //     pause_menu(utils, game->pause);
    // if (utils->strt_menu == true)
    //     starting_menu(utils, game->start);
    //     death_menu(utils, game->death);
    // if (utils->settings == true)
    //     settings_menu(utils, game->settings);
}

int open_window(utils_t *utils, game_t *game)
{
    while (sfRenderWindow_isOpen(utils->window)) {
        check_utils(utils);
        capture_events(utils);
        if (utils->life <= 0) utils->death = true;
        sfRenderWindow_display(utils->window);
        sfRenderWindow_clear(utils->window, sfBlack);
    }
    return 0;
}
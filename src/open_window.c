 /*
** EPITECH PROJECT, 2019
** runnner
** File description:
** open window
*/

#include "my.h"
#include <unistd.h>
#include <stdio.h>

void navigation_controller(utils_t *utils, game_t *game)
{
    if (utils->in_start == true) {
        display_startmenu(utils, game->startmenu);
    }
    if (utils->in_game == true) {
        printing_map(game);
        draw_player(game->play, game->utils);
        draw_enemys(utils, game->ene);
        draw_keys(utils, game->key);
        draw_achivement(utils, game->achiv);
        //mini_map(game);
    }
    if (utils->in_pause == true) {
        display_pausemenu(game);
    }
    //     death_menu(utils, game->death);
    // if (utils->settings == true)
    //     settings_menu(utils, game->settings);
}

int open_window(utils_t *utils, game_t *game)
{
    game->key = NULL;
    game->ene = NULL;
    init_keys(&game->key);
    init_enemy(&game->ene, 5);
    while (sfRenderWindow_isOpen(utils->window)) {
        navigation_controller(utils, game);
        capture_events(utils, game);
        if (utils->life <= 0) utils->death = true;
        sfRenderWindow_display(utils->window);
        sfRenderWindow_clear(utils->window, sfBlack);
    }
    return 0;
}
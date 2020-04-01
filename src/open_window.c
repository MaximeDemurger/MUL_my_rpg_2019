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
    sfVector2f player_pos = {(float)game->play->x_play,
                            (float)game->play->y_play};

    if (utils->in_start == true)
        display_startmenu(utils, game->startmenu);
    if (utils->lvl_selection == true)
        display_selection(utils, game->select);
    if (utils->in_game == true) {
        printing_map(game);
        draw_player(game->play, game->utils, game);
        draw_enemys(utils, game->ene);
        enemy_move(game, game->ene, player_pos);
        draw_keys(utils, game->key);
        pick_up_keys(&game->key, player_pos, game->achiv);
        draw_achivement(utils, game->achiv);
        draw_inventory(utils, game->inv, game->achiv);
        if (game->map->open_map == true)
            print_minimap(game);
    }
    if (utils->in_pause == true)
        display_pausemenu(game);
    //     death_menu(utils, game->death);
    // if (utils->settings == true)
    //     settings_menu(utils, game->settings);
}

int open_window(utils_t *utils, game_t *game)
{
    game->key = NULL;
    game->ene = NULL;
    init_keys(&game->key);
    init_enemy(&game->ene, rand() % 4);
    init_enemy(&game->ene, 5);
    get_path(game->map->map_pars, game->map);
    while (sfRenderWindow_isOpen(utils->window)) {
        navigation_controller(utils, game);
        capture_events(utils, game);
        if (utils->life <= 0) utils->death = true;
        sfRenderWindow_display(utils->window);
        sfRenderWindow_clear(utils->window, sfBlack);
    }
    return 0;
}
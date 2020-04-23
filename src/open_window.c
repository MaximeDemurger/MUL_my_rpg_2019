/*
** EPITECH PROJECT, 2019
** runnner
** File description:
** open window
*/

#include "my.h"
#include <unistd.h>
#include <stdio.h>

void display_game(utils_t *utils, game_t *game,
sfVector2f player_pos)
{
    if (utils->in_game == true) {
        printing_map(game);
        draw_food(utils, game->food);
        draw_player(game->play, game->utils, game);
        draw_enemys(utils, game->ene);
        enemy_move(game, game->ene, player_pos);
        draw_keys(utils, game->key);
        pick_up_keys(&game->key, player_pos, game->achiv);
        pick_up_food(&game->food, player_pos, game->play);
        kill_enemys(&game->ene, game->achiv);
        draw_achivement(utils, game->achiv);
        draw_inventory(utils, game->inv, game->achiv);
        display_score(game);
        display_heart(game->play, game->utils);
        display_how_to(game);
        display_settings_button(game);
        if (game->map->open_map == true)
            print_minimap(game);
        if (game->play->attack_number >= 1) {
            attack_enemis(game->play, game->utils, game->ene);
            game->play->attack_number = 0;
        }
    }
}

void navigation_controller_next(utils_t *utils, game_t *game,
sfVector2f player_pos)
{
    display_game(utils, game, player_pos);
    if (utils->in_pause == true)
        display_pausemenu(game);
    if (utils->in_settings == true)
        display_settings(game);
    //     death_menu(utils, game->death);
    // if (utils->settings == true)
    //     settings_menu(utils, game->settings);
}

void navigation_controller(utils_t *utils, game_t *game)
{
    sfVector2f player_pos = {(float)game->play->x_play,
                            (float)game->play->y_play};

    if (utils->in_start == true)
        display_startmenu(utils, game->startmenu);
    if (utils->lvl_selection == true)
        display_selection(utils, game->select);
    if (utils->in_dungeon == true) {
        game->play->x_play = 150;
        game->play->y_play = 150;
        print_dungeon(utils, game->dungeon);
        draw_player(game->play, game->utils, game);
    }
    navigation_controller_next(utils, game, player_pos);
}

int open_window(utils_t *utils, game_t *game)
{
    game->key = NULL;
    game->ene = NULL;
    game->food = NULL;
    init_food(&game->food);
    init_keys(&game->key);
    init_enemy(&game->ene, rand() % 5);
    get_path(game->map->map_pars, game->map);
    while (sfRenderWindow_isOpen(utils->window)) {
        navigation_controller(utils, game);
        capture_events(utils, game);
        if (game->play->life <= 0) utils->death = true;
        sfRenderWindow_display(utils->window);
        sfRenderWindow_clear(utils->window, sfBlack);
    }
    return 0;
}
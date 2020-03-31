/*
** EPITECH PROJECT, 2019
** runner
** File description:
** capture events
*/

#include "my.h"

int dungeon_pos(play_t *play, map_t *map)
{
    if (map->map_pos_col == play->col_map &&
        map->map_pos_line == play->line_map &&
        play->x_play >= 560 && play->x_play <= 1150 &&
        play->y_play >= 200 && play->y_play <= 800)
        return 1;
    return 0;
}

void open_mini_map(game_t *game)
{
    if (game->utils->event.key.code == sfKeyM &&
        game->map->open_map == false &&
        game->map->wait_for_it > 2) {
        game->map->open_map = true;
        game->map->wait_for_it = 0;
    } else if (game->map->open_map == true &&
        game->utils->event.key.code == sfKeyM &&
        game->map->wait_for_it > 2) {
        game->map->open_map = false;
        game->map->wait_for_it = 0;
    }
    game->map->wait_for_it++;
}

void capture_events(utils_t *utils, game_t *game)
{
    while (sfRenderWindow_pollEvent(utils->window, &utils->event)) {
        if (utils->event.type == sfEvtClosed)
            sfRenderWindow_close(utils->window);
        if (utils->event.type == sfEvtKeyPressed &&
            utils->event.key.code == sfKeyEscape &&
            utils->in_game == true)
            utils->in_pause = true;
        open_mini_map(game);
        player_move(game->play, game->utils);
    }
}
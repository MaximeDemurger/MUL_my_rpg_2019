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
        play->x_play >= 590 && play->x_play <= 1185 &&
        play->y_play >= 243 && play->y_play <= 840)
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

void capture_event_next(utils_t *utils, game_t *game)
{
    if (utils->event.type == sfEvtKeyPressed &&
        utils->event.key.code == sfKeyE && game->pnj->in_range == true
        && game->pnj->is_talking == false)
        game->pnj->is_talking = true;
    if (utils->event.type == sfEvtKeyPressed &&
        utils->event.key.code == sfKeyN && game->pnj->is_talking == true)
        game->pnj->index += 1;
    if (game->pnj->next_to == 1 && utils->event.key.code == sfKeyA
        && game->dungeon->all_achiv == 1) {
        game->utils->in_dungeon = true;
        game->utils->in_game = false;
    }
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
        player_move(game->play, game->utils, game->map);
        capture_event_next(utils, game);
    }
}
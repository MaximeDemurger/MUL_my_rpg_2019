/*
** EPITECH PROJECT, 2019
** runner
** File description:
** capture events
*/

#include "my.h"

void move_player(play_t *play, utils_t *utils)
{
    if (utils->event.key.code == sfKeyRight && play->x_play <= 1830 &&
        play->col_map <= 32)
        play->x_play += 10;
    else if (utils->event.key.code == sfKeyLeft && play->x_play >= 0 &&
            play->col_map >= 0)
        play->x_play -= 10;
    else if (utils->event.key.code == sfKeyDown && play->y_play <= 1000 &&
            play->line_map <= 16)
        play->y_play += 10;
    else if (utils->event.key.code == sfKeyUp && play->y_play >= 0 &&
            play->line_map >= 0)
        play->y_play -= 10;
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
        move_player(game->play, utils);
    }
}
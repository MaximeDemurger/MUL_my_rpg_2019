/*
** EPITECH PROJECT, 2020
** player
** File description:
** player
*/
#include "my.h"

int movement_player_y(play_t *play, utils_t *utils, map_t *map)
{
    if (utils->event.key.code == sfKeyRight) {
        sfSprite_setRotation(play->player, 90);
        move_rect_up(play);
        sfClock_restart(play->clock);
        if (dungeon_pos(play, map) == 0)
            play->x_play += (utils->width / 128);
        else
            play->x_play -= (utils->width / 128);
    } else if (utils->event.key.code == sfKeyLeft) {
        sfSprite_setRotation(play->player, -90);
        move_rect_up(play);
        if (dungeon_pos(play, map) == 0)
            play->x_play -= (utils->width / 128);
        else
            play->x_play += (utils->width / 128);
        sfClock_restart(play->clock);
    }
    return 0;
}

int movement_player_x(play_t *play, utils_t *utils, map_t *map)
{
    if (utils->event.key.code == sfKeyUp) {
        sfSprite_setRotation(play->player, 0);
        move_rect_up(play);
        if (dungeon_pos(play, map) == 0)
            play->y_play -= (utils->height / 75);
        else
            play->y_play += (utils->height / 75);
        sfClock_restart(play->clock);
    }
    else if (utils->event.key.code == sfKeyDown) {
        sfSprite_setRotation(play->player, 180);
        move_rect_up(play);
        if (dungeon_pos(play, map) == 0)
            play->y_play += (utils->height / 75);
        else
            play->y_play -= (utils->height / 75);
        sfClock_restart(play->clock);
    }
    return 0;
}

int player_move(play_t *play, utils_t *utils, map_t *map, game_t *game)
{
    sfVector2f scale = {0.2, 0.2};
    sfTime time = sfClock_getElapsedTime(play->clock);
    float seconds = time.microseconds / 1000000.0;

    sfSprite_setScale(play->player, scale);
    sfRectangleShape *sfRectangleShape_create(void);
    sfSprite_setTextureRect(play->player, play->rect);
    if (seconds > 0.01 && game->dungeon->in_it == 0) {
        movement_player_x(play, utils, map);
        movement_player_y(play, utils, map);
    }
    return 0;
}
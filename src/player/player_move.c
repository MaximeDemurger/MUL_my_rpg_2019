/*
** EPITECH PROJECT, 2020
** player
** File description:
** player
*/
#include "my.h"

int movement_player_y(play_t *play, utils_t *utils)
{
    if (utils->event.type == sfEvtKeyPressed &&
        utils->event.key.code == sfKeyRight) {
        sfSprite_setRotation(play->player, 90);
        move_rect_up(play);
        sfClock_restart(play->clock);
        play->x_play += 30;
    }
    else if (utils->event.type == sfEvtKeyPressed &&
            utils->event.key.code == sfKeyLeft) {
        sfSprite_setRotation(play->player, -90);
        move_rect_up(play);
        play->x_play -= 30;
        sfClock_restart(play->clock);
    }
    return 0;
}

int movement_player_x(play_t *play, utils_t *utils)
{
    if (utils->event.type == sfEvtKeyPressed &&
        utils->event.key.code == sfKeyUp) {
        sfSprite_setRotation(play->player, 0);
        move_rect_up(play);
        play->y_play -= 30;
        sfClock_restart(play->clock);
    }
    else if (utils->event.type == sfEvtKeyPressed &&
            utils->event.key.code == sfKeyDown) {
        sfSprite_setRotation(play->player, 180);
        move_rect_up(play);
        play->y_play += 30;
        sfClock_restart(play->clock);
    }
    else {
        movement_player_y(play, utils);
    }
    return 0;
}

int player_move(play_t *play, utils_t *utils)
{
    sfVector2f scale = {0.2, 0.2};
    sfTime time = sfClock_getElapsedTime(play->clock);
    float seconds = time.microseconds / 1000000.0;
    

    sfSprite_setScale(play->player, scale);
    sfRectangleShape *sfRectangleShape_create(void);
    sfSprite_setTextureRect(play->player, play->rect);
    if (seconds > 0.01) {
        movement_player_x(play, utils);
    }
    return 0;
}
/*
** EPITECH PROJECT, 2020
** player
** File description:
** player
*/
#include "my.h"

void move_rect(play_t *play)
{
    if (play->rect.left < 220)
        play->rect.left += 100;
    else
        play->rect.left = 0;
}

int movement_player_y(play_t *play, utils_t *utils)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        sfSprite_setRotation(play->player, 90);
        move_rect_up(play);
        sfClock_restart(play->clock);
        play->x_play += 5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        sfSprite_setRotation(play->player, -90);
        move_rect_up(play);
        play->x_play -= 5;
        sfClock_restart(play->clock);
    }
    return 0;
}

int movement_player_x(play_t *play, utils_t *utils)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        sfSprite_setRotation(play->player, 0);
        move_rect_up(play);
        play->y_play -= 5;
        sfClock_restart(play->clock);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        sfSprite_setRotation(play->player, 180);
        move_rect_up(play);
        play->y_play += 5;
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
    if (seconds > 0.001) {
        movement_player_x(play, utils);
    }
    return 0;
}
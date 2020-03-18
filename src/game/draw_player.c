/*
** EPITECH PROJECT, 2020
** draw palyer
** File description:
** player drawing
*/

#include <stdio.h>
#include "my.h"

void draw_player(play_t *play, utils_t *utils)
{
    sfVector2f player_pos = {play->x_play, play->y_play};

    sfSprite_setPosition(play->player, player_pos);
    sfRenderWindow_drawSprite(utils->window, play->player, NULL);
}
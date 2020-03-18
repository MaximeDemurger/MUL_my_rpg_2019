/*
** EPITECH PROJECT, 2020
** gameplay
** File description:
** gameplay
*/

#include "my.h"

int init_gameplay(play_t *play)
{
    play->x_play = 1000;
    play->y_play = 500;
    play->col_map = 0;
    play->line_map = 0;
    play->player_text = sfTexture_createFromFile("utils/imgs/player.png", NULL);
    play->player = sfSprite_create();
    if (!play->player || !play->player_text)
        return 84;
    sfSprite_setTexture(play->player, play->player_text, sfTrue);
    return 0;
}
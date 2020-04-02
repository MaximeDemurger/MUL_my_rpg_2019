/*
** EPITECH PROJECT, 2020
** gameplay
** File description:
** gameplay
*/

#include "my.h"

int init_gameplay(play_t *play)
{
    sfIntRect rect = {0, 0, 350, 300};
    sfVector2f offset = {5, 0};

    play->life = 10;
    play->x_play = 1000;
    play->y_play = 500;
    play->origin.x = 175;
    play->origin.y = 150;
    play->col_map = 0;
    play->line_map = 0;
    play->player_text = sfTexture_createFromFile("utils/imgs/player.png", NULL);
    play->player = sfSprite_create();
    play->clock = sfClock_create();
    sfSprite_setOrigin(play->player, play->origin);
    if (!play->player || !play->player_text || !play->clock)
        return 84;
    sfSprite_setTexture(play->player, play->player_text, sfTrue);
    play->rect = rect;
    play->offset = offset;
    return 0;
}
/*
** EPITECH PROJECT, 2020
** draw palyer
** File description:
** player drawing
*/

#include <stdio.h>
#include "my.h"

int check_dungeon(sfVector2f player_pos)
{
    if (player_pos.x >= 510 &&
        player_pos.x <= 570 &&
        player_pos.y >= 260 &&
        player_pos.y <= 330)
        printf("In Dungeon\n");
    return 0;
}

void draw_player(play_t *play, utils_t *utils, game_t *game)
{
    sfVector2f player_pos = {play->x_play, play->y_play};

    if (game->achiv->player_keys >= 3 && game->achiv->player_gold >= 30)
        game->dungeon->all_achiv = 1;
    sfSprite_setPosition(play->player, player_pos);
    sfRenderWindow_drawSprite(utils->window, play->player, NULL);
}
/*
** EPITECH PROJECT, 2020
** game map
** File description:
** game map
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

void check_charac(char a, utils_t *utils, map_t *map, sfVector2f pos)
{
    if (a == 'O') {
        sfSprite_setPosition(map->grass, pos);
        sfRenderWindow_drawSprite(utils->window, map->grass, NULL);
    }
    if (a == 'X') {
        sfSprite_setPosition(map->soil, pos);
        sfRenderWindow_drawSprite(utils->window, map->soil, NULL);
    }
    if (a == '1') {
        sfSprite_setPosition(map->tower_pos, pos);
        sfRenderWindow_drawSprite(utils->window, map->tower_pos, NULL);
    }
}

void printing_map(game_t *game)
{
    int col = 0;
    int line = 0;
    int x = 0;
    int y = 0;
    sfVector2f pos = {x, y};

    while (line < 8) {
        col = 0;
        pos.x = 0;
        while (col < 16) {
            check_charac(game->map->map_pars[line][col],
                        game->utils, game->map, pos);
            pos.x += 128;
            col++;
        }
        pos.y += 135;
        line++;
    }
}
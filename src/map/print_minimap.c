/*
** EPITECH PROJECT, 2020
** minimap
** File description:
** minimap
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

void check_mini_next(char a, utils_t *utils, map_t *map, sfVector2f pos)
{
    if (a == 'D') {
        sfSprite_setPosition(map->donjon_mini, pos);
        sfRenderWindow_drawSprite(utils->window, map->donjon_mini, NULL);
    }
    if (a == 'S') {
        sfSprite_setPosition(map->mini_stairs, pos);
        sfRenderWindow_drawSprite(utils->window, map->mini_stairs, NULL);
    }
}

void check_mini(char a, utils_t *utils, map_t *map, sfVector2f pos)
{
    if (a == 'O') {
        sfSprite_setPosition(map->mini_grass, pos);
        sfRenderWindow_drawSprite(utils->window, map->mini_grass, NULL);
    }
    if (a == 'X') {
        sfSprite_setPosition(map->mini_soil, pos);
        sfRenderWindow_drawSprite(utils->window, map->mini_soil, NULL);
    }
    if (a == '1') {
        sfSprite_setPosition(map->mini_tower, pos);
        sfRenderWindow_drawSprite(utils->window, map->mini_tower, NULL);
    } else
        check_mini_next(a, utils, map, pos);
}

void print_minimap(game_t *game)
{
    sfVector2f mini_map = {150, 120};
    sfVector2f rec_map = {150, 100};
    int i = 0;
    int j = 0;

    while (game->map->map_pars[i]) {
        j = 0;
        mini_map.x = 185;
        while (game->map->map_pars[i][j]) {
            check_mini(game->map->map_pars[i][j], game->utils,
                        game->map, mini_map);
            mini_map.x += 33;
            j++;
        }
        mini_map.y += 35;
        i++;
    }
    sfSprite_setPosition(game->map->mini_map, rec_map);
    sfRenderWindow_drawSprite(game->utils->window, game->map->mini_map, NULL);
}
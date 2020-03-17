/*
** EPITECH PROJECT, 2020
** game map
** File description:
** game map
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "my.h"

void check_case(map_t *map, utils_t *utils, sfVector2f pos)
{
    sfSprite_setPosition(map->tower_pos, pos);
    sfRenderWindow_drawSprite(utils->window, map->tower_pos, NULL);
}

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
    if (a == '1')
        check_case(map, utils, pos);
}

void printing_map(char **tab, game_t *game)
{
    int col = 0;
    int line = 0;
    int x = 0;
    int y = 0;
    sfVector2f pos = {x, y};

    while (tab[line] != NULL) {
        col = 0;
        pos.x = 0;
        while (tab[line][col] != '\0') {
            check_charac(tab[line][col], game->utils, game->map, pos);
            pos.x += 128;
            col++;
        }
        pos.y += 135;
        line++;
    }
}
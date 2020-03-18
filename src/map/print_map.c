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

int check_map(play_t *play)
{
    if (play->x_play == 1840 && play->col_map < 32) {
        play->x_play = 20;
        play->col_map += 16;
    } else if (play->x_play == 0 && play->col_map > 0) {
        play->x_play = 1820;
        play->col_map -= 16;
    } else if (play->y_play == 1010 && play->line_map < 16) {
        play->y_play = 20;
        play->line_map += 8;
    } else if (play->y_play == -20 && play->line_map > 0) {
        play->y_play = 980;
        play->line_map -= 8;
    }
    return 0;
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
    if (a == '1') {
        sfSprite_setPosition(map->tower_pos, pos);
        sfRenderWindow_drawSprite(utils->window, map->tower_pos, NULL);
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
    }
}

void printing_map(game_t *game)
{
    int x = 0;
    int y = 0;
    sfVector2f pos = {x, y};
    int col = 0;
    int line = 0;

    check_map(game->play);
    line = game->play->line_map;
    while (line < 8 + game->play->line_map) {
        col = game->play->col_map;
        pos.x = 0;
        while (col < 16 + game->play->col_map) {
            check_charac(game->map->map_pars[line][col],
                        game->utils, game->map, pos);
            pos.x += 128;
            col++;
        }
        pos.y += 135;
        line++;
    }
}

void print_minimap(game_t *game)
{
    sfVector2f mini_map = {150, 120};
    sfVector2f rec_map = {150, 100}; 
    int i = 0;
    int j = 0;

    sfSprite_setPosition(game->map->mini_map, rec_map);
    sfRenderWindow_drawSprite(game->utils->window, game->map->mini_map, NULL);
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
}
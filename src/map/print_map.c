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

int check_map(play_t *play, keys_t *keys, enemy_t *ene)
{
    if (play->x_play == 1840 && play->col_map < 32) {
        play->x_play = 20;
        play->col_map += 16;
        init_keys(&keys);
        init_enemy(&ene, rand() % 4);
    } else if (play->x_play == 0 && play->col_map > 0) {
        play->x_play = 1820;
        play->col_map -= 16;
        init_keys(&keys);
        init_enemy(&ene, rand() % 4);
    } else if (play->y_play == 1010 && play->line_map < 16) {
        play->y_play = 20;
        play->line_map += 8;
        init_keys(&keys);
        init_enemy(&ene, rand() % 4);
    } else if (play->y_play == -10 && play->line_map > 0) {
        play->y_play = 980;
        play->line_map -= 8;
        init_keys(&keys);
        init_enemy(&ene, rand() % 4);
    } return 0;
}

void rotation(game_t *game, sfVector2f pos)
{
    float y;
    sfVector2f origin = {75, 75};
    double c = game->play->x_play - pos.x;
    double b = game->play->y_play - pos.y;

    if (game->play->x_play <= 810 && game->play->x_play >= 170 &&
        game->play->y_play <= 430) {
        y = -atan2(c, b) * 180 / 3.14;
        sfSprite_setOrigin(game->pnj->sprite_dung, origin);
        sfSprite_setRotation(game->pnj->sprite_dung, y);
    }
}

void check_charac(char a, utils_t *utils, game_t *game, sfVector2f pos)
{
    if (a == 'O') {
        sfSprite_setPosition(game->map->grass, pos);
        sfRenderWindow_drawSprite(game->utils->window, game->map->grass, NULL);
    } else if (a == 'X') {
        sfSprite_setPosition(game->map->soil, pos);
        sfRenderWindow_drawSprite(utils->window, game->map->soil, NULL);
    } else if (a == '1') {
        sfSprite_setPosition(game->map->tower_pos, pos);
        sfRenderWindow_drawSprite(utils->window, game->map->tower_pos, NULL);
    } else if (a == 'D') {
        sfSprite_setPosition(game->map->donjon, pos);
        sfRenderWindow_drawSprite(utils->window, game->map->donjon, NULL);
    } else if (a == 'S') {
        sfSprite_setPosition(game->map->stairs, pos);
        sfRenderWindow_drawSprite(utils->window, game->map->stairs, NULL);
    } else if (a == 'E') {
        rotation(game, pos);
        sfSprite_setPosition(game->map->grass, pos);
        sfRenderWindow_drawSprite(game->utils->window, game->map->grass, NULL);
        sfSprite_setPosition(game->pnj->sprite_dung, pos);
        sfRenderWindow_drawSprite(utils->window, game->pnj->sprite_dung, NULL);
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
    if (a == 'D') {
        sfSprite_setPosition(map->donjon_mini, pos);
        sfRenderWindow_drawSprite(utils->window, map->donjon_mini, NULL);
    } if (a == 'S') {
        sfSprite_setPosition(map->mini_stairs, pos);
        sfRenderWindow_drawSprite(utils->window, map->mini_stairs, NULL);
    }
}

void printing_map(game_t *game)
{
    int x = 0;
    int y = 0;
    sfVector2f pos = {x, y};
    int col = 0;
    int line = 0;

    check_map(game->play, game->key, game->ene);
    line = game->play->line_map;
    while (line < 8 + game->play->line_map) {
        col = game->play->col_map;
        pos.x = 0;
        while (col < 16 + game->play->col_map) {
            check_charac(game->map->map_pars[line][col],
                        game->utils, game, pos);
            pos.x += 128;
            col++;
        }
        pos.y += 135;
        line++;
    }
    if (game->play->col_map == 0 && game->play->line_map == 0)
        draw_ancient(game->utils, game->pnj);
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
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

void rotation(game_t *game, sfVector2f pos)
{
    float y;
    sfVector2f origin = {75, 75};
    sfVector2f pos_dung = {660, 130};
    double c = game->play->x_play - pos.x;
    double b = game->play->y_play - pos.y;

    if (game->play->x_play <= 810 && game->play->x_play >= 170 &&
        game->play->y_play <= 430) {
        pos.x += 20;
        pos.y += 20;
        sfSprite_setPosition(game->pnj->not_enough, pos_dung);
        sfRenderWindow_drawSprite(game->utils->window,
            game->pnj->not_enough, NULL);
        sfSprite_setPosition(game->pnj->sprite_dung, pos);
        y = -atan2(c, b) * 180 / 3.14;
        sfSprite_setOrigin(game->pnj->sprite_dung, origin);
        sfSprite_setRotation(game->pnj->sprite_dung, y);
        game->pnj->next_to = 1;
    } else
        game->pnj->next_to = 0;
}

void check_charac_next(char a, utils_t *utils, game_t *game, sfVector2f pos)
{
    if (a == 'D') {
        sfSprite_setPosition(game->map->donjon, pos);
        sfRenderWindow_drawSprite(utils->window, game->map->donjon, NULL);
    }
    if (a == 'S') {
        sfSprite_setPosition(game->map->stairs, pos);
        sfRenderWindow_drawSprite(utils->window, game->map->stairs, NULL);
    }
    else if (a == 'E') {
        sfSprite_setPosition(game->map->grass, pos);
        sfRenderWindow_drawSprite(game->utils->window, game->map->grass, NULL);
        sfSprite_setPosition(game->pnj->sprite_dung, pos);
        sfRenderWindow_drawSprite(utils->window, game->pnj->sprite_dung, NULL);
        rotation(game, pos);
    }
}

void check_charac(char a, utils_t *utils, game_t *game, sfVector2f pos)
{
    if (a == 'O') {
        sfSprite_setPosition(game->map->grass, pos);
        sfRenderWindow_drawSprite(game->utils->window, game->map->grass, NULL);
    }
    if (a == 'X') {
        sfSprite_setPosition(game->map->soil, pos);
        sfRenderWindow_drawSprite(utils->window, game->map->soil, NULL);
    }
    else if (a == '1') {
        sfSprite_setPosition(game->map->tower_pos, pos);
        sfRenderWindow_drawSprite(utils->window, game->map->tower_pos, NULL);
    } else
        check_charac_next(a, utils, game, pos);
}

void printing_map_next(game_t *game)
{
    if (game->play->col_map == 0 && game->play->line_map == 0) {
        draw_ancient(game->utils, game->pnj);
        do_interaction(game->utils, game);
    }
}

void printing_map(game_t *game)
{
    int x = 0;
    int y = 0;
    sfVector2f pos = {x, y};
    int col = 0;
    int line = 0;

    check_map(game->play, game);
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
    printing_map_next(game);
}
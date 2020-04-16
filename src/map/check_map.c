/*
** EPITECH PROJECT, 2020
** check
** File description:
** check
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int check_map_next(play_t *play, keys_t *keys, enemy_t *ene)
{
    if (play->y_play >= 1049 && play->line_map < 16) {
        play->y_play = 53;
        play->line_map += 8;
        init_keys(&keys);
        init_enemy(&ene, rand() % 4);
    } else if (play->y_play <= 32 && play->line_map > 0) {
        play->y_play = 1034;
        play->line_map -= 8;
        init_keys(&keys);
        init_enemy(&ene, rand() % 4);
    }
    return 0;
}

int check_map(play_t *play, keys_t *keys, enemy_t *ene)
{
    if (play->x_play >= 1895 && play->col_map < 32) {
        play->x_play = 45;
        play->col_map += 16;
        init_keys(&keys);
        init_enemy(&ene, rand() % 4);
    } else if (play->x_play <= 20 && play->col_map > 0) {
        play->x_play = 1870;
        play->col_map -= 16;
        init_keys(&keys);
        init_enemy(&ene, rand() % 4);
    } else {
        if (check_map_next(play, keys, ene) == 84)
            return 84;
    }
    return 0;
}
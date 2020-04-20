/*
** EPITECH PROJECT, 2020
** attack
** File description:
** attack
*/

#include "my.h"

float vector_dist_player(sfVector2f dir)
{
    float x = dir.x;
    float y = dir.y;
    float res = sqrt(x * x + y * y);

    return (res);
}

int attack_enemis(play_t *play, utils_t *utils)
{
    return 0;
}
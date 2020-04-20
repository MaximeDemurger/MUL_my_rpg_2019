/*
** EPITECH PROJECT, 2020
** attack
** File description:
** attack
*/

#include "my.h"

int enemy_inrange(enemy_t *current, float pos_x, float pos_y)
{
    if (current->pos.x > pos_x - 50 &&
        current->pos.x < pos_x + 50 &&
        current->pos.y > pos_y - 50 &&
        current->pos.y < pos_y + 50)
        return 1;
    return 0;
}

int attack_enemis(play_t *play, utils_t *utils, enemy_t *ene)
{
    enemy_t *tmp = ene;

    while (tmp) {
        if (enemy_inrange(tmp, (float)play->x_play, (float)play->y_play)) {
            tmp->heart -= 25;
        }
        tmp = tmp->next;
    }
    return 0;
}
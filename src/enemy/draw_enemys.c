/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** draw_enemy
*/

#include "my.h"

void draw_enemys(utils_t *utils, enemy_t *ene)
{
    enemy_t *tmp = ene;

    while (tmp) {
        sfRenderWindow_drawSprite(utils->window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
}
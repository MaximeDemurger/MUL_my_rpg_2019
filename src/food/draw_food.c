/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** draw heart
*/

#include "my.h"

void draw_food(utils_t *utils, food_t *food)
{
    food_t *tmp = food;

    while (tmp) {
        sfRenderWindow_drawSprite(utils->window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
}
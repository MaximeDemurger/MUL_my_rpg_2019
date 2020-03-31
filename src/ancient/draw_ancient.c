/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** draw_ancient
*/

#include "my.h"

void draw_ancient(utils_t *utils, pnj_t *pnj)
{
    sfSprite_setPosition(pnj->sprite, pnj->pos);
    sfRenderWindow_drawSprite(utils->window, pnj->sprite, NULL);
}
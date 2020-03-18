/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** draw keys
*/

#include "my.h"

void draw_keys(utils_t *utils, keys_t *key)
{
    keys_t *tmp = key;

    while (tmp) {
        sfRenderWindow_drawSprite(utils->window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
}
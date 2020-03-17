/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** draw indicators
*/

#include "my.h"

void draw_indicators(utils_t *utils, achiv_t *achiv)
{
    sfVector2f pos1 = {200, 100};
    sfVector2f pos2 = {200, 150};

    if (achiv->player_kills >= 5) {
        sfSprite_setPosition(achiv->tick, pos1);
        sfRenderWindow_drawSprite(utils->window, achiv->tick, NULL);
    } else if (achiv->player_kills < 5) {
        sfSprite_setPosition(achiv->cross, pos1);
        sfRenderWindow_drawSprite(utils->window, achiv->cross, NULL);
    } if (achiv->player_keys >= 3) {
        sfSprite_setPosition(achiv->tick, pos2);
        sfRenderWindow_drawSprite(utils->window, achiv->tick, NULL);
    } else if (achiv->player_keys < 3){
        sfSprite_setPosition(achiv->cross, pos2);
        sfRenderWindow_drawSprite(utils->window, achiv->cross, NULL);
    } 
}
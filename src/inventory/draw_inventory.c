/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** draw_inventory
*/

#include "my.h"

void draw_inventory(utils_t *utils, inv_t *inv, achiv_t *achiv)
{
    sfText_setString(inv->keys, convert_to_string(achiv->player_keys));
    sfText_setString(inv->gold, convert_to_string(achiv->player_gold));

    sfRenderWindow_drawSprite(utils->window, inv->back, NULL);
    sfRenderWindow_drawSprite(utils->window, inv->case2, NULL);
    sfRenderWindow_drawSprite(utils->window, inv->case1, NULL);
    sfRenderWindow_drawSprite(utils->window, inv->obj1, NULL);
    sfRenderWindow_drawSprite(utils->window, inv->obj2, NULL);
    sfRenderWindow_drawText(utils->window, inv->keys, NULL);
    sfRenderWindow_drawText(utils->window, inv->gold, NULL);
}
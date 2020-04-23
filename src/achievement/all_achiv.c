/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** all achivements successfull
*/

#include "my.h"

void all_achivs(achiv_t *achiv, dungeon_t *dungeon)
{
    if (achiv->player_kills >= 5 && achiv->player_keys >= 3
        && achiv->player_gold >= 30)
        dungeon->all_achiv = true;
}
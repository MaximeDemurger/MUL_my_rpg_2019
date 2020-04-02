/*
** EPITECH PROJECT, 2020
** init dungeon
** File description:
** init dungeon
*/

#include "my.h"

int init_dungeon(dungeon_t *dungeon)
{
    dungeon->text_ground = sfTexture_createFromFile(
                                    "utils/imgs/dungeon_ground.png", NULL);
    dungeon->ground = sfSprite_create();
    sfSprite_setTexture(dungeon->ground, dungeon->text_ground, sfTrue);
}
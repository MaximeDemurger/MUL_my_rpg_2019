/*
** EPITECH PROJECT, 2020
** init mpa
** File description:
** init map
*/

#include <stdio.h>
#include "my.h"
#include "map_struct.h"

void set_texture_map(map_t *map)
{
    sfSprite_setTexture(map->grass, map->grass_text, sfTrue);
    sfSprite_setTexture(map->soil, map->soil_text, sfTrue);
    sfSprite_setTexture(map->tower_pos, map->tower_pos_text, sfTrue);
    sfSprite_setTexture(map->mini_map, map->mini_map_text, sfTrue);
    sfSprite_setTexture(map->mini_grass, map->mini_grass_text, sfTrue);
    sfSprite_setTexture(map->mini_soil, map->mini_soil_text, sfTrue);
    sfSprite_setTexture(map->mini_tower, map->mini_tower_text, sfTrue);
    sfSprite_setTexture(map->donjon, map->donjon_text, sfTrue);
    sfSprite_setTexture(map->donjon_mini, map->donjon_mini_text, sfTrue);
    sfSprite_setTexture(map->mini_stairs, map->mini_stairs_text, sfTrue);
    sfSprite_setTexture(map->stairs, map->stairs_text, sfTrue);
}

int init_minimap(map_t *map)
{
    map->mini_grass_text = sfTexture_createFromFile(
                                "utils/imgs/grass_mini.png", NULL);
    map->mini_soil_text = sfTexture_createFromFile(
                                "utils/imgs/soil_mini.jpg", NULL);
    map->mini_tower_text = sfTexture_createFromFile(
                                "utils/imgs/tower_mini.jpg", NULL);
    map->mini_map_text = sfTexture_createFromFile(
                                "utils/imgs/red_minimap.png", NULL);
    map->donjon_mini_text = sfTexture_createFromFile(
                                "utils/imgs/dungeon_mini.png", NULL);
    map->mini_stairs_text = sfTexture_createFromFile(
                                            "utils/imgs/mini_stairs.png", NULL);
    map->mini_stairs = sfSprite_create();
    map->donjon_mini = sfSprite_create();
    map->mini_map = sfSprite_create();
    map->mini_grass = sfSprite_create();
    map->mini_soil = sfSprite_create();
    map->mini_tower = sfSprite_create();
    if (!map->mini_soil || !map->mini_tower || !map->mini_grass ||
    !map->mini_tower_text || !map->mini_soil_text || !map->mini_grass_text ||
    !map->mini_map || !map->mini_map_text || !map->donjon_mini ||
    !map->donjon_mini_text)
        return 84;
    return 0;
}

int init_map(map_t *map)
{
    map->grass_text = sfTexture_createFromFile("utils/imgs/grass.png", NULL);
    map->soil_text = sfTexture_createFromFile("utils/imgs/soil.jpg", NULL);
    map->tower_pos_text = sfTexture_createFromFile("utils/imgs/tower_pos.jpg",
                                                    NULL);
    map->grass = sfSprite_create();
    map->soil = sfSprite_create();
    map->tower_pos = sfSprite_create();
    map->donjon_text = sfTexture_createFromFile(
                                            "utils/imgs/dungeon.png", NULL);
    map->donjon = sfSprite_create();
    map->stairs_text = sfTexture_createFromFile(
                                            "utils/imgs/stairs.png", NULL);
    map->stairs = sfSprite_create();
    init_minimap(map);
    if (!map->soil || !map->tower_pos || !map->grass ||
    !map->tower_pos_text || !map->soil_text || !map->grass_text ||
    !map->donjon || !map->donjon_text)
        return 84;
    set_texture_map(map);
    map->map_pars = map_generator();
    map->open_map = false;
    map->wait_for_it = 0;
    return 0;
}
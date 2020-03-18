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
}

int init_map(map_t *map, char **av)
{
    map->grass_text = sfTexture_createFromFile("utils/imgs/grass.png", NULL);
    map->soil_text = sfTexture_createFromFile("utils/imgs/soil.jpg", NULL);
    map->tower_pos_text = sfTexture_createFromFile("utils/imgs/tower_pos.jpg",
                                                    NULL);
    map->mini_map_text = sfTexture_createFromFile("utils/imgs/red_minimap.png",
                                                NULL);
    map->mini_map = sfSprite_create();
    map->grass = sfSprite_create();
    map->soil = sfSprite_create();
    map->tower_pos = sfSprite_create();
    if (!map->soil || !map->tower_pos || !map->grass ||
    !map->tower_pos_text || !map->soil_text || !map->grass_text ||
    !map->mini_map || !map->mini_map_text)
        return 84;
    set_texture_map(map);
    map->map_pars = map_generator();
    return 0;
}
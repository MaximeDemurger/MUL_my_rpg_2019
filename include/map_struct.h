/*
** EPITECH PROJECT, 2020
** mapstruct
** File description:
** map struct
*/

#ifndef MAP_STRUCT_H
#define MAP_STRUCT_H

#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "SFML/System/Export.h"
#include "SFML/System/Time.h"
#include "SFML/System/Types.h"
#include <stdbool.h>

typedef struct map_s {
    sfTexture *grass_text;
    sfTexture *soil_text;
    sfTexture *tower_pos_text;
    sfSprite *tower_pos;
    sfSprite *grass;
    sfSprite *soil;
    sfTexture *mini_map_text;
    sfSprite *mini_map;
    sfTexture *mini_soil_text;
    sfSprite *mini_soil;
    sfTexture *mini_grass_text;
    sfSprite *mini_grass;
    sfTexture *mini_tower_text;
    sfSprite *mini_tower;
    char **map_pars;
    bool open_map;
    int wait_for_it;
} map_t;


#endif /* !MAP_STRUCT_H */

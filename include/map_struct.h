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

typedef struct map_s {
    sfTexture *grass_text;
    sfTexture *soil_text;
    sfTexture *tower_pos_text;
    sfSprite *tower_pos;
    sfSprite *grass;
    sfSprite *soil;
    char **map_pars;
} map_t;


#endif /* !MAP_STRUCT_H */

/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** main struct
*/

#ifndef MAIN_STRUCT
#define MAIN_STRUCT

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <SFML/System/Types.h>
#include <stdbool.h>

typedef struct game_s {
    struct utils_s *utils;
    struct startmenu_s *startmenu;
} game_t;

typedef struct startmenu_s {
    sfSprite *background_sprite;
    sfTexture *background_texture;
    sfSprite *start_sprite;
    sfTexture *start_texture;
    sfSprite *quit_sprite;
    sfTexture *quit_texture;
} startmenu_t;

typedef struct utils_s {
    sfRenderWindow *window;
    sfEvent event;
    bool pause;
    bool death;
    bool in_start;
    int life;
} utils_t;

#endif /* !MAIN_STRUCT */

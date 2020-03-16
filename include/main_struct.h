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
    sfSprite *background;
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

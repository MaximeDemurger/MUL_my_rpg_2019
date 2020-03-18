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
    struct achivs_s *achiv;
    struct map_s *map;
    struct enemys_s *ene;
    struct play_s *play;
} game_t;

typedef struct startmenu_s {
    sfSprite *background_sprite;
    sfTexture *background_texture;
    sfSprite *start_sprite;
    sfTexture *start_texture;
    sfSprite *quit_sprite;
    sfTexture *quit_texture;
    sfTexture *start_texture_highlight;
    sfTexture *quit_texture_highlight;
} startmenu_t;

typedef struct utils_s {
    sfRenderWindow *window;
    sfEvent event;
    bool in_pause;
    bool death;
    bool in_start;
    bool in_game;
    int life;
} utils_t;

#endif /* !MAIN_STRUCT */

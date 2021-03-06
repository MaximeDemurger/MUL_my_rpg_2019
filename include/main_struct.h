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
    struct pausemenu_s *pausemenu;
    struct achivs_s *achiv;
    struct map_s *map;
    struct enemys_s *ene;
    struct keys_s *key;
    struct play_s *play;
    struct inventory_s *inv;
    struct dungeon_s *dungeon;
    struct pnj_s *pnj;
    struct select_s *select;
    struct score_s *score;
    struct high_s *high;
    struct food_s *food;
    struct settings_s *settings;
    struct howto_s *how_to;
    struct death_screen_s *death_screen;
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

typedef struct settings_s {
    sfTexture *settings_texture_highlight;
    sfTexture *settings_texture;
    sfSprite *settings_sprite;
    sfSprite *circle_sprite;
    sfSprite *bar_sprite;
    sfTexture *circle_texture;
    sfTexture *bar_texture;
    bool is_dragging;
} settings_t;

typedef struct death_screen_s {
    sfText *death_text;
} death_screen_t;

typedef struct pausemenu_s {
    sfSprite *background_sprite;
    sfSprite *start_sprite;
    sfSprite *main_sprite;
    sfTexture *main_texture;
    sfSprite *quit_sprite;
    sfTexture *start_texture_highlight;
    sfTexture *quit_texture_highlight;
    sfTexture *main_texture_highlight;
} pausemenu_t;

typedef struct utils_s {
    sfRenderWindow *window;
    sfEvent event;
    bool in_pause;
    bool death;
    bool in_start;
    bool in_game;
    bool in_settings;
    bool lvl_selection;
    bool in_how_to;
    bool in_dungeon;
    sfMusic *back_music;
    int heart;
    float width;
    float height;
    bool new_high;
    char *current_high;
}utils_t;

typedef struct howto_s {
    sfTexture *how_to_texture;
    sfSprite *how_to_sprite;
    sfTexture *background_texture;
    sfSprite *background_sprite;
    sfFont *font;
    sfText *text;
    sfTexture *esc_texture;
    sfSprite *esc_sprite;
    sfFont *font_esc;
    sfText *text_esc;
    sfFont *font_key;
    sfText *text_key;
    sfTexture *key_texture;
    sfSprite *key_sprite;
    sfFont *font_p;
    sfText *text_p;
    sfTexture *p_texture;
    sfSprite *p_sprite;
    sfFont *font_m;
    sfText *text_m;
    sfTexture *m_texture;
    sfSprite *m_sprite;
    sfFont *font_a;
    sfText *text_a;
    sfFont *font_rules;
    sfText *text_rules;
    sfTexture *a_texture;
    sfSprite *a_sprite;
    sfFont *font_rules_first;
    sfText *text_rules_first;
    sfFont *font_rules_second;
    sfText *text_rules_second;
}howto_t;

#endif /* !MAIN_STRUCT */

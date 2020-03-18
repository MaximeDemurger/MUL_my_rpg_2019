/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** my.h
*/

#ifndef PROTO
#define PROTO

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include <math.h>
#include "main_struct.h"
#include "map_struct.h"
#include "achivement.h"
#include "enemy.h"
#include "keys.h"
#include "play_struct.h"

#ifndef READ_SIZE
#define READ_SIZE 4096
#endif

/* MAIN GAME */
void capture_events(utils_t *, game_t *);
int open_window(utils_t *, game_t *);

/* start menu */
int display_startmenu(utils_t *utils, startmenu_t *startmenu);
int init_startmenu(startmenu_t *startmenu);
int init_highlight(startmenu_t *startmenu);
int display_highlight_start(startmenu_t *startmenu, sfVector2i pos);
int display_highlight_quit(startmenu_t *startmenu, sfVector2i pos);
int go_to_game(utils_t *utils);
void event_start_menu(utils_t *utils);

/* MAP */
char **map_generator(void);
int init_map(map_t *map, char **av);
void printing_map(game_t *game);
void mini_map(game_t *game);

/* GAME */
void draw_player(play_t *play, utils_t *utils);
int init_gameplay(play_t *play);

/* pause menu */
int init_pausemenu(game_t *game);
int display_pausemenu(game_t *game);

/* ACHIVEMENTS */
void draw_achivement(utils_t *, achiv_t *);
void talked(utils_t *, achiv_t *);
void draw_indicators(utils_t *, achiv_t *);
void not_talked(utils_t *, achiv_t *);
void draw_talked(utils_t *, achiv_t *);
void check_last_indic(utils_t *, achiv_t *);
int init_achivement(achiv_t *);

/* ENEMYS */
void enemy_move(game_t *, enemy_t *, sfVector2f);
void init_enemy(enemy_t **, size_t);
void draw_enemys(utils_t *, enemy_t *);

/* KEYS */
void init_keys(keys_t **);
void draw_keys(utils_t *, keys_t *);

/* LIB FUNCTIONS */
char *convert_to_string(int);
char *my_revstr(char *);
int my_strlen(char const *);
char *my_strdup(char const *str);
char *get_next_line(int fd);
char **my_str_to_word_array(char const *str, char separator);

#endif /* !PROTO */

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
#include <stddef.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "main_struct.h"
#include "map_struct.h"
#include "achivement.h"
#include "enemy.h"
#include "keys.h"
#include "play_struct.h"
#include "inventory.h"
#include "dungeon.h"
#include "ancient.h"
#include "selection.h"
#include "highscores.h"
#include "food.h"

#ifndef READ_SIZE
#define READ_SIZE 4096
#endif

/* MAIN GAME */
void capture_events(utils_t *, game_t *);
int open_window(utils_t *, game_t *);

/* SELECTION */
void display_selection(utils_t *, select_t *);
int init_selection(select_t *);

/* HIGHSCORE */
int get_high_scores(high_t *);
int add_new_score(high_t *, char const *);

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
int init_map(map_t *map);
void printing_map(game_t *game);
void print_minimap(game_t *game);
int check_map(play_t *play, keys_t *keys, enemy_t *ene);
int check_map_next(play_t *play, keys_t *keys, enemy_t *ene);
void check_mini_next(char a, utils_t *utils, map_t *map, sfVector2f pos);
char **put_donjon(char **tab);

/* GAME */
void draw_player(play_t *play, utils_t *utils, game_t *game);
int get_path(char **tab, map_t *map);
int init_gameplay(play_t *play);

/* pause menu */
int init_pausemenu(game_t *game);
int display_pausemenu(game_t *game);
int create_highlights(game_t *game);
int display_highlight(game_t *game);
int display_highlight_start_pause(pausemenu_t *pausemenu, sfVector2i pos, startmenu_t *startmenu);
int display_highlight_quit_pause(pausemenu_t *pausemenu, sfVector2i pos, startmenu_t *startmenu);
int display_highlight_main_pause(pausemenu_t *pausemenu, sfVector2i pos, startmenu_t *startmenu);

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

/* FOOD */
int init_food(food_t **);
void draw_food(utils_t *, food_t *);

/* KEYS */
void init_keys(keys_t **);
void draw_keys(utils_t *, keys_t *);
void pick_up_keys(keys_t **, sfVector2f, achiv_t *);

/* INVENTORY */
int init_inventory(inv_t *);
void draw_inventory(utils_t *, inv_t *, achiv_t *);

/* ANCIENT */
int init_ancient(pnj_t *);
void draw_ancient(utils_t *, pnj_t *);
void do_interaction(utils_t *, game_t *);

/* LIB FUNCTIONS */
char *convert_to_string(int);
char *my_revstr(char *);
int my_strlen(char const *);
char *my_strdup(char const *str);
char *get_next_line(int fd);
char **my_str_to_word_array(char const *str, char separator);
char *my_itoa(int nb);
int calc_int_len(int nb);
int my_atoi(char const *);

/*player*/
int dungeon_pos(play_t *play, map_t *map);
int player_move(play_t *play, utils_t *utils, map_t *map);
int movement_player_x(play_t *play, utils_t *utils, map_t *map);
int movement_player_y(play_t *play, utils_t *utils, map_t *map);
void move_rect_down(play_t *play);
void move_rect_up(play_t *play);
int destroy_heart(play_t *play, utils_t *utils);
int destroy_heart_next(play_t *play, utils_t *utils);
int set_position_heart(play_t *play);
int set_texture_heart(play_t *play);
int display_heart(play_t *play, utils_t *utils);
int destroy_heart_next_two(play_t *play, utils_t *utils);
int destroy_heart_next(play_t *play, utils_t *utils);
int attack_enemis(play_t *play, utils_t *utils, enemy_t *ene);
int create_texture_attack(play_t *play, utils_t *utils);

/* DUNGEON */
int init_dungeon(dungeon_t *dungeon);
int print_dungeon(utils_t *utils, dungeon_t *dungeon);

/*score*/
int init_score_game(game_t *game);
int display_score(game_t *game);
int score(game_t *game);
int update_score(game_t *game);

#endif /* !PROTO */

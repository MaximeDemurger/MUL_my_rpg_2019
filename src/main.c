/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** main
*/

#include "my.h"

int init_game_next(game_t *game, char **av)
{
    if (!game->utils || !game->startmenu || !game->achiv || !game->pnj
        || !game->play || !game->map || !game->inv || !game->dungeon ||
        !game->select || !game->score)
        return 1;
    init_settings(game);
    init_startmenu(game->startmenu);
    init_pausemenu(game);
    init_text_how_to(game);
    how_to_escape_button(game);
    keybord_key_button(game);
    if (init_achivement(game->achiv) || init_map(game->map) ||
        init_gameplay(game->play) || init_inventory(game->inv) ||
        init_ancient(game->pnj) || init_selection(game->select)
        || score(game) || get_high_scores(game->high) ||
        init_dungeon(game->dungeon) || init_how_to(game->how_to))
        return 1;
    create_texture_attack(game->play, game->utils);
    game->utils->in_start = true;
    game->utils->width = 1920;
    game->utils->height = 1080;
    game->dungeon->all_achiv = 1;
    return 0;
}

int init_game(game_t *game, char **av)
{
    game->utils = malloc(sizeof(utils_t));
    game->startmenu = malloc(sizeof(startmenu_t));
    game->pausemenu = malloc(sizeof(pausemenu_t));
    game->achiv = malloc(sizeof(achiv_t));
    game->map = malloc(sizeof(map_t));
    game->play = malloc(sizeof(play_t));
    game->inv = malloc(sizeof(inv_t));
    game->dungeon = malloc(sizeof(dungeon_t));
    game->pnj = malloc(sizeof(pnj_t));
    game->select = malloc(sizeof(select_t));
    game->score = malloc(sizeof(score_t));
    game->settings = malloc(sizeof(settings_t));
    game->how_to = malloc(sizeof(howto_t));
    game->death_screen = malloc(sizeof(death_screen_t));
    game->high = NULL;
    if (init_game_next(game, av) == 1)
        return 1;
    return 0;
}

int main(int ac, char **av)
{
    game_t *game = malloc(sizeof(game_t));
    sfVideoMode view_mode = {1920, 1080, 32};

    if (init_game(game, av))
        return 84;
    game->dungeon->all_achiv = 1;
    game->utils->window = sfRenderWindow_create(view_mode, "MY RPG",
                    sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->utils->window, 30);
    open_window(game->utils, game);
    return 0;
}
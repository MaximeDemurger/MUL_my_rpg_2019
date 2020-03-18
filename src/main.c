/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** main
*/

#include "my.h"

int init_game(game_t *game, char **av)
{
    game->utils = malloc(sizeof(utils_t));
    game->startmenu = malloc(sizeof(startmenu_t));
    game->achiv = malloc(sizeof(achiv_t));
    game->map = malloc(sizeof(map_t));
    game->play = malloc(sizeof(play_t));

    if (!game->utils || !game->startmenu || !game->achiv ||
        !game->play || !game->map)
        return 1;
    init_startmenu(game->startmenu);
    if (init_achivement(game->achiv) || init_map(game->map, av) ||
        init_gameplay(game->play))
        return 1;
    game->utils->in_start = true;
    return 0;
}

int main(int ac, char **av)
{
    game_t *game = malloc(sizeof(game_t));
    sfVideoMode view_mode = {1920, 1080, 32};

    if (init_game(game, av))
        return 84;
    game->utils->window = sfRenderWindow_create(view_mode, "MY RPG",
                    sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->utils->window, 30);
    open_window(game->utils, game);
    return 0;
}
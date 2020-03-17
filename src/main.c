/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** main
*/

#include "my.h"

int init_game(game_t *game)
{
    game->utils = malloc(sizeof(utils_t));
    game->startmenu = malloc(sizeof(startmenu_t));
    game->achiv = malloc(sizeof(achiv_t));

    if (!game->utils || !game->startmenu || !game->achiv)
        return 1;
    init_startmenu(game->startmenu);
    if (init_achivement(game->achiv))
        return 1;
    game->utils->in_start = true;
    return 0;
}

int main(int ac, char **av)
{
    game_t *game = malloc(sizeof(game_t));
    sfVideoMode view_mode = {1920, 1080, 32};

    if (init_game(game))
        return 84;
    game->utils->window = sfRenderWindow_create(view_mode, "MY RPG",
                    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->utils->window, 30);
    open_window(game->utils, game);
    return 0;
}
/*
** EPITECH PROJECT, 2020
** display
** File description:
** display
*/

#include "my.h"

int display_pausemenu(game_t *game)
{
    sfRenderWindow_clear(game->utils->window, sfBlack);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->pausemenu->background_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->pausemenu->start_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->pausemenu->quit_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->pausemenu->main_sprite, NULL);
    return 0;
}
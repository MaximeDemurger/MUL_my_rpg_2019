/*
** EPITECH PROJECT, 2020
** print_how
** File description:
** print_how
*/

#include "my.h"

int display_background_how_to(game_t *game)
{
    sfRenderWindow_drawSprite(game->utils->window,
                            game->how_to->background_sprite, NULL);
    return 0;
}
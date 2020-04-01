/*
** EPITECH PROJECT, 2020
** init
** File description:
** init
*/

#include "my.h"

int init_text(game_t *game)
{
    if (!game)
        return 84;
    game->score->font = sfFont_createFromFile("./utils/font/arial.ttf");
    if (!game->score->font)
        return 84;
    return 0;
}

int init_score_game(game_t *game)
{
    sfVector2f pos = {1650, 980};
    sfVector2f pos_text = {1800, 980};
    char *int_text = NULL;

    if (!game || init_text(game) == 84)
        return 84;
    int_text = my_itoa(game->score->score);
    game->score->live_int = sfText_create();
    game->score->live_text = sfText_create();
    sfText_setPosition(game->score->live_text, pos);
    sfText_setFont(game->score->live_text, game->score->font);
    sfText_setCharacterSize(game->score->live_text, 40);
    sfText_setString(game->score->live_text, "Score :");
    sfText_setPosition(game->score->live_int, pos_text);
    sfText_setFont(game->score->live_int, game->score->font);
    sfText_setCharacterSize(game->score->live_int, 40);
    sfText_setString(game->score->live_int, int_text);
    return 0;
}
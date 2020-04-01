/*
** EPITECH PROJECT, 2020
** score
** File description:
** score
*/

#include "my.h"

int display_score_end(game_t *game)
{
    if (!game)
        return 84;
    sfRenderWindow_drawText(game->utils->window, game->score->live_text, NULL);
    sfRenderWindow_drawText(game->utils->window, game->score->live_int, NULL);
    return 0;
}

int display_score(game_t *game)
{
    if (!game)
        return 84;
    update_score(game);
    sfRenderWindow_drawText(game->utils->window, game->score->live_text, NULL);
    sfRenderWindow_drawText(game->utils->window, game->score->live_int, NULL);
    return 0;
}

int score(game_t *game)
{
    if (!game || init_score_game(game) == 84)
        return 84;
    return 0;
}

int update_score(game_t *game)
{
    game->score->score += 0.2;
    char *int_text = my_itoa(game->score->score);
    sfText_setString(game->score->live_int, int_text);
    return 0;
}
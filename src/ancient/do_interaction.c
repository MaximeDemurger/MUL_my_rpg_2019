/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** do interaction
*/

#include "my.h"

int player_in_range(pnj_t *pnj, play_t *play)
{
    if ((float)play->x_play > pnj->pos.x - 100 &&
        (float)play->x_play < pnj->pos.x + 100 &&
        (float)play->y_play > pnj->pos.y - 100 &&
        (float)play->y_play < pnj->pos.y + 100)
        return 1;
    return 0;
}

void interactions(utils_t *utils, game_t *game, sfText *interact)
{
    if (game->pnj->is_talking == true) {
        sfText_setString(interact, "Press N to see more");
        sfText_setString(game->pnj->text, game->pnj->dialog[game->pnj->index]);
        sfRenderWindow_drawSprite(utils->window, game->pnj->bulle, NULL);
        sfRenderWindow_drawText(utils->window, interact, NULL);
        sfRenderWindow_drawText(utils->window, game->pnj->text, NULL);
    }
    if (game->pnj->index >= 7) {
        game->pnj->is_talking = false;
        game->pnj->index = 0;
        game->achiv->png_talked = true;
    }
}

void do_interaction(utils_t *utils, game_t *game)
{
    sfText *interact = sfText_create();
    sfVector2f pos = {450, 250};

    if (!interact)
        return;
    sfText_setFont(interact, game->pnj->font);
    sfText_setPosition(interact, pos);
    sfText_setColor(interact, sfBlack);
    if (player_in_range(game->pnj, game->play))
        game->pnj->in_range = true;
    else {
        game->pnj->in_range = false;
        game->pnj->is_talking = false;
    }
    if (game->pnj->in_range == true && game->pnj->is_talking == false) {
        sfText_setString(interact, "Press E to talk to the ancient");
        sfRenderWindow_drawText(utils->window, interact, NULL);
    }
    interactions(utils, game, interact);
}
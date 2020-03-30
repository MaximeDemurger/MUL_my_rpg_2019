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

void do_interaction(utils_t *utils, pnj_t *pnj, play_t *play)
{
    sfText *interact = sfText_create();

    if (!interact)
        return;
    sfText_setFont(interact, pnj->font);
    sfText_setPosition(interact, pnj->pos);
    if (player_in_range(pnj, play))
        pnj->in_range = true;
    else {
        pnj->in_range = false;
        pnj->is_talking = false;
    }
    if (pnj->in_range == true && pnj->is_talking == false) {
        sfText_setString(interact, "Press E to talk to the ancient");
        sfRenderWindow_drawText(utils->window, interact, NULL);
    }
    if (pnj->is_talking == true) {
        sfText_setString(interact, "Press N to see more");
        sfText_setString(pnj->text, pnj->dialog[pnj->index]);
        sfRenderWindow_drawText(utils->window, interact, NULL);
        sfRenderWindow_drawText(utils->window, pnj->text, NULL);
    }
    if (pnj->index >= 7) {
        pnj->is_talking = false;
        pnj->index = 0;
    }
}
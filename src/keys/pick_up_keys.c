/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** pick up keys
*/

#include "my.h"

int player_inrange(sfVector2f player_pos, keys_t *keys)
{
    if (player_pos.x > keys->pos.x - 50 &&
        player_pos.x < keys->pos.x + 50 &&
        player_pos.y > keys->pos.y - 50 &&
        player_pos.y < keys->pos.y + 50) {
        return 1;
    }
    return 0;
}

int my_delete_nodes(keys_t **begin, sfVector2f player_pos)
{
    keys_t *tmp = *begin;
    keys_t *next = *begin;

    if (tmp == NULL)
        return 0;
    if (player_inrange(player_pos, *begin)) {
        (*begin) = (*begin)->next;
        return 1;
    }
    next = tmp->next;
    while (tmp && next) {
        if (player_inrange(player_pos, next)) {
            tmp->next = next->next;
            free(next);
            return 1;
        }
        tmp = next;
        next = next->next;
    }
    return 0;
}

void pick_up_keys(keys_t **keys, sfVector2f player_pos, achiv_t *achiv)
{
    if (my_delete_nodes(keys, player_pos))
        achiv->player_keys++;
}
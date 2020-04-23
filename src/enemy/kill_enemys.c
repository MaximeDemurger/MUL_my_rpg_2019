/*
** EPITECH PROJECT, 2020
** my rpg 
** File description:
** kill enemys
*/

#include "my.h"

int my_delete_enemys(enemy_t **begin)
{
    enemy_t *tmp = *begin;
    enemy_t *next = *begin;

    if (tmp == NULL)
        return 0;
    if ((*begin)->heart <= 0) {
        (*begin) = (*begin)->next;
        return 1;
    }
    next = tmp->next;
    while (tmp && next) {
        if (next->heart <= 0) {
            tmp->next = next->next;
            free(next);
            return 1;
        }
        tmp = next;
        next = next->next;
    }
    return 0;
}

void kill_enemys(enemy_t **ene, achiv_t *achiv)
{
    if (my_delete_enemys(ene)) {
        achiv->player_gold += 5;
        achiv->player_kills++;
    }
}
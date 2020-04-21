/*
** EPITECH PROJECT, 2020
** food
** File description:
** food
*/

#include "my.h"

int player_inrange_food(sfVector2f player_pos, food_t *food)
{
    if (player_pos.x > food->pos.x - 50 &&
        player_pos.x < food->pos.x + 50 &&
        player_pos.y > food->pos.y - 50 &&
        player_pos.y < food->pos.y + 50) {
        return 1;
    }
    return 0;
}

int my_delete_food(food_t **begin, sfVector2f player_pos)
{
    food_t *tmp = *begin;
    food_t *next = *begin;

    if (!tmp)
        return 0;
    if (player_inrange_food(player_pos, *begin)) {
        (*begin) = (*begin)->next;
        return 1;
    }
    next = tmp->next;
    while (tmp && next) {
        if (player_inrange_food(player_pos, next)) {
            tmp->next = next->next;
            free(next);
            return 1;
        }
        tmp = next;
        next = next->next;
    }
    return 0;
}

void pick_up_food(food_t **foods, sfVector2f player_pos, play_t *play)
{
    if (play->life <= 4.00) {
        if (my_delete_food(foods, player_pos))
            play->life += 1;
    }
}
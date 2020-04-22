/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** final_score.c
*/

#include "my.h"

int is_highscore(high_t *high, char const *new_score)
{
    if (my_int_cmp(high->score, new_score) > 0)
        return 0;
    else
        return 1;
}
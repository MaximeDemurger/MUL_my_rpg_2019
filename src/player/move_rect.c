/*
** EPITECH PROJECT, 2020
** move
** File description:
** miove
*/

#include "my.h"

void move_rect_up(play_t *play)
{
    if (play->rect.top < 450)
        play->rect.top += 250;
    else
        play->rect.top = 0;
}
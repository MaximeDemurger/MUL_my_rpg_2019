/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** move enemys
*/

#include "my.h"

float vector_dist(sfVector2f dir)
{
    float x = dir.x;
    float y = dir.y;
    float res = sqrt(x * x + y * y);

    return (res);
}

sfVector2f normalize_vector(sfVector2f dir)
{
    float len = vector_dist(dir);

    dir.x = dir.x / len;
    dir.y = dir.y / len;
    return (dir);
}

void get_angle(sfSprite *sprite, sfVector2f dir)
{
    float pi = 3.141592653589;
    float angle = asin(dir.y / vector_dist(dir)) * 180 / pi;

    if (dir.x < 0) {
        angle += 180;
        angle *= (-1);
    }
    sfSprite_setRotation(sprite, angle);
}

void enemy_move(game_t *game, enemy_t *enemy, sfVector2f player)
{
    enemy_t *current = enemy;

    while (current) {
        current->dir.x = player.x - current->pos.x;
        current->dir.y = player.y - current->pos.y;
        get_angle(current->sprite, current->dir);
        if (sfClock_getElapsedTime(current->clock).microseconds
            / 1000000.0 >= 0.001 && vector_dist(current->dir) <= 200 &&
            vector_dist(current->dir) >= 45) {
            if (vector_dist(current->dir) <= 55)
                game->play->life-= 0.1;
            current->dir = normalize_vector(current->dir);
            current->pos.x += current->dir.x;
            current->pos.y += current->dir.y;
            sfClock_restart(current->clock);
        }
        sfSprite_setPosition(current->sprite, current->pos);
        current = current->next;
    }
}
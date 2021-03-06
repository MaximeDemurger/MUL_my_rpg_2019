/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** init enemy
*/

#include "my.h"

enemy_t *add_elem(enemy_t *elem)
{
    enemy_t *tmp = malloc(sizeof(enemy_t));
    sfVector2f offset;
    sfVector2f origin = {225, 127};

    //srand(time(NULL));
    offset.x = rand() % 1650;
    offset.y = rand() % 900;
    if (!tmp)
        return NULL;
    tmp->heart = 100;
    tmp->texture = sfTexture_createFromFile("assets/monstre.png", NULL);
    tmp->sprite = sfSprite_create();
    tmp->clock = sfClock_create();
    tmp->pos = offset;
    if (!tmp->texture || !tmp->sprite)
        return NULL;
    sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
    sfSprite_setPosition(tmp->sprite, tmp->pos);
    sfSprite_setOrigin(tmp->sprite, origin);
    tmp->next = elem;
    return tmp;
}

void init_enemy(enemy_t **ene, size_t nb)
{
    size_t i = 0;

    (*ene) = NULL;
    while (i < nb) {
        (*ene) = add_elem(*ene);
        i++;
    }
}
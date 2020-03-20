/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** init keys
*/

#include "my.h"

keys_t *add_key(keys_t *elem)
{
    keys_t *tmp = malloc(sizeof(keys_t));
    sfVector2f pos;

    if (!tmp)
        return NULL;
    pos.x = rand() % 1800;
    pos.y = rand() % 900;
    tmp->texture = sfTexture_createFromFile("assets/key.png", NULL);
    tmp->sprite = sfSprite_create();
    if (!tmp->texture || !tmp->sprite)
        return NULL;
    tmp->pos = pos;
    sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
    sfSprite_setPosition(tmp->sprite, tmp->pos);
    tmp->next = elem;
    return tmp;
}

void init_keys(keys_t **key)
{
    int num = rand() % 10;
    int keys = 0;
    int index = 0;

    if (*key)
        *key = NULL;
    if (num == 1 || num == 5 || num == 9)
        keys = 1;
    if (num == 7)
        keys = 2;
    if (num == 8)
        keys = 3;
    while (index < keys) {
        (*key) = add_key((*key));
        index++;
    }
}
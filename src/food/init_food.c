/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** init_heart
*/

#include "my.h"

food_t *add_food(food_t *food)
{
    food_t *tmp = malloc(sizeof(food_t));
    sfVector2f pos;

    if (!tmp)
        return NULL;
    pos.x = rand() % 1800;
    pos.y = rand() % 900;
    tmp->texture = sfTexture_createFromFile("assets/food.png", NULL);
    tmp->sprite = sfSprite_create();
    if (!tmp->sprite || !tmp->texture)
        return NULL;
    tmp->pos = pos;
    sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
    sfSprite_setPosition(tmp->sprite, tmp->pos);
    tmp->next = food;
    return tmp;
}

int init_food(food_t **food)
{
    int nb = rand() % 5;

    while (nb > 0) {
        *food = add_food(*food);
        nb--;
    }
    return 0;
}
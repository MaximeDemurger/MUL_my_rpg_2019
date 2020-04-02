/*
** EPITECH PROJECT, 2020
** player
** File description:
** player
*/

#include "my.h"

int set_position_life(play_t *play, utils_t *utils)
{
    sfVector2f pos_one = {850, 1000};
    sfVector2f pos_two = {900, 1000};
    sfVector2f pos_three = {950, 1000};
    sfVector2f pos_four = {1000, 1000};
    sfVector2f pos_five = {1050, 1000};

    sfSprite_setPosition(play->one, pos_one);
    sfSprite_setPosition(play->two, pos_two);
    sfSprite_setPosition(play->three, pos_three);
    sfSprite_setPosition(play->four, pos_four);
    sfSprite_setPosition(play->five, pos_five);
    return 0;
}

int display_life_next(play_t *play, utils_t *utils)
{
    set_position_life(play, utils);
    sfRenderWindow_drawSprite(utils->window, play->one, NULL);
    sfSprite_setTexture(play->two, play->texture_two, sfTrue);
    sfRenderWindow_drawSprite(utils->window, play->two, NULL);
    sfSprite_setTexture(play->three, play->texture_three, sfTrue);
    sfRenderWindow_drawSprite(utils->window, play->three, NULL);
    sfSprite_setTexture(play->four, play->texture_four, sfTrue);
    sfRenderWindow_drawSprite(utils->window, play->four, NULL);
    sfSprite_setTexture(play->five, play->texture_five, sfTrue);
    sfRenderWindow_drawSprite(utils->window, play->five, NULL);
    return 0; 
}

int display_life(play_t *play, utils_t *utils)
{
    sfVector2f scale = {0.15, 0.15};

    play->one = sfSprite_create();
    play->two = sfSprite_create();
    play->three = sfSprite_create();
    play->four = sfSprite_create();
    play->five = sfSprite_create();
    play->texture_one = sfTexture_createFromFile("utils/imgs/heart.png", NULL);
    play->texture_two = sfTexture_createFromFile("utils/imgs/heart.png", NULL);
    play->texture_three = sfTexture_createFromFile("utils/imgs/heart.png", NULL);
    play->texture_four = sfTexture_createFromFile("utils/imgs/heart.png", NULL);
    play->texture_five = sfTexture_createFromFile("utils/imgs/heart.png", NULL);
    sfSprite_setScale(play->one, scale);
    sfSprite_setScale(play->two, scale);
    sfSprite_setScale(play->three, scale);
    sfSprite_setScale(play->four, scale);
    sfSprite_setScale(play->five, scale);
    sfSprite_setTexture(play->one, play->texture_one, sfTrue);
    display_life_next(play, utils);
    return 0;
}
/*
** EPITECH PROJECT, 2020
** player
** File description:
** player
*/

#include "my.h"

int set_texture_life(play_t *play, utils_t *utils)
{
    sfSprite_setTexture(play->one, play->texture_one, sfTrue);
    sfSprite_setTexture(play->two, play->texture_two, sfTrue);
    sfSprite_setTexture(play->three, play->texture_three, sfTrue);
    sfSprite_setTexture(play->four, play->texture_four, sfTrue);
    sfSprite_setTexture(play->five, play->texture_five, sfTrue);
    sfSprite_setTexture(play->empty_one, play->empty_texture_one, sfTrue);
    sfSprite_setTexture(play->empty_two, play->empty_texture_two, sfTrue);
    sfSprite_setTexture(play->empty_three, play->empty_texture_three, sfTrue);
    sfSprite_setTexture(play->empty_four, play->empty_texture_four, sfTrue);
    sfSprite_setTexture(play->empty_five, play->empty_texture_five, sfTrue);
    return 0;
}

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
    sfSprite_setPosition(play->empty_one, pos_one);
    sfSprite_setPosition(play->empty_two, pos_two);
    sfSprite_setPosition(play->empty_three, pos_three);
    sfSprite_setPosition(play->empty_four, pos_four);
    sfSprite_setPosition(play->empty_five, pos_five);
    return 0;
}

int create_sprite(play_t *play)
{
    play->one = sfSprite_create();
    play->two = sfSprite_create();
    play->three = sfSprite_create();
    play->four = sfSprite_create();
    play->five = sfSprite_create();
    play->empty_one = sfSprite_create();
    play->empty_two = sfSprite_create();
    play->empty_three = sfSprite_create();
    play->empty_four = sfSprite_create();
    play->empty_five = sfSprite_create();
}

int create_texture(play_t *play)
{
    play->texture_one = sfTexture_createFromFile("utils/imgs/heart.png", NULL);
    play->texture_two = sfTexture_createFromFile("utils/imgs/heart.png", NULL);
    play->texture_three =
        sfTexture_createFromFile("utils/imgs/heart.png", NULL);
    play->texture_four
        = sfTexture_createFromFile("utils/imgs/heart.png", NULL);
    play->texture_five
        = sfTexture_createFromFile("utils/imgs/heart.png", NULL);
        
    play->empty_texture_one =
        sfTexture_createFromFile("utils/imgs/empty_heart.png", NULL);
    play->empty_texture_two =
        sfTexture_createFromFile("utils/imgs/empty_heart.png", NULL);
    play->empty_texture_three =
        sfTexture_createFromFile("utils/imgs/empty_heart.png", NULL);
    play->empty_texture_four
        = sfTexture_createFromFile("utils/imgs/empty_heart.png", NULL);
    play->empty_texture_five
        = sfTexture_createFromFile("utils/imgs/empty_heart.png", NULL);
    return 0;
}

int display_life(play_t *play, utils_t *utils)
{
    sfVector2f scale = {0.15, 0.15};
    sfVector2f scale_empty = {0.15, 0.15};

    create_sprite(play);
    create_texture(play);
    sfSprite_setScale(play->one, scale);
    sfSprite_setScale(play->two, scale);
    sfSprite_setScale(play->three, scale);
    sfSprite_setScale(play->four, scale);
    sfSprite_setScale(play->five, scale);
    sfSprite_setScale(play->empty_one, scale_empty);
    sfSprite_setScale(play->empty_two, scale_empty);
    sfSprite_setScale(play->empty_three, scale_empty);
    sfSprite_setScale(play->empty_four, scale_empty);
    sfSprite_setScale(play->empty_five, scale_empty);
    set_position_life(play, utils);
    set_texture_life(play, utils);
    destroy_heart(play, utils);
    return 0;
}
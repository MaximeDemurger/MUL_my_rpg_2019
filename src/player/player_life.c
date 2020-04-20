/*
** EPITECH PROJECT, 2020
** player
** File description:
** player
*/

#include "my.h"

int set_texture_heart(play_t *play)
{
    sfSprite_setTexture(play->heart->one, play->heart->texture_one, sfTrue);
    sfSprite_setTexture(play->heart->two, play->heart->texture_two, sfTrue);
    sfSprite_setTexture(play->heart->three, play->heart->texture_three,
        sfTrue);
    sfSprite_setTexture(play->heart->four, play->heart->texture_four, sfTrue);
    sfSprite_setTexture(play->heart->five, play->heart->texture_five, sfTrue);
    sfSprite_setTexture(play->heart->empty_one,
        play->heart->empty_texture_one, sfTrue);
    sfSprite_setTexture(play->heart->empty_two,
        play->heart->empty_texture_two, sfTrue);
    sfSprite_setTexture(play->heart->empty_three,
        play->heart->empty_texture_three, sfTrue);
    sfSprite_setTexture(play->heart->empty_four,
        play->heart->empty_texture_four, sfTrue);
    sfSprite_setTexture(play->heart->empty_five,
        play->heart->empty_texture_five, sfTrue);
    return 0;
}

int set_position_heart(play_t *play)
{
    sfVector2f pos_one = {850, 1000};
    sfVector2f pos_two = {900, 1000};
    sfVector2f pos_three = {950, 1000};
    sfVector2f pos_four = {1000, 1000};
    sfVector2f pos_five = {1050, 1000};

    sfSprite_setPosition(play->heart->one, pos_one);
    sfSprite_setPosition(play->heart->two, pos_two);
    sfSprite_setPosition(play->heart->three, pos_three);
    sfSprite_setPosition(play->heart->four, pos_four);
    sfSprite_setPosition(play->heart->five, pos_five);
    sfSprite_setPosition(play->heart->empty_one, pos_one);
    sfSprite_setPosition(play->heart->empty_two, pos_two);
    sfSprite_setPosition(play->heart->empty_three, pos_three);
    sfSprite_setPosition(play->heart->empty_four, pos_four);
    sfSprite_setPosition(play->heart->empty_five, pos_five);
    return 0;
}

int create_sprite(play_t *play)
{
    play->heart->one = sfSprite_create();
    play->heart->two = sfSprite_create();
    play->heart->three = sfSprite_create();
    play->heart->four = sfSprite_create();
    play->heart->five = sfSprite_create();
    play->heart->empty_one = sfSprite_create();
    play->heart->empty_two = sfSprite_create();
    play->heart->empty_three = sfSprite_create();
    play->heart->empty_four = sfSprite_create();
    play->heart->empty_five = sfSprite_create();
    return 0;
}

int create_texture(play_t *play)
{
    play->heart->texture_one =
        sfTexture_createFromFile("utils/imgs/heart.png", NULL);
    play->heart->texture_two =
        sfTexture_createFromFile("utils/imgs/heart.png", NULL);
    play->heart->texture_three =
        sfTexture_createFromFile("utils/imgs/heart.png", NULL);
    play->heart->texture_four
        = sfTexture_createFromFile("utils/imgs/heart.png", NULL);
    play->heart->texture_five
        = sfTexture_createFromFile("utils/imgs/heart.png", NULL);
    play->heart->empty_texture_one =
        sfTexture_createFromFile("utils/imgs/empty_heart.png", NULL);
    play->heart->empty_texture_two =
        sfTexture_createFromFile("utils/imgs/empty_heart.png", NULL);
    play->heart->empty_texture_three =
        sfTexture_createFromFile("utils/imgs/empty_heart.png", NULL);
    play->heart->empty_texture_four
        = sfTexture_createFromFile("utils/imgs/empty_heart.png", NULL);
    play->heart->empty_texture_five
        = sfTexture_createFromFile("utils/imgs/empty_heart.png", NULL);
    return 0;
}

int display_heart(play_t *play, utils_t *utils)
{
    sfVector2f scale = {0.15, 0.15};
    sfVector2f scale_empty = {0.2, 0.2};

    create_sprite(play);
    create_texture(play);
    sfSprite_setScale(play->heart->one, scale);
    sfSprite_setScale(play->heart->two, scale);
    sfSprite_setScale(play->heart->three, scale);
    sfSprite_setScale(play->heart->four, scale);
    sfSprite_setScale(play->heart->five, scale);
    sfSprite_setScale(play->heart->empty_one, scale_empty);
    sfSprite_setScale(play->heart->empty_two, scale_empty);
    sfSprite_setScale(play->heart->empty_three, scale_empty);
    sfSprite_setScale(play->heart->empty_four, scale_empty);
    sfSprite_setScale(play->heart->empty_five, scale_empty);
    set_position_heart(play);
    set_texture_heart(play);
    destroy_heart(play, utils);
    return 0;
}
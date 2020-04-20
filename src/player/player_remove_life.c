/*
** EPITECH PROJECT, 2020
** player
** File description:
** player
*/

#include "my.h"

int destroy_heart_next_two(play_t *play, utils_t *utils)
{
    if (play->life > 0 && play->life <= 1) {
        sfRenderWindow_drawSprite(utils->window, play->heart->one, NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->empty_two, NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->empty_three,
            NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->empty_four, NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->empty_five, NULL);
    }
    else if (play->life < 0) {
        sfRenderWindow_drawSprite(utils->window, play->heart->empty_one, NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->empty_two, NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->empty_three,
            NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->empty_four, NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->empty_five, NULL);
    }
    return 0;
}

int destroy_heart_next(play_t *play, utils_t *utils)
{
    if (play->life > 2 && play->life <= 3) {
        sfRenderWindow_drawSprite(utils->window, play->heart->one, NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->two, NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->three, NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->empty_four, NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->empty_five, NULL);
    }
    if (play->life > 1 && play->life <= 2) {
        sfRenderWindow_drawSprite(utils->window, play->heart->one, NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->two, NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->empty_three,
            NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->empty_four, NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->empty_five, NULL);
    } else
        destroy_heart_next_two(play, utils);
    return 0;
}

int destroy_heart(play_t *play, utils_t *utils)
{
    set_texture_heart(play);
    if (play->life > 4 && play->life <= 5) {
        sfRenderWindow_drawSprite(utils->window, play->heart->one, NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->two, NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->three, NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->four, NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->five, NULL);
    }
    else if (play->life > 3 && play->life <= 4) {
        sfRenderWindow_drawSprite(utils->window, play->heart->one, NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->two, NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->three, NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->four, NULL);
        sfRenderWindow_drawSprite(utils->window, play->heart->empty_five, NULL);
    } else {
        destroy_heart_next(play, utils);
    }
    return 0;
}
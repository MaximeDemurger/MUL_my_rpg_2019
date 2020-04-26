/*
** EPITECH PROJECT, 2020
** attack
** File description:
** attack
*/

#include "my.h"

int enemy_inrange(enemy_t *current, float pos_x, float pos_y)
{
    if (current->pos.x > pos_x - 50 &&
        current->pos.x < pos_x + 50 &&
        current->pos.y > pos_y - 50 &&
        current->pos.y < pos_y + 50)
        return 1;
    return 0;
}

int create_texture_attack(play_t *play, utils_t *utils)
{
    play->attack->sprite_attack = sfSprite_create();
    play->attack->texture_attack =
        sfTexture_createFromFile("utils/imgs/attack.png", NULL);
    sfSprite_setTexture(play->attack->sprite_attack,
    play->attack->texture_attack, sfTrue);
    return 0;
}

int attack_enemis(play_t *play, utils_t *utils, enemy_t *ene)
{
    sfVector2f pos = {play->x_play - 85, play->y_play - 90};
    sfVector2f scale = {0.5, 0.5};

    if (!play || !utils || !ene)
        return 84;
    sfSprite_setScale(play->attack->sprite_attack, scale);
    sfSprite_setPosition(play->attack->sprite_attack, pos);
    sfRenderWindow_drawSprite(utils->window, play->attack->sprite_attack,
        NULL);
    while (ene) {
        if (enemy_inrange(ene, (float)play->x_play, (float)play->y_play)) {
            ene->heart -= 25;
        }
        ene = ene->next;
    }
    return 0;
}
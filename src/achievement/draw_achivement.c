/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** draw achivement
*/

#include "my.h"

void not_talked(utils_t *utils, achiv_t *achiv)
{
    sfVector2f txt_pos = {50, 50};

    sfText_setPosition(achiv->not_talked, txt_pos);
    sfRenderWindow_drawSprite(utils->window, achiv->back, NULL);
    sfRenderWindow_drawText(utils->window, achiv->not_talked, NULL);
}

void draw_talked(utils_t *utils, achiv_t *achiv)
{
    sfRenderWindow_drawSprite(utils->window, achiv->back, NULL);
    sfRenderWindow_drawText(utils->window, achiv->killing, NULL);
    sfRenderWindow_drawText(utils->window, achiv->keys, NULL);
    sfRenderWindow_drawText(utils->window, achiv->golds, NULL);
    sfRenderWindow_drawText(utils->window, achiv->p_killing, NULL);
    sfRenderWindow_drawText(utils->window, achiv->p_keys, NULL);
    sfRenderWindow_drawText(utils->window, achiv->p_golds, NULL);
}

void check_last_indic(utils_t *utils, achiv_t *achiv)
{
    sfVector2f pos3 = {300, 160};

    if (achiv->player_gold >= 30) {
        sfSprite_setPosition(achiv->tick, pos3);
        sfRenderWindow_drawSprite(utils->window, achiv->tick, NULL);
    } else if (achiv->player_gold < 30) {
        sfSprite_setPosition(achiv->cross, pos3);
        sfRenderWindow_drawSprite(utils->window, achiv->cross, NULL);
    }
}

void talked(utils_t *utils, achiv_t *achiv)
{
    sfVector2f kill_pos = {50, 50};
    sfVector2f key_pos = {50, 100};
    sfVector2f gold_pos = {50, 150};
    sfVector2f p_kill_pos = {260, 50};
    sfVector2f p_key_pos = {200, 100};
    sfVector2f p_gold_pos = {200, 150};

    sfText_setPosition(achiv->killing, kill_pos);
    sfText_setPosition(achiv->keys, key_pos);
    sfText_setPosition(achiv->golds, gold_pos);
    sfText_setString(achiv->p_golds, convert_to_string(achiv->player_gold));
    sfText_setString(achiv->p_killing, convert_to_string(achiv->player_kills));
    sfText_setString(achiv->p_keys, convert_to_string(achiv->player_keys));
    sfText_setPosition(achiv->p_golds, p_gold_pos);
    sfText_setPosition(achiv->p_killing, p_kill_pos);
    sfText_setPosition(achiv->p_keys, p_key_pos);
    draw_talked(utils, achiv);
    draw_indicators(utils, achiv);
}

void draw_achivement(utils_t *utils, achiv_t *achiv)
{
    if (achiv->png_talked == false)
        not_talked(utils, achiv);
    else
        talked(utils, achiv);
}
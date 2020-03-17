/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** draw achivement
*/

#include "my.h"

void not_talked(utils_t *utils, achiv_t *achiv)
{
    sfVector2f txt_pos = {100, 100};

    sfText_setPosition(achiv->not_talked, txt_pos);
    sfRenderWindow_drawText(utils->window, achiv->not_talked, NULL);
}

void draw_talked(utils_t *utils, achiv_t *achiv)
{
    sfRenderWindow_drawText(utils->window, achiv->killing, NULL);
    sfRenderWindow_drawText(utils->window, achiv->keys, NULL);
    sfRenderWindow_drawText(utils->window, achiv->golds, NULL);
    sfRenderWindow_drawText(utils->window, achiv->p_killing, NULL);
    sfRenderWindow_drawText(utils->window, achiv->p_keys, NULL);
    sfRenderWindow_drawText(utils->window, achiv->p_golds, NULL);
}

void check_last_indic(utils_t *utils, achiv_t *achiv)
{
    sfVector2f pos3 = {200, 200};

    if (achiv->player_gold >= 30) {
        sfSprite_setPosition(achiv->tick, pos3);
        sfRenderWindow_drawSprite(utils->window, achiv->tick, NULL);
    } else if (achiv->player_gold < 30) {
        sfSprite_setPosition(achiv->cross, pos3);
        sfRenderWindow_drawSprite(utils->window, achiv->cross, NULL);
    }
}

void draw_indicators(utils_t *utils, achiv_t *achiv)
{
    sfVector2f pos1 = {200, 100};
    sfVector2f pos2 = {200, 150};

    if (achiv->player_kills >= 5) {
        sfSprite_setPosition(achiv->tick, pos1);
        sfRenderWindow_drawSprite(utils->window, achiv->tick, NULL);
    } else if (achiv->player_kills < 5) {
        sfSprite_setPosition(achiv->cross, pos1);
        sfRenderWindow_drawSprite(utils->window, achiv->cross, NULL);
    } if (achiv->player_keys >= 3) {
        sfSprite_setPosition(achiv->tick, pos2);
        sfRenderWindow_drawSprite(utils->window, achiv->tick, NULL);
    } else if (achiv->player_keys < 3){
        sfSprite_setPosition(achiv->cross, pos2);
        sfRenderWindow_drawSprite(utils->window, achiv->cross, NULL);
    } 
}

void talked(utils_t *utils, achiv_t *achiv)
{
    sfVector2f kill_pos = {100, 100};
    sfVector2f key_pos = {100, 150};
    sfVector2f gold_pos = {100, 200};
    sfVector2f p_kill_pos = {150, 100};
    sfVector2f p_key_pos = {150, 150};
    sfVector2f p_gold_pos = {150, 200};

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
    if (achiv->not_talked == true)
        not_talked(utils, achiv);
    else
        talked(utils, achiv);
}
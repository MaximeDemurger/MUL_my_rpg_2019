/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** init achivement
*/

#include "my.h"

void init_bis(achiv_t *achiv)
{
    achiv->p_golds = sfText_create();
    achiv->p_keys = sfText_create();
    achiv->p_killing = sfText_create();
    achiv->t_golds = sfText_create();
    achiv->t_keys = sfText_create();
    achiv->t_killing = sfText_create();
    achiv->cross_text = sfTexture_createFromFile("assets/cross.png", NULL);
    achiv->tick_text = sfTexture_createFromFile("assets/tick.png", NULL);
    achiv->tick = sfSprite_create();
    achiv->cross = sfSprite_create();
}

int check_all(achiv_t *achiv)
{
    if (!achiv->p_golds || !achiv->p_keys || !achiv->p_killing ||
        !achiv->t_golds || !achiv->t_keys || !achiv->t_killing ||
        !achiv->cross_text || !achiv->cross || !achiv->tick_text ||
        !achiv->tick || !achiv->font || !achiv->not_talked || !achiv->keys ||
        !achiv->killing || !achiv->golds)
        return 1;
    return 0;
}

void set_achivement(achiv_t *achiv)
{
    sfSprite_setTexture(achiv->tick, achiv->tick_text, NULL);
    sfSprite_setTexture(achiv->cross, achiv->cross_text, NULL);
}

int init_achivement(achiv_t *achiv)
{
    achiv->png_talked = false;
    achiv->total_kills = 5;
    achiv->total_keys = 3;
    achiv->total_gold = 30;
    achiv->player_gold = 0;
    achiv->player_keys = 0;
    achiv->player_kills = 0;
    achiv->font = sfFont_createFromFile("assets/police.otf");
    achiv->not_talked = sfText_create();
    achiv->killing = sfText_create();
    achiv->keys = sfText_create();
    achiv->golds = sfText_create();
    init_bis(achiv);
    if (check_all(achiv))
        return 1;
    set_achivement(achiv);
    return 0;
}
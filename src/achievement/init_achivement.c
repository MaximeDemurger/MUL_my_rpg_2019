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
    achiv->cross_text = sfTexture_createFromFile("assets/cross.png", NULL);
    achiv->tick_text = sfTexture_createFromFile("assets/tick.png", NULL);
    achiv->tick = sfSprite_create();
    achiv->cross = sfSprite_create();
}

int check_all(achiv_t *achiv)
{
    if (!achiv->p_golds || !achiv->p_keys || !achiv->p_killing ||
        !achiv->cross_text || !achiv->cross || !achiv->tick_text ||
        !achiv->tick || !achiv->font || !achiv->not_talked || !achiv->keys ||
        !achiv->killing || !achiv->golds)
        return 1;
    return 0;
}

void set_achivement(achiv_t *achiv)
{
    sfSprite_setTexture(achiv->tick, achiv->tick_text, sfTrue);
    sfSprite_setTexture(achiv->cross, achiv->cross_text, sfTrue);
    sfText_setFont(achiv->not_talked, achiv->font);
    sfText_setFont(achiv->golds, achiv->font);
    sfText_setFont(achiv->killing, achiv->font);
    sfText_setFont(achiv->keys, achiv->font);
    sfText_setFont(achiv->p_golds, achiv->font);
    sfText_setFont(achiv->p_keys, achiv->font);
    sfText_setFont(achiv->p_killing, achiv->font);
}

void init_txt(achiv_t *achiv)
{
    sfText_setCharacterSize(achiv->not_talked, 30);
    sfText_setCharacterSize(achiv->killing, 30);
    sfText_setCharacterSize(achiv->keys, 30);
    sfText_setCharacterSize(achiv->golds, 30);
    sfText_setCharacterSize(achiv->p_killing, 30);
    sfText_setCharacterSize(achiv->p_keys, 30);
    sfText_setCharacterSize(achiv->p_golds, 30);
    sfText_setString(achiv->not_talked, "Talk to the PNJ to see achivements");
    sfText_setString(achiv->killing, "Kill 5 monsters:");
    sfText_setString(achiv->keys, "Find 3 keys:");
    sfText_setString(achiv->golds, "Get 30 gold:");
}

int init_achivement(achiv_t *achiv)
{
    achiv->png_talked = false;
    achiv->lvl_complet = false;
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
    init_txt(achiv);
    return 0;
}
/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** init ancient
*/

#include "my.h"

void set_pnj(pnj_t *pnj)
{
    sfVector2f pos = {330, 200};
    sfVector2f pos2 = {250, 100};

    sfSprite_setTexture(pnj->sprite, pnj->texture, sfTrue);
    sfSprite_setTexture(pnj->bulle, pnj->bulle_text, sfTrue);
    sfSprite_setTexture(pnj->sprite_dung, pnj->texture_dung, sfTrue);
    sfSprite_setTexture(pnj->not_enough, pnj->texture_not_enou, sfTrue);
    sfSprite_setTexture(pnj->enter, pnj->texture_enter, sfTrue);
    sfSprite_setPosition(pnj->bulle, pos2);
    sfText_setFont(pnj->text, pnj->font);
    sfText_setCharacterSize(pnj->text, 25);
    sfText_setPosition(pnj->text, pos);
    sfSprite_setRotation(pnj->sprite, 90);
    sfText_setColor(pnj->text, sfBlack);
    pnj->in_range = false;
    pnj->is_talking = false;
    pnj->index = 0;
    pnj->dialog = malloc(sizeof(char *) * 7);
}

int init_dungeon_ancient(pnj_t *pnj)
{
    pnj->texture_dung = sfTexture_createFromFile("assets/pnj_dungeon.png",
                                                                    NULL);
    pnj->sprite_dung = sfSprite_create();
    pnj->not_enough = sfSprite_create();
    pnj->texture_not_enou = sfTexture_createFromFile("assets/not_enough.png",
                                                                    NULL);
    pnj->enter = sfSprite_create();
    pnj->texture_enter = sfTexture_createFromFile("assets/enter_dungeon.png",
                                                                    NULL);
    return 0;
}

int init_ancient(pnj_t *pnj)
{
    sfVector2f pos = {300, 300};
    pnj->texture = sfTexture_createFromFile("assets/pnj.png", NULL);
    pnj->sprite = sfSprite_create();
    pnj->font = sfFont_createFromFile("assets/police.otf");
    pnj->text = sfText_create();
    pnj->bulle = sfSprite_create();
    pnj->bulle_text = sfTexture_createFromFile("assets/bulle_conv.png", NULL);
    if (!pnj->texture || !pnj->sprite || !pnj->font || !pnj->text
        || !pnj->bulle || !pnj->bulle_text)
        return 1;
    pnj->pos = pos;
    init_dungeon_ancient(pnj);
    set_pnj(pnj);
    pnj->dialog[0] = "Welcome adventurer to your first quest in this world!";
    pnj->dialog[1] = "To complet this quest you will have to:";
    pnj->dialog[2] = "Kill at least 5 monsters,";
    pnj->dialog[3] = "Find at least 3 keys";
    pnj->dialog[4] = "And collect at least 30 golds";
    pnj->dialog[5] = "Then find the dungeon but I can't say more about it!";
    pnj->dialog[6] = "Good Luck adventurer try not to get killed AHAHAHAH!!";
    pnj->dialog[7] = NULL;
    return 0;
}
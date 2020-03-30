/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** init ancient
*/

#include "my.h"

void set_pnj(pnj_t *pnj)
{
    sfVector2f pos = {300, 250};

    sfSprite_setTexture(pnj->sprite, pnj->texture, sfTrue);
    sfText_setFont(pnj->text, pnj->font);
    sfText_setCharacterSize(pnj->text, 25);
    sfText_setPosition(pnj->text, pos);
    sfSprite_setRotation(pnj->sprite, 90);
}

int init_ancient(pnj_t *pnj)
{
    sfVector2f pos = {300, 300};

    pnj->texture = sfTexture_createFromFile("assets/pnj.png", NULL);
    pnj->sprite = sfSprite_create();
    pnj->font = sfFont_createFromFile("assets/police.otf");
    pnj->text = sfText_create();
    if (!pnj->texture || !pnj->sprite || !pnj->font || !pnj->text)
        return 1;
    pnj->in_range = false;
    pnj->is_talking = false;
    pnj->pos = pos;
    set_pnj(pnj);
    pnj->index = 0;
    pnj->dialog = malloc(sizeof(char *) * 7);
    pnj->dialog[0] = "Welcome adventurer to your first quest in this world!";
    pnj->dialog[1] = "To complet this quest you will have to:";
    pnj->dialog[2] = "Kill at least 5 monsters,";
    pnj->dialog[3] = "Find at least 3 keys";
    pnj->dialog[4] = "And collect at least 30 golds";
    pnj->dialog[5] = "Then find the dungeon but I can't say more about it!";
    pnj->dialog[6] = "Good Luck adventurer try not to get killed AHAHAHAH!!";
    return 0;
}
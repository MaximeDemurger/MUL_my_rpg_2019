/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** init inventory
*/

#include "my.h"

void set_txt(inv_t *inv)
{
    sfVector2f pos = {150, 1000};
    sfVector2f pos2 = {290, 1000};

    sfText_setFont(inv->gold, inv->font);
    sfText_setCharacterSize(inv->gold, 30);
    sfText_setPosition(inv->gold, pos);
    sfText_setColor(inv->gold, sfBlack);
    sfText_setFont(inv->keys, inv->font);
    sfText_setCharacterSize(inv->keys, 30);
    sfText_setPosition(inv->keys, pos2);
    sfText_setColor(inv->keys, sfBlack);
}

void set_inv(inv_t *inv)
{
    sfVector2f pos = {0, 850};
    sfVector2f pos2 = {60, 930};
    sfVector2f pos3 = {200, 930};
    sfVector2f pos4 = {90, 950};
    sfVector2f pos5 = {230, 950};
    sfVector2f scale = {1.2, 2};

    sfSprite_setTexture(inv->back, inv->back_text, sfTrue);
    sfSprite_setPosition(inv->back, pos);
    sfSprite_setScale(inv->back, scale);
    sfSprite_setTexture(inv->case1, inv->case_text, sfTrue);
    sfSprite_setPosition(inv->case1, pos2);
    sfSprite_setTexture(inv->case2, inv->case_text, sfTrue);
    sfSprite_setPosition(inv->case2, pos3);
    sfSprite_setTexture(inv->obj1, inv->obj1_text, sfTrue);
    sfSprite_setPosition(inv->obj1, pos4);
    sfSprite_setTexture(inv->obj2, inv->obj2_text, sfTrue);
    sfSprite_setPosition(inv->obj2, pos5);
}

int init_inventory(inv_t *inv)
{
    inv->back = sfSprite_create();
    inv->back_text = sfTexture_createFromFile("assets/hudlayout.png", NULL);
    inv->case1 = sfSprite_create();
    inv->case2 = sfSprite_create();
    inv->case_text = sfTexture_createFromFile("assets/inventory.png", NULL);
    inv->font = sfFont_createFromFile("assets/police.otf");
    inv->gold = sfText_create();
    inv->keys = sfText_create();
    inv->obj1 = sfSprite_create();
    inv->obj1_text = sfTexture_createFromFile("assets/gold.png", NULL);
    inv->obj2 = sfSprite_create();
    inv->obj2_text = sfTexture_createFromFile("assets/key.png", NULL);
    if (!inv->back || !inv->back_text || !inv->case1 || !inv->case2 ||
        !inv->case_text || !inv->font || !inv->gold || !inv->keys ||
        !inv->obj1 || !inv->obj1_text || !inv->obj2 || !inv->obj2_text)
        return 1;
    set_inv(inv);
    set_txt(inv);
    return 0;
}
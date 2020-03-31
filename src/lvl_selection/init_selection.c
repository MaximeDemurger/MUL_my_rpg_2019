/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** init selection
*/

#include "my.h"

void set_texts_select(select_t *select)
{
    sfVector2f pos = {250, 200};
    sfVector2f pos2 = {50, 1000};
    sfVector2f pos3 = {1400, 1000};

    sfText_setFont(select->credits, select->font);
    sfText_setFont(select->version, select->font);
    sfText_setFont(select->welcomming, select->font);
    sfText_setString(select->credits, "Developped by DemiZ's");
    sfText_setString(select->version, "Version: 0.1.1 Early Acces");
    sfText_setString(select->welcomming, "Welcomme! Please choose your level");
    sfText_setPosition(select->welcomming, pos);
    sfText_setPosition(select->credits, pos2);
    sfText_setPosition(select->version, pos3);
    sfText_setCharacterSize(select->welcomming, 100);
    sfText_setCharacterSize(select->credits, 50);
    sfText_setCharacterSize(select->version, 50);
    sfText_setColor(select->version, sfBlack);
    sfText_setColor(select->welcomming, sfBlack);
    sfText_setColor(select->credits, sfBlack);
}

int init_selection(select_t *select)
{
    select->back_text = sfTexture_createFromFile(
                        "utils/imgs/background_startmenu.png", NULL);
    select->back = sfSprite_create();
    select->lvls_text = sfTexture_createFromFile(
                        "assets/lvl_select.png", NULL);
    select->lvls = sfSprite_create();
    select->font = sfFont_createFromFile("assets/police.otf");
    select->credits = sfText_create();
    select->version = sfText_create();
    select->welcomming = sfText_create();
    select->hoover = sfSprite_create();
    select->hoover_text = sfTexture_createFromFile("assets/hoover.png", NULL);
    if (!select->back_text || !select->back || !select->lvls_text ||
        !select->lvls || !select->font || !select->credits || !select->version
        || !select->welcomming || !select->hoover || !select->hoover_text)
        return 1;
    set_texts_select(select);
    sfSprite_setTexture(select->back, select->back_text, sfTrue);
    sfSprite_setTexture(select->lvls, select->lvls_text, sfTrue);
    sfSprite_setTexture(select->hoover, select->hoover_text, sfTrue);
    return 0;
}
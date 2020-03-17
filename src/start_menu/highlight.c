/*
** EPITECH PROJECT, 2020
** highlight
** File description:
** highlight
*/

#include "my.h"

int init_highlight(startmenu_t *startmenu)
{
    startmenu->quit_texture_highlight = sfTexture_createFromFile
                                    ("./utils/imgs/quit_highlight.png", NULL);
    startmenu->start_texture_highlight = sfTexture_createFromFile
                                    ("./utils/imgs/start_highlight.png", NULL);
    return 0;
}

int display_highlight_start(startmenu_t *startmenu, sfVector2i pos)
{
    if ((pos.x >= 805 && pos.x <= 980) && (pos.y >= 637 && pos.y <= 726)) {
        sfSprite_setTexture(startmenu->start_sprite,
                            startmenu->start_texture_highlight, sfTrue);
    } else {
        sfSprite_setTexture(startmenu->start_sprite,
                            startmenu->start_texture, sfTrue);
    }
    return 0;
}

int display_highlight_quit(startmenu_t *startmenu, sfVector2i pos)
{
    if ((pos.x >= 805 && pos.x <= 980) && (pos.y >= 767 && pos.y <= 854)) {
        sfSprite_setTexture(startmenu->quit_sprite,
                            startmenu->quit_texture_highlight, sfTrue);
    } else {
        sfSprite_setTexture(startmenu->quit_sprite,
                            startmenu->quit_texture, sfTrue);
    }
    return 0;
}
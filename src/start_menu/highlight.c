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
    if ((pos.x >= 830 && pos.x <= 1006) && (pos.y >= 683 && pos.y <= 774)) {
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
    if ((pos.x >= 830 && pos.x <= 1006) && (pos.y >= 823 && pos.y <= 916)) {
        sfSprite_setTexture(startmenu->quit_sprite,
                            startmenu->quit_texture_highlight, sfTrue);
    } else {
        sfSprite_setTexture(startmenu->quit_sprite,
                            startmenu->quit_texture, sfTrue);
    }
    return 0;
}
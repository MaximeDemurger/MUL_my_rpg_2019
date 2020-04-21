/*
** EPITECH PROJECT, 2020
** highlight
** File description:
** highlight
*/

#include "my.h"

int create_highlights(game_t *game)
{
    game->pausemenu->main_texture_highlight = sfTexture_createFromFile
                            ("./utils/imgs/menu_button_highlight.png", NULL);
    
}

int display_highlight(game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->utils->window);

    display_highlight_start_pause(game->pausemenu, pos, game->startmenu);
    display_highlight_main_pause(game->pausemenu, pos, game->startmenu);
    display_highlight_quit_pause(game->pausemenu, pos, game->startmenu);
}

int display_highlight_start_pause(pausemenu_t *pausemenu, sfVector2i pos, startmenu_t *startmenu)
{
    if ((pos.x >= 830 && pos.x <= 1006) && (pos.y >= 683 && pos.y <= 774)) {
        sfSprite_setTexture(pausemenu->start_sprite,
                            startmenu->start_texture_highlight, sfTrue);
    } else {
        sfSprite_setTexture(pausemenu->start_sprite,
                            startmenu->start_texture, sfTrue);
    }
    return 0;
}

int display_highlight_quit_pause(pausemenu_t *pausemenu, sfVector2i pos, startmenu_t *startmenu)
{
    if ((pos.x >= 830 && pos.x <= 1006) && (pos.y >= 542 && pos.y <= 634)) {
        sfSprite_setTexture(pausemenu->quit_sprite,
                            startmenu->quit_texture_highlight, sfTrue);
    } else {
        sfSprite_setTexture(pausemenu->quit_sprite,
                            startmenu->quit_texture, sfTrue);
    }
    return 0;
}

int display_highlight_main_pause(pausemenu_t *pausemenu, sfVector2i pos, startmenu_t *startmenu)
{
    if ((pos.x >= 830 && pos.x <= 1006) && (pos.y >= 823 && pos.y <= 916)) {
        sfSprite_setTexture(pausemenu->main_sprite,
                            pausemenu->main_texture_highlight, sfTrue);
    } else {
        sfSprite_setTexture(pausemenu->main_sprite,
                            pausemenu->main_texture, sfTrue);
    }
    return 0;
}
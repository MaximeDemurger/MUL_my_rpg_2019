/*
** EPITECH PROJECT, 2020
** init
** File description:
** init
*/

#include "my.h"

void event_settings(utils_t *utils)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(utils->window);

    if (utils->event.type == sfEvtMouseButtonPressed &&
            (pos.x >= 1816 && pos.x <= 1869) &&
            (pos.y >= 35 && pos.y <= 90)) {
        utils->in_game = false;
        utils->in_settings = true;
        sfRenderWindow_clear(utils->window, sfBlack);
    }
}

int highlight_settings_button(game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->utils->window);

    if (mouse_pos.x >= 1816 && mouse_pos.x <= 1869
            && mouse_pos.y >= 35 && mouse_pos.y <= 90) {
        sfSprite_setTexture(game->settings->settings_sprite,
                    game->settings->settings_texture_highlight, sfTrue);
    } else {
        sfSprite_setTexture(game->settings->settings_sprite,
                        game->settings->settings_texture, sfTrue);
    }
}

int display_settings(game_t *game)
{
    sfRenderWindow_drawSprite(game->utils->window,
                        game->startmenu->background_sprite, NULL);
}

int display_settings_button(game_t *game)
{
    highlight_settings_button(game);
    event_settings(game->utils);  
    sfRenderWindow_drawSprite(game->utils->window,
                            game->settings->settings_sprite, NULL);
}

int init_settings(game_t *game)
{
    sfVector2f pos = {1800, 25};
    sfVector2f scale = {0.3, 0.3};

    game->settings->settings_sprite = sfSprite_create();
    game->settings->settings_texture = sfTexture_createFromFile
                                    ("./utils/imgs/settings.png", NULL);
    game->settings->settings_texture_highlight = sfTexture_createFromFile
                                    ("./utils/imgs/settings_highlight.png", NULL);
    sfSprite_setTexture(game->settings->settings_sprite,
                        game->settings->settings_texture, sfTrue);
    sfSprite_setScale(game->settings->settings_sprite, scale);
    sfSprite_setPosition(game->settings->settings_sprite, pos);
}
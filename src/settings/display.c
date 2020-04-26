/*
** EPITECH PROJECT, 2020
** display
** File description:
** display
*/

#include "my.h"

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
    return 0;
}

int display_settings(game_t *game)
{
    sfRenderWindow_drawSprite(game->utils->window,
                        game->startmenu->background_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                        game->settings->bar_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                        game->settings->circle_sprite, NULL);
    event_sound_bar(game);
    return 0;
}

int display_settings_button(game_t *game)
{
    highlight_settings_button(game);
    event_settings(game->utils);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->settings->settings_sprite, NULL);
    return 0;
}
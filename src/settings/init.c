/*
** EPITECH PROJECT, 2020
** init
** File description:
** init
*/

#include "my.h"

void event_sound_bar(game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->utils->window);
    sfVector2f sprite_pos = sfSprite_getPosition(game->settings->circle_sprite);
    sfVector2f temp_pos = {sprite_pos.x, 520};
    int temp = 0;

    if (game->utils->event.type == sfEvtMouseButtonPressed &&
            (pos.x >= sprite_pos.x - 20 && pos.x <= sprite_pos.x + 50) &&
            (pos.y >= 526 && pos.y <= 590) && game->utils->event.type != sfEvtMouseButtonReleased) {
        temp_pos.x = pos.x;
        printf("bite\n");
        sfSprite_setPosition(game->settings->circle_sprite, temp_pos);
    }
}

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
    event_sound_bar(game);
    sfRenderWindow_drawSprite(game->utils->window,
                        game->startmenu->background_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                        game->settings->bar_sprite, NULL);
    sfRenderWindow_drawSprite(game->utils->window,
                        game->settings->circle_sprite, NULL);
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
    sfVector2f pos_2 = {750, 370};
    sfVector2f pos_3 = {810, 520};
    sfVector2f scale = {0.3, 0.3};
    sfVector2f scale_2 = {0.9, 0.9};
    sfVector2f scale_3 = {0.1, 0.1};

    game->settings->settings_sprite = sfSprite_create();
    game->settings->bar_sprite = sfSprite_create();
    game->settings->circle_sprite = sfSprite_create();
    game->settings->bar_texture = sfTexture_createFromFile
                            ("./utils/imgs/sound_bar.png", NULL);
    game->settings->circle_texture = sfTexture_createFromFile
                            ("./utils/imgs/circle.png", NULL);
    sfSprite_setTexture(game->settings->bar_sprite,
                        game->settings->bar_texture, sfTrue);
    sfSprite_setTexture(game->settings->circle_sprite,
                        game->settings->circle_texture, sfTrue);
    sfSprite_setPosition(game->settings->bar_sprite, pos_2);
    sfSprite_setPosition(game->settings->circle_sprite, pos_3);
    sfSprite_setScale(game->settings->bar_sprite, scale_2);
    sfSprite_setScale(game->settings->circle_sprite, scale_3);
    game->settings->settings_texture = sfTexture_createFromFile
                                    ("./utils/imgs/settings.png", NULL);
    game->settings->settings_texture_highlight = sfTexture_createFromFile
                                    ("./utils/imgs/settings_highlight.png", NULL);
    sfSprite_setTexture(game->settings->settings_sprite,
                        game->settings->settings_texture, sfTrue);
    sfSprite_setScale(game->settings->settings_sprite, scale);
    sfSprite_setPosition(game->settings->settings_sprite, pos);
}
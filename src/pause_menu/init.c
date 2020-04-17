/*
** EPITECH PROJECT, 2020
** init
** File description:
** init
*/

#include "my.h"

int create_sprites_pause(game_t *game)
{
    game->pausemenu->background_sprite = sfSprite_create();
    game->pausemenu->main_sprite = sfSprite_create();
    game->pausemenu->quit_sprite = sfSprite_create();
    game->pausemenu->start_sprite = sfSprite_create();
    return 0;
}

int set_textures_pause(game_t *game)
{
    game->pausemenu->main_texture = sfTexture_createFromFile
                                ("./utils/imgs/menu_button.png", NULL);
    sfSprite_setTexture(game->pausemenu->main_sprite,
                        game->pausemenu->main_texture, sfTrue);
    sfSprite_setTexture(game->pausemenu->background_sprite,
                        game->startmenu->background_texture, sfTrue);
    sfSprite_setTexture(game->pausemenu->start_sprite,
                        game->startmenu->start_texture, sfTrue);
    sfSprite_setTexture(game->pausemenu->quit_sprite,
                        game->startmenu->quit_texture, sfTrue);
    return 0;
}

int set_positions_pause(game_t *game)
{
    sfVector2f scale = {0.6, 0.6};
    sfVector2f scale_s = {0.7, 0.7};
    sfVector2f pos_1 = {830, 540};
    sfVector2f pos_2 = {830, 680};
    sfVector2f pos_3 = {830, 820};

    sfSprite_setScale(game->pausemenu->background_sprite, scale);
    sfSprite_setPosition(game->pausemenu->quit_sprite, pos_1);
    sfSprite_setPosition(game->pausemenu->start_sprite, pos_2);
    sfSprite_setPosition(game->pausemenu->main_sprite, pos_3);
    sfSprite_setScale(game->pausemenu->quit_sprite, scale_s);
    sfSprite_setScale(game->pausemenu->main_sprite, scale_s);
    sfSprite_setScale(game->pausemenu->start_sprite, scale_s);
    return 0;
}

int init_pausemenu(game_t *game)
{
    create_sprites_pause(game);
    create_highlights(game);
    set_textures_pause(game);
    set_positions_pause(game);
    return 0;
}
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

    sfSprite_setScale(game->pausemenu->background_sprite, scale);
    return 0;
}

int init_pausemenu(game_t *game)
{
    create_sprites_pause(game);
    set_textures_pause(game);
    set_positions_pause(game);
    return 0;
}
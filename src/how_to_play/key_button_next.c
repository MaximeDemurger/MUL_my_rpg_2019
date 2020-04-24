/*
** EPITECH PROJECT, 2020
** key
** File description:
** key
*/

#include "my.h"

int keybord_a_text(game_t *game)
{
    sfVector2f pos_text = {130, 530};

    game->how_to->text_a = sfText_create();
    game->how_to->font_a = sfFont_createFromFile("./utils/font/arial.ttf");
    if (!game->how_to->text_a || !game->how_to->font_a)
        return 84;
    sfText_setFont(game->how_to->text_a, game->how_to->font_a);
    sfText_setCharacterSize(game->how_to->text_a, 30);
    sfText_setString(game->how_to->text_a,
    "If you click on the A button,\
    you can access to the dungeun if you win the first level !");
    sfText_setPosition(game->how_to->text_a, pos_text);
    sfText_setColor(game->how_to->text_a, sfBlack);
    return 0;
}

int key_a_button(game_t *game)
{
    sfVector2f pos = {30, 520};
    sfVector2f scale = {0.3, 0.3};

    game->how_to->a_sprite = sfSprite_create();
    game->how_to->a_texture = sfTexture_createFromFile
                    ("./utils/imgs/a_key.png", NULL);
    sfSprite_setTexture(game->how_to->a_sprite,
                        game->how_to->a_texture, sfTrue);
    sfSprite_setScale(game->how_to->a_sprite, scale);
    sfSprite_setPosition(game->how_to->a_sprite, pos);
    keybord_m_text(game);
    return 0;
}

int keybord_m_text(game_t *game)
{
    sfVector2f pos_text = {130, 430};

    game->how_to->text_m = sfText_create();
    game->how_to->font_m = sfFont_createFromFile("./utils/font/arial.ttf");
    if (!game->how_to->text_m || !game->how_to->font_m)
        return 84;
    sfText_setFont(game->how_to->text_m, game->how_to->font_m);
    sfText_setCharacterSize(game->how_to->text_m, 30);
    sfText_setString(game->how_to->text_m,
    "If you click on the M button, display the minimap");
    sfText_setPosition(game->how_to->text_m, pos_text);
    sfText_setColor(game->how_to->text_m, sfBlack);
    return 0;
}

int key_m_button(game_t *game)
{
    sfVector2f pos = {30, 420};
    sfVector2f scale = {0.3, 0.3};

    game->how_to->m_sprite = sfSprite_create();
    game->how_to->m_texture = sfTexture_createFromFile
                    ("./utils/imgs/m_key.jpeg", NULL);
    sfSprite_setTexture(game->how_to->m_sprite,
                        game->how_to->m_texture, sfTrue);
    sfSprite_setScale(game->how_to->m_sprite, scale);
    sfSprite_setPosition(game->how_to->m_sprite, pos);
    keybord_m_text(game);
    return 0;
}
/*
** EPITECH PROJECT, 2020
** key_button
** File description:
** key_button
*/

#include "my.h"

int how_to_escape_button(game_t *game)
{
    sfVector2f pos = {30, 130};
    sfVector2f pos_text = {130, 140};
    sfVector2f scale = {0.3, 0.3};
    game->how_to->esc_sprite = sfSprite_create();
    game->how_to->esc_texture = sfTexture_createFromFile
                                    ("./utils/imgs/esc.jpeg", NULL);
    sfSprite_setTexture(game->how_to->esc_sprite,
                        game->how_to->esc_texture, sfTrue);
    sfSprite_setScale(game->how_to->esc_sprite, scale);
    sfSprite_setPosition(game->how_to->esc_sprite, pos);
    game->how_to->text_esc = sfText_create();
    game->how_to->font_esc = sfFont_createFromFile("./utils/font/arial.ttf");
    if (!game->how_to->text_esc || !game->how_to->font_esc)
        return 84;
    sfText_setFont(game->how_to->text_esc, game->how_to->font_esc);
    sfText_setCharacterSize(game->how_to->text_esc, 30);
    sfText_setString(game->how_to->text_esc,
        "If you click on the esc button you can acces to the settings menu !");
    sfText_setPosition(game->how_to->text_esc, pos_text);
    sfText_setColor(game->how_to->text_esc, sfBlack);
    return 0;
}

int keybord_p_text(game_t *game)
{
    sfVector2f pos_text = {130, 330};

    game->how_to->text_p = sfText_create();
    game->how_to->font_p = sfFont_createFromFile("./utils/font/arial.ttf");
    if (!game->how_to->text_p || !game->how_to->font_p)
        return 84;
    sfText_setFont(game->how_to->text_p, game->how_to->font_p);
    sfText_setCharacterSize(game->how_to->text_p, 30);
    sfText_setString(game->how_to->text_p,
    "If you click on the P button, the player attack the enemy");
    sfText_setPosition(game->how_to->text_p, pos_text);
    sfText_setColor(game->how_to->text_p, sfBlack);
    return 0;
}

int key_p_button(game_t *game)
{
    sfVector2f pos = {30, 320};
    sfVector2f scale = {0.3, 0.3};

    game->how_to->p_sprite = sfSprite_create();
    game->how_to->p_texture = sfTexture_createFromFile
                    ("./utils/imgs/p_key.jpeg", NULL);
    sfSprite_setTexture(game->how_to->p_sprite,
                        game->how_to->p_texture, sfTrue);
    sfSprite_setScale(game->how_to->p_sprite, scale);
    sfSprite_setPosition(game->how_to->p_sprite, pos);
    keybord_p_text(game);
    return 0;
}

int keybord_key_text(game_t *game)
{
    sfVector2f pos_text = {130, 240};

    game->how_to->text_key = sfText_create();
    game->how_to->font_key = sfFont_createFromFile("./utils/font/arial.ttf");
    if (!game->how_to->text_key || !game->how_to->font_key)
        return 84;
    sfText_setFont(game->how_to->text_key, game->how_to->font_key);
    sfText_setCharacterSize(game->how_to->text_key, 30);
    sfText_setString(game->how_to->text_key,
    "Right button to move right ! Left button to move left !\
    Up button to move up ! Down button to move down !");
    sfText_setPosition(game->how_to->text_key, pos_text);
    sfText_setColor(game->how_to->text_key, sfBlack);
    return 0;
}

int keybord_key_button(game_t *game)
{
    sfVector2f pos = {30, 220};
    sfVector2f scale = {0.3, 0.3};

    game->how_to->key_sprite = sfSprite_create();
    game->how_to->key_texture = sfTexture_createFromFile
                    ("./utils/imgs/keybord_key.jpeg", NULL);
    sfSprite_setTexture(game->how_to->key_sprite,
                        game->how_to->key_texture, sfTrue);
    sfSprite_setScale(game->how_to->key_sprite, scale);
    sfSprite_setPosition(game->how_to->key_sprite, pos);
    keybord_key_text(game);
    return 0;
}
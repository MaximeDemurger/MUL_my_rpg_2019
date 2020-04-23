/*
** EPITECH PROJECT, 2020
** print_how
** File description:
** print_how
*/

#include "my.h"

int init_text_how_to(game_t *game)
{
    sfVector2f pos = {40, 40};

    if (!game)
        return 84;
    game->how_to->text = sfText_create();
    game->how_to->font = sfFont_createFromFile("./utils/font/horrendo.ttf");
    if (!game->how_to->font || !game->how_to->text)
        return 84;
    sfText_setFont(game->how_to->text, game->how_to->font);
    sfText_setCharacterSize(game->how_to->text, 40);
    sfText_setString(game->how_to->text, "HOW TO PLAY");
    sfText_setPosition(game->how_to->text, pos);
    sfText_setColor(game->how_to->text, sfBlack);
    return 0;
}

int how_to_escape_button(game_t *game)
{
    sfVector2f pos = {30, 130};
    sfVector2f pos_text = {100, 140};
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

int keybord_key_button(game_t *game)
{
    sfVector2f pos = {30, 230};
    sfVector2f scale = {0.3, 0.3};

    game->how_to->key_sprite = sfSprite_create();
    game->how_to->key_texture = sfTexture_createFromFile
                    ("./utils/imgs/keybord_key.jpeg", NULL);
    sfSprite_setTexture(game->how_to->key_sprite,
                        game->how_to->key_texture, sfTrue);
    sfSprite_setScale(game->how_to->key_sprite, scale);
    sfSprite_setPosition(game->how_to->key_sprite, pos);
    return 0;
}

int display_background_how_to(game_t *game)
{
    sfRenderWindow_drawSprite(game->utils->window,
                            game->how_to->background_sprite, NULL);
    sfRenderWindow_drawText(game->utils->window, game->how_to->text, NULL);
    sfRenderWindow_drawSprite(game->utils->window, game->how_to->esc_sprite,
                                NULL);
    sfRenderWindow_drawText(game->utils->window, game->how_to->text_esc, NULL);
    sfRenderWindow_drawSprite(game->utils->window, game->how_to->key_sprite,
                            NULL);
    return 0;
}
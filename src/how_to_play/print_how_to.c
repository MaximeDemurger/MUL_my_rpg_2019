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
    sfRenderWindow_drawText(game->utils->window, game->how_to->text_key, NULL);
    sfRenderWindow_drawSprite(game->utils->window, game->how_to->p_sprite,
                            NULL);
    sfRenderWindow_drawText(game->utils->window, game->how_to->text_p, NULL);
    sfRenderWindow_drawSprite(game->utils->window, game->how_to->m_sprite,
                            NULL);
    sfRenderWindow_drawText(game->utils->window, game->how_to->text_m, NULL);
    sfRenderWindow_drawSprite(game->utils->window, game->how_to->a_sprite,
                            NULL);
    sfRenderWindow_drawText(game->utils->window, game->how_to->text_a, NULL);
    return 0;
}
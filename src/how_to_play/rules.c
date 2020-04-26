/*
** EPITECH PROJECT, 2020
** rules
** File description:
** rules
*/

#include "my.h"

int rules_one(game_t *game)
{
    sfVector2f pos_text = {30, 730};

    game->how_to->text_rules_first = sfText_create();
    game->how_to->font_rules_first =
        sfFont_createFromFile("./utils/font/arial.ttf");
    if (!game->how_to->text_rules_first || !game->how_to->font_rules_first)
        return 84;
    sfText_setFont(game->how_to->text_rules_first, game->how_to->font_rules_first);
    sfText_setCharacterSize(game->how_to->text_rules_first, 30);
    sfText_setString(game->how_to->text_rules_first, "First, go to speak to the pnj.\
    He will give you the rules to succes the level.\
    If you win the level you need th find the dungeon.");
    sfText_setPosition(game->how_to->text_rules_first, pos_text);
    sfText_setColor(game->how_to->text_rules_first, sfBlack);
    return 0;
}

int rules_two(game_t *game)
{
    sfVector2f pos_text = {30, 770};

    game->how_to->text_rules_second = sfText_create();
    game->how_to->font_rules_second =
        sfFont_createFromFile("./utils/font/arial.ttf");
    if (!game->how_to->text_rules_second || !game->how_to->font_rules_second)
        return 84;
    sfText_setFont(game->how_to->text_rules_second, game->how_to->font_rules_second);
    sfText_setCharacterSize(game->how_to->text_rules_second, 30);
    sfText_setString(game->how_to->text_rules_second,
    "In the dungeon you will fight against the big enemis!\
    Enjoy, and Good luck !");
    sfText_setPosition(game->how_to->text_rules_second, pos_text);
    sfText_setColor(game->how_to->text_rules_second, sfBlack);
    return 0;
}
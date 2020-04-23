/*
** EPITECH PROJECT, 2020
** init
** File description:
** init
*/

#include "my.h"

void event_how_to(utils_t *utils)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(utils->window);

    if (utils->event.type == sfEvtMouseButtonPressed &&
            (pos.x >= 1716 && pos.x <= 1769) &&
            (pos.y >= 45 && pos.y <= 100)) {
        utils->in_game = false;
        utils->in_how_to = true;
        sfRenderWindow_clear(utils->window, sfBlack);
    }
}

int display_how_to(game_t *game)
{
    event_how_to(game->utils);
    sfRenderWindow_drawSprite(game->utils->window,
                            game->how_to->how_to_sprite, NULL);
    return 0;
}

int init_how_to(howto_t *how_to)
{
    sfVector2f pos = {1700, 35};
    sfVector2f scale = {0.2, 0.2};

    how_to->how_to_sprite = sfSprite_create();
    how_to->how_to_texture = sfTexture_createFromFile
                                    ("./utils/imgs/book.png", NULL);
    sfSprite_setTexture(how_to->how_to_sprite,
                        how_to->how_to_texture, sfTrue);
    sfSprite_setScale(how_to->how_to_sprite, scale);
    sfSprite_setPosition(how_to->how_to_sprite, pos);
    return 0;
}
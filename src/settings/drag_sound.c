/*
** EPITECH PROJECT, 2020
** drag
** File description:
** drag_sound
*/

#include "my.h"

void drag(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->utils->window);
    sfVector2f pos = {mouse.x, 520};

    sfSprite_setPosition(game->settings->circle_sprite, pos);
}

void event_sound_bar(game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->utils->window);
    sfVector2f sprite_pos = sfSprite_getPosition(game->settings->circle_sprite);
    sfVector2f temp_pos = {sprite_pos.x, 520};

    if (game->utils->event.type == sfEvtMouseButtonPressed &&
            (pos.x >= sprite_pos.x - 50 && pos.x <= sprite_pos.x + 50) &&
            (pos.y >= 526 && pos.y <= 590) && game->settings->is_dragging == false) {
        game->settings->is_dragging = true;
        printf("click\n");
    }
    if (game->settings->is_dragging) {
        drag(game);
    }
    if (game->utils->event.type == sfEvtMouseButtonReleased &&
            (pos.x >= sprite_pos.x - 50 && pos.x <= sprite_pos.x + 50) &&
            (pos.y >= 526 && pos.y <= 590) && game->settings->is_dragging == true) {
        game->settings->is_dragging = false;
        printf("unclick\n");
    }
}
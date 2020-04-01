/*
** EPITECH PROJECT, 2020
** play struct
** File description:
** paly struct
*/

#ifndef PLAY_STRUCT_H
#define PLAY_STRUCT_H

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <SFML/System/Types.h>

typedef struct score_s {
    sfVector2f pos;
    float score;
    sfIntRect rect;
    sfText *live_text;
    sfText *live_int;
    sfFont *font;
    sfText *score_text;
}score_t;

typedef struct play_s {
    int live;
    sfTexture *player_text;
    sfSprite *player;
    sfVector2f origin;
    int x_play;
    int y_play;
    sfClock *clock;
    sfVector2f offset;
    sfIntRect rect;
    int col_map;
    int line_map;
} play_t;

#endif /* !PLAY_STRUCT_H */

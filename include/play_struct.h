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

typedef struct heart_s {
    sfSprite *one;
    sfSprite *two;
    sfSprite *three;
    sfSprite *four;
    sfSprite *five;
    sfSprite *empty_one;
    sfSprite *empty_two;
    sfSprite *empty_three;
    sfSprite *empty_four;
    sfSprite *empty_five;
    sfTexture *empty_texture_one;
    sfTexture *empty_texture_two;
    sfTexture *empty_texture_three;
    sfTexture *empty_texture_four;
    sfTexture *empty_texture_five;
    sfTexture *player_text;
    sfTexture *texture_one;
    sfTexture *texture_two;
    sfTexture *texture_three;
    sfTexture *texture_four;
    sfTexture *texture_five;
}heart_t;

typedef struct attack_s {
    sfSprite *sprite_attack;
    sfTexture *texture_attack;
}attack_t;

typedef struct play_s {
    float life;
    sfSprite *player;
    sfVector2f origin;
    int attack_number;
    int x_play;
    int y_play;
    sfClock *clock;
    sfVector2f offset;
    sfIntRect rect;
    int col_map;
    int line_map;
    struct heart_s *heart;
    struct attack_s *attack;
}play_t;

#endif /* !PLAY_STRUCT_H */

/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** achievement.h
*/

#ifndef ACHIVEMENT
#define ACHIVEMENT

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <SFML/System/Types.h>
#include <stdbool.h>

typedef struct achivs_s {
    int player_kills;
    int player_keys;
    int player_gold;
    bool png_talked;
    bool lvl_complet;
    sfFont *font;
    sfText *not_talked;
    sfText *killing;
    sfText *keys;
    sfText *golds;
    sfText *p_killing;
    sfText *p_keys;
    sfText *p_golds;
    sfTexture *cross_text;
    sfSprite *cross;
    sfTexture *tick_text;
    sfSprite *tick;
}achiv_t;

#endif /* !ACHIEVEMENT */

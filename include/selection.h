/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** lvl selection.h
*/

#ifndef SELECT
#define SELECT

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <SFML/System/Types.h>

typedef struct select_s {
    sfSprite *back;
    sfTexture *back_text;
    sfSprite *lvls;
    sfTexture *lvls_text;
    sfTexture *hoover_text;
    sfSprite *hoover;
    sfText *welcomming;
    sfText *version;
    sfText *credits;
    sfFont *font;
}select_t;

#endif /* !SELECT */

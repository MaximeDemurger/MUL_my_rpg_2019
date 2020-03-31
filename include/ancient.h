/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** ancient.h
*/

#ifndef ANCIENT
#define ANCIENT

#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "SFML/System/Export.h"
#include "SFML/System/Time.h"
#include "SFML/System/Types.h"
#include <stdbool.h>

typedef struct pnj_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *bulle;
    sfTexture *bulle_text;
    sfVector2f pos;
    bool in_range;
    bool is_talking;
    char **dialog;
    int index;
    sfFont *font;
    sfText *text;
}pnj_t;

#endif /* !ANCIENT */

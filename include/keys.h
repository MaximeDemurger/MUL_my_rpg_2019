/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** keys.h
*/

#ifndef KEYS
#define KEYS

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <SFML/System/Types.h>
#include <stdbool.h>

typedef struct keys_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    struct keys_s *next;
}keys_t;

#endif /* !KEYS */

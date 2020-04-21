/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** heart.h
*/

#ifndef FOOD
#define FOOD

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <SFML/System/Types.h>

typedef struct food_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    struct food_s *next;
}food_t;

#endif /* !FOOD */

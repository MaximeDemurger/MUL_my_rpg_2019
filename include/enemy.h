/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** enemy.h
*/

#ifndef ENEMY
#define ENEMY

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <SFML/System/Types.h>
#include <stdbool.h>

typedef struct enemys_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f dir;
    int life;
    sfClock *clock;
    struct enemys_s *next;
}enemy_t;

#endif /* !ENEMY */

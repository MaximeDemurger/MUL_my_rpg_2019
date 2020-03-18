/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** inventory.h
*/

#ifndef INVENTORY
#define INVENTORY

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <SFML/System/Types.h>

typedef struct inventory_s {
    sfTexture *back_text;
    sfSprite *back;
    sfTexture *case_text;
    sfSprite *case1;
    sfSprite *case2;
    sfTexture *obj1_text;
    sfSprite *obj1;
    sfTexture *obj2_text;
    sfSprite *obj2;
    sfFont *font;
    sfText *keys;
    sfText *gold;
}inv_t;

#endif /* !INVENTORY */

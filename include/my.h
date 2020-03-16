/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** my.h
*/

#ifndef PROTO
#define PROTO

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include "main_struct.h"
#include "achivement.h"

/* MAIN GAME */
void capture_events(utils_t *);
int open_window(utils_t *, game_t *);

#endif /* !PROTO */

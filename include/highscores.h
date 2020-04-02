/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** highscores.h
*/

#ifndef HIGHSCORE
#define HIGHSCORE

typedef struct high_s {
    char *score;
    int rank;
    struct high_s *next;
}high_t;

#endif /* !HIGHSCORE */

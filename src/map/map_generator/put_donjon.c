/*
** EPITECH PROJECT, 2020
** donjon
** File description:
** donjon
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "my.h"

int give_values(int *random_col, int *random_line, int *secondcol, int *col)
{
    if (*random_col == 0 && *random_line == 0)
        *random_col += 1;
    *col = *random_col * 16 + 5;
    *secondcol = *col;
    return 0;
}

//too long function
char **put_donjon(char **tab)
{
    int random_line = (rand() % 3);
    int random_col = (rand() % 3);
    int line = random_line * 8 + 2;;
    int secondline = line;
    int col = 0;
    int secondcol;

    give_values(&random_col, &random_line, &secondcol, &col);
    while (line < 4 + secondline) {
        col = random_col * 16 + 5;
        while (col < 4 + secondcol) {
            if (line == random_line * 8 + 2 && col == random_col * 16 + 5) {
                tab[line][col - 1] = 'S';
                tab[line - 1][col - 1] = 'E';
            } tab[line][col++] = 'D';
        } line++;
    }
    return tab;
}
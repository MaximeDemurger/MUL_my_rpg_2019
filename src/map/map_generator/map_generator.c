/*
** EPITECH PROJECT, 2020
** map generator
** File description:
** generator
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "my.h"

char write_in_file(int i, int *j, int random)
{
    if (i == 1151)
        return '\0';
    if (i == *j) {
        *j += 48;
        return '\n';
    } else if (random == 0)
        return '1';
    else if (random == 1)
        return 'O';
    else if (random == 2)
        return 'X';
    return 0;
}


char **put_donjon(char **tab)
{
    int random_line = (rand() % 3);
    int random_col = (rand() % 3);
    int line = random_line * 8 + 2;;
    int secondline = line;
    int col = 0;
    int secondcol;

    if (random_col == 0 && random_line == 0)
        random_col++;
    col = random_col * 16 + 5;
    secondcol = col;
    while (line < 4 + secondline) {
        col = random_col * 16 + 5;
        while (col < 4 + secondcol) {
            if (line == random_line * 8 + 2 && col == random_col * 16 + 5)
                tab[line][col - 1] = 'D'; 
            tab[line][col++] = 'D';
        }
        line++;
    }
    return tab;
}

char **map_generator(void)
{
    int random = 0;
    int i = 0;
    int j = 47;
    char **tab = NULL;
    char *map = malloc(sizeof(char) * 1152);

    if (map == NULL)
        return NULL;
    while (i < 1152) {
        random = rand() % 3;
        map[i] = write_in_file(i, &j, random);
        i++;
    }
    tab = my_str_to_word_array(map, '\n');
    tab = put_donjon(tab);
    return tab;
}
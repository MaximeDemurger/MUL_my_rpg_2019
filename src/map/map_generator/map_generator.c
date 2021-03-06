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

char write_in_file_next(int i, int *j, int random)
{
    if (random == 0)
        return '1';
    if (random == 1)
        return 'O';
    else if (random == 2)
        return 'X';
    return 0;
}

char write_in_file(int i, int *j, int random)
{
    if (i == 1151)
        return '\0';
    if (i == *j) {
        *j += 48;
        return '\n';
    } else
        return write_in_file_next(i, j, random);
    return 0;
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
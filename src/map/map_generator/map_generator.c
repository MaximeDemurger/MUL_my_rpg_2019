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

void write_in_file(FILE *fd, int i, int *j, int random)
{
    if (i == *j) {
        fwrite("\n", 1, 1, fd);
        *j += 47;
    } else if (random == 0)
        fwrite("1", 1, 1, fd);
    else if (random == 1)
        fwrite("X", 1, 1, fd);
    else if (random == 2)
        fwrite("O", 1, 1, fd);
}


int map_generator(char **av)
{
    int random = 0;
    int i = 0;
    FILE *fd;
    int j = 46;
    char *map = malloc(sizeof(char) * 1128);

    if (map == NULL || av[1] == NULL)
        return 84;
    fd = fopen(av[1], "w");
    while (i < 1128) {
        random = rand() % 3;
        write_in_file(fd, i, &j, random);
        i++;
    }
    return 0;
}
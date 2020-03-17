/*
** EPITECH PROJECT, 2020
** start game
** File description:
** start game play function
*/

#include <stdlib.h>
#include <fcntl.h>
#include "my.h"

char **gettingMap_fromFile(char *filepath)
{
    char **line = malloc(sizeof(char *) * 25);
    char *str = NULL;
    int i = 0;
    int fd = 0;

    if (!filepath || !line)
        return NULL;
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return NULL;
    while ((str = get_next_line(fd))) {
        line[i] = my_strdup(str);
        if (!line[i])
            return NULL;
        i++;
        free(str);
    }
    line[i] = NULL;
    return line;
}
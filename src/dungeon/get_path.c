/*
** EPITECH PROJECT, 2020
** get path
** File description:
** get path
*/

#include "my.h"

int print_dungeon(utils_t *utils, dungeon_t *dungeon)
{
    sfVector2f dungeon_pos = {0, 0};

    while (dungeon_pos.y < 1080) {
        dungeon_pos.x = 0;
        while (dungeon_pos.x < 1920) {
            sfSprite_setPosition(dungeon->ground, dungeon_pos);
            sfRenderWindow_drawSprite(utils->window, dungeon->ground, NULL);
            dungeon_pos.x += 128;
        }
        dungeon_pos.y += 135;
    }
    return 0;
}

int get_path(char **tab, map_t *map)
{
    int line = 0;
    int col = 0;

    while (tab[line]) {
        if (line > 8 + map->map_pos_line)
            map->map_pos_line += 8;
        col = 0;
        map->map_pos_col = 0;
        while (tab[line][col]) {
            if (col > 16 + map->map_pos_col)
                map->map_pos_col += 16;
            if (tab[line][col] == 'S')
                return 0;
            col++;
        }
        line++;
    }
    return 0;
}
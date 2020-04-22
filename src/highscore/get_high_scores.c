/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** get high scroes
*/

#include "my.h"

void my_rev_list(high_t **begin)
{
    high_t *tmp = 0;
    high_t *elem = *begin;
    high_t *next;

    while (elem->next) {
        next = elem->next;
        elem->next = tmp;
        tmp = elem;
        elem = next;
    }
    elem->next = tmp;
    *begin = elem;
}

high_t *add_score(high_t *high, char const *line, int count)
{
    high_t *tmp = malloc(sizeof(high_t));

    if (!tmp)
        return NULL;
    tmp->score = my_strdup(line);
    tmp->rank = count;
    tmp->next = high;
    return tmp;
}

int get_high_scores(high_t *high)
{
    char *line = NULL;
    size_t n = 0;
    int count = 1;
    FILE *stream = fopen("Highscores.txt", "r");

    if (!stream)
        return 1;
    while (getline(&line, &n, stream) != -1) {
        high = add_score(high, line, count);
        count++;
    }
    my_rev_list(&high);
    fclose(stream);
    return 0;
}
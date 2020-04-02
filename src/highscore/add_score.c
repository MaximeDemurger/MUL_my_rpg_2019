/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** add score
*/

#include "my.h"

int my_int_cmp(char const *s1, char const *s2)
{
    int num1 = 0;
    int num2 = 0;

    if (!s1 || !s2)
        return 0;
    num1 = my_atoi(s1);
    num2 = my_atoi(s2);
    if (num1 > num2)
        return 1;
    if (num1 == num2)
        return 1;
    if (num1 < num2)
        return -1;
    return 0;
}

int add_new_score(high_t *high, char const *new_score)
{
    high_t *tmp = high;
    bool write_new = false;
    FILE *stream = fopen("Highscores.txt", "w+");

    if (!tmp || !stream) return 1;
    while (tmp) {
        if (write_new == false) {
            if (my_int_cmp(tmp->score, new_score) > 0) {
                fwrite(tmp->score, my_strlen(tmp->score), 1, stream);
                tmp = tmp->next;
            }
            else {
                fwrite(new_score, my_strlen(new_score), 1, stream);
                write_new = true;
            }
        } else {
            fwrite(tmp->score, my_strlen(tmp->score), 1, stream);
            tmp = tmp->next;
        }
    }
    return 0;
}
/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** my int cmp
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
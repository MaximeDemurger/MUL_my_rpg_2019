/*
** EPITECH PROJECT, 2019
** my atoi
** File description:
** my_atoi
*/

#include "my.h"

int check_char(char const *str)
{
    int i = 0;

    while (str[i]) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '\n')
            return 1;
        i++;
    }
    return 0;
}

int my_atoi(char const *stack)
{
    int printer = 0;
    int n = 0;

    if (check_char(stack))
        return -1;
    while (stack[n] != '\0') {
        if (stack[n] >= '0' && stack[n] <= '9')
            printer = printer + (stack[n] - 48);
        if (stack[n + 1] == '\n')
            return (printer);
        if (stack[n + 1] != '\0')
            printer = printer * 10;
        n++;
    }
    return (printer);
}
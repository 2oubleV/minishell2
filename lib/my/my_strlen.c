/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** task03
*/

#include "stdlib.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    if (str[0] == '\0' || str[0] == '\n')
        return 0;
    for (; str[i] != '\0'; i++);
    return i;
}
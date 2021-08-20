/*
** EPITECH PROJECT, 2020
** my_strlowcase
** File description:
** lowcase
*/

#include <stdio.h>

int my_strlen(char const *str);

char *my_strlowcase(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; ++i) {
        if (str[i] > 64 && str[i] < 91)
            str[i] = str[i] + 32;
    }
    return (str);
}
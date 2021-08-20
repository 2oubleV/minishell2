/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
** my_strupcase
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src);

char *my_strupcase(char *str)
{
    int i;
    str = my_strdup(str);

    for (i = 0; str[i] != '\0'; ++i) {
        if (str[i] > 96 && str[i] < 123)
            str[i] = str[i] - 32;
    }
    return (str);
}
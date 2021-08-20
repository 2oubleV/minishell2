/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (str == NULL)
        exit(84);
    if (my_strlen(src) == 0)
        return NULL;
    for (int i = 0; src[i] != '\0'; ++i) {
        str[i] = src[i];
    }
    str[my_strlen(src)] = '\0';
    return (str);
}
/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** function that copies a string into another
*/

#include "my.h"
#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int length = 0;

    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    if (dest == NULL)
        return NULL;
    while (src[length] != '\0')
        ++length;
    while (src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[length] = '\0';
    return (dest);
}

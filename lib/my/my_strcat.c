/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** concatenate 2 strings
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_strlen.c"

char *my_strcat(char const *dest, char const *src)
{
    int src_length = my_strlen(src);
    int dest_length = my_strlen(dest);
    int full_length = src_length + dest_length;
    int j = 0;
    char *tmp = malloc(sizeof(char) * full_length + 1);

    if (tmp == NULL)
        exit(84);
    for (int i = 0; i < src_length; ++i)
        tmp[i] = src[i];
    for (int i = src_length; i < full_length; i++) {
        tmp[i] = dest[j];
        j++;
    }
    tmp[full_length] = '\0';
    return (tmp);
}
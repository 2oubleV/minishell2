/*
** EPITECH PROJECT, 2020
** B-PSU-101-LIL-1-1-minishell1-william.mallevays
** File description:
** Created by william,
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char *clean_str(char *str)
{
    char *tmp = malloc(sizeof(char) * my_strlen(str));
    int i = 0;

    if (tmp == NULL)
        return NULL;
    for (; str[i] != '\n' ; ++i) {
        tmp[i] = str[i];
    }
        tmp[my_strlen(str) - 1] = '\0';
    free(str);
    return tmp;
}
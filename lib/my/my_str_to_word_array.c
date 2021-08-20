/*
** EPITECH PROJECT, 2020
** B-PSU-101-LIL-1-1-minishell1-william.mallevays
** File description:
** Created by william,
*/

#include "my.h"
#include <string.h>
#include <stdlib.h>

int count_arg(char *src)
{
    int i = 0;
    char *str = my_strdup(src);
    char *token = NULL;

    token = strtok(str, " \t");
    for (; token != NULL; i++)
        token = strtok(NULL, " \t");
    free(str);
    free(token);
    return i;
}

char **my_str_to_tab(char *src)
{
    int count = count_arg(src);
    char **tab_path = NULL;
    char *str = my_strdup(src);
    char *token = NULL;

    if (count == 0)
        return NULL;
    tab_path = malloc(sizeof(char *) * (count + 1));
    if (tab_path == NULL)
        return NULL;
    tab_path[count] = NULL;
    token = strtok(str, " \t");
    for (int i = 0; token != NULL; i++) {
        tab_path[i] = my_strdup(token);
        token = strtok(NULL, " \t");
    }
    free(str);
    free(token);
    return tab_path;
}
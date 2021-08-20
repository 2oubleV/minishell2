/*
** EPITECH PROJECT, 2025
** B-PSU-210-LIL-2-1-bsminishell2-william.mallevays
** File description:
** Created by William,
*/

#include "my.h"
#include <stdlib.h>

int tab_len(char **arg)
{
    int i = 0;

    if (arg == NULL)
        return 0;
    while (arg[i] != NULL)
        i++;
    return i;
}

char **my_tab_dup(char **old_env)
{
    char **new_tab = malloc(sizeof(char *) * (tab_len(old_env) + 1));

    if (new_tab == NULL)
        exit(84);
    for (int i = 0; old_env[i] != NULL; ++i)
        new_tab[i] = my_strdup(old_env[i]);
    new_tab[tab_len(old_env)] = NULL;
    return new_tab;
}

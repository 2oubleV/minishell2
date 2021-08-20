/*
** EPITECH PROJECT, 2025
** B-PSU-210-LIL-2-1-bsminishell2-william.mallevays
** File description:
** Created by William,
*/

#include "../include/minishell2.h"

int check_var_env(char **env, char *name)
{
    if (env != NULL && name != NULL) {
        for (int i = 0; env[i] != NULL; ++i) {
            if (check_var(name, env[i]) == 0) {
                return i;
            }
        }
    }
    return -1;
}

char *str_to_var(char **tab)
{
    char *var = NULL;

    if (tab_len(tab) != 2 && tab_len(tab) != 3)
        return NULL;
    var = my_strcat("=", tab[1]);
    if (tab_len(tab) == 3)
        var = my_strcat(tab[2], var);
    return var;
}

char **add_env(char **env, char **tab)
{
    char **new_env = malloc(sizeof(char *) * (tab_len(env) + 2));

    if (new_env == NULL)
        exit(84);
    for (int i = 0; env[i] != NULL; ++i)
        new_env[i] = my_strdup(env[i]);
    new_env[tab_len(env)] = str_to_var(tab);
    if (new_env[tab_len(env)] == NULL) {
        my_putstr("invalid arguments\n");
        return env;
    }
    new_env[tab_len(env) + 1] = NULL;
    return new_env;
}

char **my_setenv(char **env, char **tab)
{
    char **new_env = NULL;
    int line = check_var_env(env, tab[1]);

    if (line < 0) {
        new_env = add_env(env, tab);
    } else {
        new_env = malloc(sizeof(char *) * (tab_len(env) + 1));
        if (new_env == NULL)
            exit(84);
        for (int i = 0; env[i] != NULL; ++i) {
            if (i == line) {
                new_env[i] = str_to_var(tab);
                i++;
            }
            new_env[i] = my_strdup(env[i]);
        }
        new_env[tab_len(env)] = NULL;
    }
    return new_env;
}


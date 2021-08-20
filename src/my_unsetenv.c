/*
** EPITECH PROJECT, 2025
** B-PSU-210-LIL-2-1-bsminishell2-william.mallevays
** File description:
** Created by William,
*/

#include "../include/minishell2.h"

void rm_env(char **new_env, char **env, int line)
{
    int j = 0;

    for (int i = 0; env[i] != NULL; ++i) {
        if (line != tab_len(env) - 1 && i == line)
            i++;
        new_env[j] = my_strdup(env[i]);
        j++;
    }
}

char **my_unsetenv(char **env, char **tab)
{
    int line = check_var_env(env, tab[1]);
    char **new_env = NULL;

    if (my_strcmp(tab[1], "*") == 0) {
        new_env = NULL;
    } else if (line < 0) {
        return env;
    } else {
        new_env = malloc(sizeof(char *) * tab_len(env));
        if (new_env == NULL)
            exit(84);
        rm_env(new_env, env, line);
    }
    new_env[tab_len(env) - 1] = NULL;
    return new_env;
}
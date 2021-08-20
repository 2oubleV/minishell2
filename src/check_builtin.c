/*
** EPITECH PROJECT, 2025
** B-PSU-210-LIL-2-1-bsminishell2-william.mallevays
** File description:
** Created by William,
*/

#include "../include/minishell2.h"

char **check_builtin(char **tab, char **env)
{
    if (my_strcmp(tab[0], "cd") == 0) {
        env = my_cd(env, tab);
        return env;
    }
    if (my_strcmp(tab[0], "env") == 0) {
        my_env(env);
        return env;
    }
    if (my_strcmp(tab[0], "unsetenv") == 0) {
        env = my_unsetenv(env, tab);
        return env;
    }
    if (my_strcmp(tab[0], "setenv") == 0) {
        env = my_setenv(env, tab);
        return env;
    }
    my_exec(tab, env);
    return env;
}

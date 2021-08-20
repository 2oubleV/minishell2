/*
** EPITECH PROJECT, 2025
** B-PSU-210-LIL-2-1-minishell2-william.mallevays
** File description:
** Created by William,
*/

#include "../include/minishell2.h"

char **handle_wave(char **env, char **tab, char *new_pwd)
{
    char **new_env = NULL;

    if (my_strlen(tab[1]) == 1) {
        new_pwd = my_strcat(my_getenv("HOME", env), "PWD=");
        if (chdir(my_getenv("HOME", env)) == -1) {
            my_putstr(tab[1]);
        } else
            new_env = my_tab_dup(my_setenv(env, setenv_cd("PWD", new_pwd)));
    } else {
        new_pwd = my_strcat(my_getenv("HOME", env), "PWD=");
        new_pwd = my_strcat(get_path(tab[1]), new_pwd);
        if (chdir(cpy_var(new_pwd, my_strlen(new_pwd) - 4)) == -1) {
            my_putstr(cpy_var(new_pwd, my_strlen(new_pwd) - 4));
        } else
            new_env = my_setenv(env, setenv_cd("PWD", new_pwd));
    }
    return new_env;
}

char **handle_two_args(char **env, char **tab, char *new_pwd)
{
    char **new_env = NULL;

    if (my_strcmp(tab[1], "-") == 0) {
        chdir(my_getenv("OLDPWD", env));
        new_env = my_setenv(env, setenv_cd("PWD", my_getenv("OLDPWD", env)));
        return new_env;
    } else if (tab[1][0] == '~') {
        new_env = handle_wave(env, tab, new_pwd);
        return new_env;
    } else {
        if (chdir(tab[1]) == -1) {
            my_putstr(tab[1]);
            my_putstr(": No such file or directory.\n");
        } else {
            new_pwd = my_strcat("/", my_getenv("PWD", env));
            new_pwd = my_strcat(tab[1], new_pwd);
            new_env = my_setenv(env, setenv_cd("PWD", new_pwd));
        }
    }
    return new_env;
}

char **handle_args(char **env, char **tab, char *new_pwd, char **new_env)
{
    char *pwd = my_getenv("PWD", env);

    if (is_dir(tab[1]) == 0) {
        new_env = handle_two_args(env, tab, new_pwd);
        new_env = my_setenv(new_env, setenv_cd("OLDPWD", pwd));
    } else
        new_env = my_tab_dup(env);
    return new_env;
}

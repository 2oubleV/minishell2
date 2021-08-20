/*
** EPITECH PROJECT, 2025
** B-PSU-210-LIL-2-1-bsminishell2-william.mallevays
** File description:
** Created by William,
*/

#include "../include/minishell2.h"

char **my_path_to_array(char *path)
{
    int count = 1;
    char **tab_path = NULL;
    char *token = NULL;

    if (path == NULL)
        return NULL;
    for (int i = 0; path[i] != '\0'; ++i)
        if (path[i] == '.' || path[i] == ':')
            count++;
    tab_path = malloc(sizeof(char *) * (count + 1));
    if (tab_path == NULL)
        return NULL;
    token = strtok_r(path, ":.", &path);
    for (int i = 0; token != NULL; i++) {
        tab_path[i] = my_strdup(token);
        token = strtok_r(NULL, ":.", &path);
    }
    tab_path[count] = NULL;
    free(token);
    return tab_path;
}

char *cpy_var(char *path, int len)
{
    char *str = malloc(sizeof(char) * my_strlen(path) - len + 1);
    int i = 0;
    int j = 0;

    if (str == NULL)
        return NULL;
    while (path[i] != '=')
        i++;
    i++;
    while (path[i] != '\0') {
        str[j] = path[i];
        i++;
        j++;
    }
    str[j] = '\0';
    return str;
}

int check_var(char *name, char *n_env)
{
    if (n_env[my_strlen(name)] != '=')
        return 1;
    for (int i = 0; name[i] != '\0'; ++i) {
        if (name[i] != n_env[i])
            return 1;
    }
    return 0;
}

char *my_getenv(char *name, char **env)
{
    char *str = NULL;

    if (env == NULL)
        return NULL;
    for (int i = 0; env[i] != NULL; ++i) {
        if (check_var(name, env[i]) == 0) {
            str = cpy_var(env[i], my_strlen(name));
            return str;
        }
    }
    return NULL;
}

void my_env(char **env)
{
    if (env == NULL)
        return;
    while (*env) {
        my_putstr(*env);
        my_putchar('\n');
        env++;
    }
}

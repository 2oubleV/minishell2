/*
** EPITECH PROJECT, 2020
** B-PSU-101-LIL-1-1-minishell1-william.mallevays
** File description:
** Created by william,
*/

#include "../include/minishell2.h"

int is_dir(char *fp)
{
    DIR *directory = opendir(fp);

    if (directory != NULL) {
        closedir(directory);
        return 0;
    }
    if (my_strcmp(fp, "-") == 0 || my_strcmp(fp, "~") == 0)
        return 0;
    if (errno == ENOTDIR) {
        my_putstr(fp);
        my_putstr(": Not a directory.\n");
    } else {
        my_putstr(fp);
        my_putstr(": No such file or directory.\n");
    }
    return 1;
}

char **setenv_cd(char *value, char *str)
{
    char **tab = malloc(sizeof(char *) * 4);

    if (tab == NULL)
        exit(84);
    tab[0] = my_strdup("SETENV");
    tab[1] = my_strdup(value);
    tab[2] = my_strdup(str);
    tab[3] = NULL;
    return tab;
}

char *get_path(char *str)
{
    char *tmp = malloc(sizeof(my_strlen(str)));

    if (tmp == NULL)
        exit(84);
    for (int i = 1; str[i] != '\0'; ++i) {
        tmp[i - 1] = str[i];
    }
    tmp[my_strlen(str) - 1] = '\0';
    return tmp;
}

char **my_cd(char **env, char **tab)
{
    char *pwd = my_getenv("PWD", env);
    char *new_pwd = NULL;
    char **new_env = NULL;

    if (tab_len(tab) == 1) {
        chdir(my_getenv("HOME", env));
        new_env = my_setenv(env, setenv_cd("PWD", my_getenv("HOME", env)));
        new_env = my_setenv(new_env, setenv_cd("OLDPWD", pwd));
    }
    if (tab_len(tab) == 2)
        new_env = handle_args(env, tab, new_pwd, new_env);
    if (tab_len(tab) > 3) {
        my_putstr("cd: Too many arguments.\n");
        new_env = my_tab_dup(env);
    }
    free(new_pwd);
    free(pwd);
    free_tab(env);
    return new_env;
}
/*
** EPITECH PROJECT, 2025
** B-PSU-210-LIL-2-1-bsminishell2-william.mallevays
** File description:
** Created by William,
*/

#include "../include/minishell2.h"

int count_sep(char *src)
{
    int i = 0;
    char *str = my_strdup(src);
    char *token = NULL;

    token = strtok(str, ";");
    for (; token != NULL; i++)
        token = strtok(NULL, ";");
    free(str);
    free(token);
    return i;
}

char **parse_sep(char *src)
{
    int count = count_sep(src);
    char **tab_path = NULL;
    char *str = my_strdup(src);
    char *token = NULL;

    tab_path = malloc(sizeof(char *) * (count + 1));
    if (tab_path == NULL)
        return NULL;
    tab_path[count] = NULL;
    token = strtok(str, ";");
    for (int i = 0; token != NULL; i++) {
        tab_path[i] = my_strdup(token);
        token = strtok(NULL, ";");
    }
    free(str);
    free(token);
    return tab_path;
}

int count_redir(char *src)
{
    int i = 0;
    char *str = my_strdup(src);
    char *token = NULL;

    token = strtok(str, "<>|");
    for (; token != NULL; i++)
        token = strtok(NULL, "<>|");
    free(str);
    free(token);
    return i;
}

char **parse_red(char *src)
{
    int count = count_redir(src);
    char **tab_path = NULL;
    char *str = my_strdup(src);
    char *token = NULL;

    tab_path = malloc(sizeof(char *) * (count + 1));
    if (tab_path == NULL)
        return NULL;
    tab_path[count] = NULL;
    token = strtok(str, "<>|");
    for (int i = 0; token != NULL; i++) {
        tab_path[i] = my_strdup(token);
        token = strtok(NULL, "<>|");
    }
    free(str);
    free(token);
    return tab_path;
}

char **exec_all_cmd(char *str, char **env)
{
    char **cmd = parse_sep(str);
    char **new_env = my_tab_dup(env);
    char **tab = NULL;
    int ret;
    int tmp;

    for (int i = 0; cmd[i] != NULL; ++i) {
        tab = init_redir(cmd, i, tab);
        tmp = select_dup(my_str_to_tab(cmd[i]), new_env, parse_red(cmd[i]));
        ret = select_redir(my_str_to_tab(cmd[i]), tmp, new_env, tab);
        if (tab != NULL && tmp >= 0) {
            new_env = check_builtin(tab, new_env);
            free_tab(tab);
        }
        if (ret >= 0 && tmp >= 0)
            dup2(tmp, ret);
    }
    free_tab(env);
    free_tab(cmd);
    return new_env;
}

/*
** EPITECH PROJECT, 2025
** B-PSU-210-LIL-2-1-minishell2-william.mallevays
** File description:
** Created by William,
*/

#include "../include/minishell2.h"

int redir_l_elem(char **tmp, int ret)
{
    if (my_strcmp(tmp[tab_len(tmp) - 1], ">") == 0 ||
        my_strcmp(tmp[tab_len(tmp) - 1], ">>") == 0) {
        my_putstr("Missing name for redirect.\n");
        return -1;
    } else if (my_strcmp(tmp[tab_len(tmp) - 1], "<") == 0 ||
        my_strcmp(tmp[tab_len(tmp) - 1], "<<") == 0) {
        my_putstr("Missing name for redirect.\n");
        return -1;
    } else
        return ret;
}

int handle_redir_err(char **tmp, char **env, char **tab)
{
    int ret = check_redir(tmp, env, tab);

    if (tmp == NULL || ret == -1)
        return -1;
    if (ret < 0) {
        my_putstr("Invalid null command.\n");
        return ret;
    } else {
        if (my_strcmp(tmp[0], ">") == 0 || my_strcmp(tmp[0], ">>") == 0) {
            my_putstr("Missing name for redirect.\n");
            return -1;
        } else if (my_strcmp(tmp[0], "<") == 0 ||
            my_strcmp(tmp[0], "<<") == 0) {
            my_putstr("Missing name for redirect.\n");
            return -1;
        } else
            return redir_l_elem(tmp, ret);
    }
}

int check_redir(char **tmp, char **env, char **tab)
{
    for (int i = 0; i < tab_len(tmp); ++i) {
        if (my_strcmp(tmp[i], ">") == 0)
            return 1;
        if (my_strcmp(tmp[i], ">>") == 0)
            return 2;
        if (my_strcmp(tmp[i], "<") == 0)
            return 3;
        if (my_strcmp(tmp[i], "<<") == 0)
            return 4;
        if (my_strcmp(tmp[i], "|") == 0) {
            if (i == 0 || i == tab_len(tmp) - 1) {
                my_putstr("Invalid null command.\n");
                return -1;
            }
            my_pipe(tab, env);
            return -1;
        }
    }
    return 0;
}

char **init_redir(char **cmd, int i, char **tab)
{
    tab = NULL;
    tab = parse_red(cmd[i]);
    tab = my_str_to_tab(tab[0]);
    return tab;
}

int select_dup(char **tab, char **env, char **cmd)
{
    int tmp = 0;
    int check = handle_redir_err(tab, env, cmd);

    if (check == 1 || check == 2)
        tmp = dup(STDOUT_FILENO);
    if (check == 3 || check == 4) {
        tmp = dup(STDIN_FILENO);
    }
    tmp = (check <= 0) ? check : tmp;
    return (tmp);
}
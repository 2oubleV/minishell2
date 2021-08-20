/*
** EPITECH PROJECT, 2025
** B-PSU-210-LIL-2-1-minishell2-william.mallevays
** File description:
** Created by William,
*/

#include "../include/minishell2.h"

int right_redir(char *fn)
{
    int fd = open(fn, O_WRONLY | O_CREAT | O_TRUNC, 0664);
    int new_fd;

    if (fd < 0)
        exit(84);
    new_fd = dup2(fd, STDOUT_FILENO);
    close(fd);
    return new_fd;
}

int d_right_redir(char *fn)
{
    int fd = open(fn, O_WRONLY | O_CREAT | O_APPEND, 0664);
    int new_fd;

    if (fd < 0) {
        my_putstr(fn);
        my_putstr(": No such file or directory.\n");
        return -1;
    }
    new_fd = dup2(fd, STDOUT_FILENO);
    close(fd);
    return new_fd;
}

int left_redir(char *fn)
{
    int fd = open(fn, O_RDONLY);
    int new_fd;

    if (fd < 0) {
        my_putstr(fn);
        my_putstr(": No such file or directory.\n");
        return -1;
    }
    new_fd = dup2(fd, STDIN_FILENO);
    return new_fd;
}

int select_redir(char **cmd, int tmp, char **env, char **tab)
{
    if (tmp <= 0)
        return 0;
    switch (check_redir(cmd, env, tab)) {
    case 1:
        return (right_redir(cmd[tab_len(cmd) - 1]));
        break;
    case 2:
        return (d_right_redir(cmd[tab_len(cmd) - 1]));
        break;
    case 3:
        return (left_redir(cmd[tab_len(cmd) - 1]));
        break;
    }
    return 0;
}
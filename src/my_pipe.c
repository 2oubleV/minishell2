/*
** EPITECH PROJECT, 2025
** B-PSU-210-LIL-2-1-minishell2-william.mallevays
** File description:
** Created by William,
*/

#include "../include/minishell2.h"

void exec_first(char **tab, int fd[2], char **env)
{
    int pid = fork();

    if (pid == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        do_exec(tab, env);
    }
}

void exec_last(char **tab, int fd[2], char **env)
{
    int pid = fork();
    if (pid == 0) {
        dup2(fd[0], STDIN_FILENO);
        close(fd[1]);
        do_exec(tab, env);
    }
}

void my_pipe(char **cmd, char **env)
{
    int fd[2];

    pipe(fd);
    exec_first(my_str_to_tab(cmd[0]), fd, env);
    exec_last(my_str_to_tab(cmd[1]), fd, env);
    waitpid(-1, NULL, 0);
}

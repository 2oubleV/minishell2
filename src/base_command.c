/*
** EPITECH PROJECT, 2020
** B-PSU-101-LIL-1-1-minishell1-william.mallevays
** File description:
** Created by william,
*/

#include "../include/minishell2.h"

char **fill_arg(char *str)
{
    char **arg = my_str_to_tab(str);
    char **ret_arg = malloc(sizeof(char *) * (tab_len(arg) + 1));

    if (ret_arg == NULL)
        return NULL;
    ret_arg[tab_len(arg)] = NULL;
    ret_arg[0] = NULL;
    for (int i = 1; arg[i] != NULL; ++i)
        ret_arg[i] = my_strdup(arg[i]);
    my_put_tab(ret_arg);
    free_tab(arg);
    return ret_arg;
}

void handle_sig(int status)
{
    if (status == SIGSEGV)
        perror("segmentation fault");
}

void do_exec(char **tab, char **env)
{
    char *tmp = tab[0];
    char *cmd = NULL;
    char **path = my_path_to_array(my_getenv("PATH", env));

    if (path != NULL) {
        for (int i = 0; path[i] != NULL; ++i) {
            cmd = NULL;
            cmd = my_strcat("/", path[i]);
            cmd = my_strcat(tab[0], cmd);
            execve(cmd, tab, env);
            free(cmd);
        }
    }
    execve(tab[0], tab, env);
    my_putstr(tab[0]);
    my_putstr(": Command not found.\n");
    free(tmp);
    free_tab(path);
    exit(0);
}

void my_exec(char **arg, char **env)
{
    int status;
    int child_pid = fork();

    if (child_pid == 0) {
        do_exec(arg, env);
    } else {
        waitpid(child_pid, &status, 0);
        handle_sig(status);
    }
}

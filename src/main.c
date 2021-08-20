/*
** EPITECH PROJECT, 2020
** B-PSU-101-LIL-1-1-minishell1-william.mallevays
** File description:
** Created by william,
*/

#include "../include/minishell2.h"

void free_tab(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i] != NULL; ++i)
        free(tab[i]);
    free(tab);
}

void my_put_tab(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i] != NULL; ++i) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}

char *get_command(char *str, char *path)
{
    char *tmp = malloc(sizeof(char) * my_strlen(str) + 1);
    char *dest = NULL;
    int i = 0;

    if (tmp == NULL)
        return NULL;
    my_putstr(str);
    while (str[i] != '\0') {
        tmp[i] = str[i];
        i++;
    }
    tmp[i] = '\0';
    dest = my_strcat(str, path);
    free(tmp);
    return dest;
}

int check_exit(char *tmp, char **env)
{
    char **tab = my_str_to_tab(tmp);

    if (my_strcmp(tab[0], "exit") == 0) {
        if (tab_len(tab) == 2 && my_str_isnum(tab[1]) == 0) {
            free_tab(env);
            my_putstr("exit\n");
            exit(my_getnbr(tab[1]));
        } else if (tab_len(tab) < 2) {
            free_tab(env);
            my_putstr("exit\n");
            exit(0);
        } else {
            my_putstr("exit: Expression Syntax\n");
            return 0;
        }
    }
    free_tab(tab);
    return 1;
}

int main(int ac, char **av, char **env)
{
    char *tmp = NULL;
    char **env_sh = my_tab_dup(env);
    size_t len = 0;

    if (ac != 1 || av[1] != NULL)
        return 84;
    while (1) {
        tmp = NULL;
        my_putstr("$> ");
        if (getline(&tmp, &len, stdin) == -1) {
            my_putstr("exit");
            exit(0);
        }
        if (tmp[0] != '\n') {
            tmp = clean_str(tmp);
            if (check_exit(tmp, env_sh) != 0)
                env_sh = exec_all_cmd(tmp, env_sh);
            free(tmp);
        }
    }
    return 0;
}
/*
** EPITECH PROJECT, 2020
** B-PSU-101-LIL-1-1-minishell2-william.mallevays
** File description:
** Created by william,
*/
#ifndef B_PSU_101_LIL_2_1_MINISHELL2_WILLIAM_MALLEVAYS_MINISHELL2_H
#define B_PSU_101_LIL_2_1_MINISHELL2_WILLIAM_MALLEVAYS_MINISHELL2_H

#include "./my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

void check_path(char **arg, char **env);
void my_exec(char **arg, char **env);
char **parse_arg(char *str);
void print_arg(char **arg);
char *my_getenv(char *find, char **env);
char *get_command(char *str, char *path);
char **fill_arg(char *str);
int tab_len(char **arg);
void my_put_tab(char **tab);
void my_env(char **env);
char *my_getenv(char *name, char **env);
char **my_path_to_array(char *path);
char **my_str_to_tab(char *str);
int check_var(char *name, char *n_env);
char *cpy_var(char *path, int len);
int check_var_env(char **env, char *name);
char **my_unsetenv(char **env, char **tab);
char **my_setenv(char **env, char **tab);
char **check_builtin(char **tab, char **env);
char **my_cd(char **env, char **tab);
char **parse_all_cmd(char *src);
char **exec_all_cmd(char *str, char **env);
void free_tab(char **tab);
int select_redir(char **cmd, int tmp, char **env, char **tab);
char **handle_wave(char **env, char **tab, char *new_pwd);
char **handle_two_args(char **env, char **tab, char *new_pwd);
char **handle_args(char **env, char **tab, char *new_pwd, char **new_env);
int is_dir(char *fp);
char **setenv_cd(char *value, char *str);
char *get_path(char *str);
char **parse_redir(char **tab);
char **init_redir(char **cmd, int i, char **tab);
char **parse_red(char *src);
int check_redir(char **tmp, char **env, char **tab);
int select_dup(char **tab, char **env, char **cmd);
int handle_redir_err(char **tmp, char **env, char **tab);
void do_exec(char **tab, char **env);
void my_pipe(char **cmd, char **env);

#endif //B_PSU_101_LIL_1_1_MINISHELL2_WILLIAM_MALLEVAYS_MINISHELL2_H

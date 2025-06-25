/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

typedef struct env_s {
    char *data;
    char *value;
    struct env_s *next;
} env_t;

typedef struct command_handler {
    char *cmd;
    int (*handler)(char **, env_t **, char *);
} command_handler_t;

char *get_path(env_t **envr);
char *get_command(char *buff, char *path, char **command);
int exec_command(char **word, env_t **envr, char *buff);
int check_signal(int status);
env_t **fill_env(env_t **envr, char **env);
char **env_to_array(env_t **envr);
void free_env(env_t *envr);
char *search_in_env(env_t *envr, const char *key);
int my_cd(char **word, env_t **envr, char *buff);
int print_env_list(char **word, env_t **envr, char *buff);
int my_setenv(char **word, env_t **envr, char *buff);
int my_unsetenv(char **word, env_t **envr, char *buff);
int check_for_exec(char *command, env_t **envr, char *buff);

#endif

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

typedef struct redirection_s {
    int type;
    char *file;
    struct redirection_s *next;
} redirection_t;

typedef struct command_handler {
    char *cmd;
    int (*handler)(char **, env_t **, char *);
} command_handler_t;

typedef struct command_s {
    char *input;
    char **input_array;
    char **first_element;
    char **all_path;
    redirection_t *redirections;
} command_t;

typedef struct pipe_data_s {
    int *pipefd;
    int cmd_count;
    env_t **envr;
    command_t *value;
} pipe_data_t;

env_t **fill_env(env_t **envr, char **env);
void free_env(env_t *envr);
char **env_to_array(env_t **envr);
int my_setenv(char **word, env_t **envr, char *buff);
int my_unsetenv(char **word, env_t **envr, char *buff);
int print_env_list(char **word, env_t **envr, char *buff);
char *search_in_env(env_t *envr, const char *key);

int check_signal(int status);
int check_core_dump(void);

int parse_command(command_t *value, env_t **envr);

int builtin_cd(char **word, env_t **envr, char *buff);
int builtin_exit(char **word, env_t **envr, char *buff);
int is_builtin(char *cmd);
int execute_builtin(char **args, env_t **envr, char *buff);
char *get_command_path(command_t *value, env_t **envr, char *command);
int handle_pipe(command_t *value, env_t **envr, char *input);

char **parse_redirections(char *input, redirection_t **redirections);
int *setup_redirections(redirection_t *redirections);
void restore_redirections(int *saved_fds);
void free_redirections(redirection_t *redirections);

#endif /* MY_H */

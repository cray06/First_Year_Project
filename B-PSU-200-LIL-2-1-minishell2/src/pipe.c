/*
** EPITECH PROJECT, 2025
** pipe.c
** File description:
** pipe.c
*/

#include "my.h"
#include "lib.h"

int *create_pipes(int cmd_count)
{
    int *pipefd = malloc(sizeof(int) * 2 * (cmd_count - 1));

    if (pipefd == NULL)
        exit(EXIT_FAILURE);
    for (int i = 0; i < cmd_count - 1; i++) {
        if (pipe(pipefd + i * 2) == -1)
            exit(EXIT_FAILURE);
    }
    return pipefd;
}

void close_pipes(int *pipefd, int cmd_count)
{
    for (int i = 0; i < 2 * (cmd_count - 1); i++)
        close(pipefd[i]);
    free(pipefd);
}

static void setup_in_out(pipe_data_t *data, int i)
{
    if (i != 0)
        dup2(data->pipefd[(i - 1) * 2], STDIN_FILENO);
    if (i != data->cmd_count - 1)
        dup2(data->pipefd[i * 2 + 1], STDOUT_FILENO);
    for (int j = 0; j < 2 * (data->cmd_count - 1); j++)
        close(data->pipefd[j]);
}

static void execute_command(char **args, env_t **envr, command_t *value)
{
    char *path;

    if (is_builtin(args[0]))
        exit(execute_builtin(args, envr, NULL));
    path = get_command_path(value, envr, args[0]);
    if (path == NULL) {
        my_putstr(args[0]);
        my_putstr(": Command not found.\n");
        exit(1);
    }
    execve(path, args, env_to_array(envr));
    exit(EXIT_FAILURE);
}

void execute_child(pipe_data_t *data, char *cmd, int i)
{
    char **args;
    redirection_t *redirections;
    int *saved_fds;

    redirections = NULL;
    setup_in_out(data, i);
    args = parse_redirections(cmd, &redirections);
    if (args == NULL || args[0] == NULL) {
        free_redirections(redirections);
        exit(0);
    }
    if (redirections != NULL && i == data->cmd_count - 1) {
        saved_fds = setup_redirections(redirections);
        if (saved_fds == NULL)
            exit(1);
    }
    execute_command(args, data->envr, data->value);
    free_word_array(args);
    free_redirections(redirections);
    exit(1);
}

static void process_commands(pipe_data_t *data, char **cmd_array)
{
    pid_t pid;

    for (int i = 0; i < data->cmd_count; i++) {
        pid = fork();
        if (pid == 0)
            execute_child(data, remove_trailing_space(cmd_array[i]), i);
    }
    close_pipes(data->pipefd, data->cmd_count);
    for (int i = 0; i < data->cmd_count; i++)
        wait(NULL);
}

int handle_pipe(command_t *value, env_t **envr, char *input)
{
    char **command_array;
    int nbr_cmd = 0;
    pipe_data_t data;

    command_array = my_str_to_word_array(input, "|");
    while (command_array[nbr_cmd] != NULL)
        nbr_cmd++;
    data = (pipe_data_t){create_pipes(nbr_cmd), nbr_cmd, envr, value};
    process_commands(&data, command_array);
    free_word_array(command_array);
    return 0;
}

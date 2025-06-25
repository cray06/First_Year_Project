/*
** EPITECH PROJECT, 2025
** handle_command.c
** File description:
** handle_command.c
*/
#include "lib.h"
#include "my.h"

int handle_builtin_or_error(char **command_input_array,
    env_t **envr, char *cmd)
{
    if (is_builtin(command_input_array[0]))
        return execute_builtin(command_input_array, envr, cmd);
    my_putstr(command_input_array[0]);
    my_putstr(": Command not found.\n");
    return 1;
}

int execute_command(char *path_of_command, char **command_input_array,
    char **env_array)
{
    pid_t p = fork();
    int status = 0;

    if (p == 0) {
        execve(path_of_command, command_input_array, env_array);
        exit(1);
    }
    waitpid(p, &status, 0);
    check_signal(status);
    return WEXITSTATUS(status);
}

char *prepare_command_path(command_t *value, env_t **envr,
    char **command_input_array)
{
    char *path_of_command =
        get_command_path(value, envr, command_input_array[0]);

    return path_of_command;
}

static int process_command(command_t *value, char **command_input_array,
    env_t **envr, char *cmd)
{
    char **env_array = env_to_array(envr);
    char *path_of_command;
    int status = 0;

    path_of_command = prepare_command_path(value, envr, command_input_array);
    if (path_of_command == NULL)
        status = handle_builtin_or_error(command_input_array, envr, cmd);
    else
        status = execute_command(path_of_command,
            command_input_array, env_array);
    free_word_array(env_array);
    return status;
}

int exec_single_command(command_t *value, char *cmd, env_t **envr)
{
    char **command_input_array;
    int *saved_fds = NULL;
    int status = 0;
    redirection_t *redirections = NULL;

    command_input_array = parse_redirections(cmd, &redirections);
    if (command_input_array == NULL || command_input_array[0] == NULL) {
        free_redirections(redirections);
        return 0;
    }
    if (redirections != NULL) {
        saved_fds = setup_redirections(redirections);
        if (saved_fds == NULL)
            return 1;
    }
    status = process_command(value, command_input_array, envr, cmd);
    if (saved_fds != NULL)
        restore_redirections(saved_fds);
    return status;
}

int parse_command(command_t *value, env_t **envr)
{
    int status = 0;

    for (int i = 0; value->input_array[i] != NULL; i++) {
        if (my_strchr(value->input_array[i], '|')) {
            handle_pipe(value, envr, value->input_array[i]);
        } else
            status = exec_single_command(value,
                remove_trailing_space(value->input_array[i]), envr);
    }
    return status;
}

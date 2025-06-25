/*
** EPITECH PROJECT, 2025
** exec.c
** File description:
** exec.c
*/

#include "lib.h"
#include "my.h"

const command_handler_t COMMANDS[] = {
    {"cd", my_cd},
    {"exit", exec_command},
    {"env", print_env_list},
    {"setenv", my_setenv},
    {"unsetenv", my_unsetenv},
    {NULL, NULL}
};

int handle_builtin_command(char **word, env_t **envr, char *buff)
{
    for (int i = 0; COMMANDS[i].cmd != NULL; i++) {
        if (my_strcmp(word[0], COMMANDS[i].cmd) == 0)
            return COMMANDS[i].handler(word, envr, buff);
    }
    return -1;
}

int handle_fork(char **word, char **buffer, env_t **envr)
{
    char **env = env_to_array(envr);

    if (env == NULL) {
        free_word_array(buffer);
        free_word_array(word);
        exit(errno);
    }
    execve(word[0], buffer, env);
    free_word_array(env);
    free_word_array(buffer);
    free_word_array(word);
    exit(errno);
}

int exec_command(char **word, env_t **envr, char *buff)
{
    pid_t p;
    int status = 0;
    char **buffer = my_str_to_word_array(buff, " \t");

    if (buffer == NULL) {
        free_word_array(word);
        return 84;
    }
    p = fork();
    if (p == 0)
        handle_fork(word, buffer, envr);
    waitpid(p, &status, 0);
    check_signal(status);
    if (my_strcmp(word[0], "exit") == 0) {
        my_putstr("exit\n");
        free_word_array(buffer);
        free_word_array(word);
        exit(WEXITSTATUS(status));
    }
    free_word_array(buffer);
    free_word_array(word);
    return WEXITSTATUS(status);
}

int check_for_exec(char *command, env_t **envr, char *buff)
{
    char **word = my_str_to_word_array(command, " \t");
    int result = 0;

    if (word == NULL)
        return 84;
    result = handle_builtin_command(word, envr, buff);
    if (result != -1) {
        free_word_array(word);
        return result;
    }
    if (access(word[0], X_OK)) {
        my_putstr(word[0]);
        my_putstr(": Command not found.\n");
        free_word_array(word);
        return 1;
    }
    return exec_command(word, envr, buff);
}

/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** main.c
*/

#include "lib.h"
#include "my.h"

void display_prompt(void)
{
    if (isatty(STDIN_FILENO))
        my_putstr("$> ");
}

int *minishell(env_t **envr, int *return_code)
{
    char *buff = NULL;
    char *command = NULL;
    size_t size = 0;
    char *path = get_path(envr);
    char *builtin[5] = {"cd", "setenv", "unsetenv", "exit", "env"};

    display_prompt();
    while (getline(&buff, &size, stdin) != -1) {
        for (int len = my_strlen(buff); len > 0 && (buff[len -1] == ' '
        || buff[len - 1] == '\n' || buff[len - 1] == '\t'); len--)
            buff[len - 1] = '\0';
        if (buff[0] != '\0') {
            command = get_command(buff, path, builtin);
            *return_code = check_for_exec(command, envr, buff);
            free(command);
        }
        display_prompt();
    }
    free(buff);
    free(path);
    return return_code;
}

int main(int argc, char **argv, char **env)
{
    int return_code = 0;
    env_t **envr = malloc(sizeof(env_t *));

    *envr = NULL;
    if (env == NULL || *env == NULL || envr == NULL) {
        free(envr);
        return 84;
    }
    if (fill_env(envr, env) == NULL) {
        free(envr);
        return 84;
    }
    if (argc > 1) {
        free_env(*envr);
        free(envr);
        return 84;
    }
    minishell(envr, &return_code);
    free_env(*envr);
    free(envr);
    return return_code;
}

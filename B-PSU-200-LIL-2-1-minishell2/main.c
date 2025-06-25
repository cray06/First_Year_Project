/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** main.c
*/

#include "my.h"
#include "lib.h"

static void display_prompt(void)
{
    if (isatty(STDIN_FILENO))
        my_putstr("$> ");
}

int *minishell(env_t **envr, int *return_code)
{
    size_t size = 0;
    command_t *value = malloc(sizeof(command_t));

    display_prompt();
    value->input = NULL;
    while (getline(&value->input, &size, stdin) != -1) {
        remove_trailing_space(value->input);
        if (value->input[0] != '\0') {
            value->input_array = my_str_to_word_array(value->input, ";");
            *return_code = parse_command(value, envr);
        }
        display_prompt();
    }
    free(value->input);
    free(value);
    return return_code;
}

int main(int argc, char **argv, char **env)
{
    int return_code = 0;
    env_t **envr = malloc(sizeof(env_t *));

    (void) argc;
    (void) argv;
    *envr = NULL;
    if (env == NULL || *env == NULL || envr == NULL) {
        free(envr);
        return 84;
    }
    if (fill_env(envr, env) == NULL) {
        free(envr);
        return 84;
    }
    minishell(envr, &return_code);
    free_env(*envr);
    free(envr);
    return return_code;
}

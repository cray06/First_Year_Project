/*
** EPITECH PROJECT, 2025
** handle_builtin.c
** File description:
** handle_builtin.c
*/

#include "my.h"
#include "lib.h"

static command_handler_t *get_command_handlers(void)
{
    static command_handler_t handlers[] = {
        {"cd", &builtin_cd},
        {"exit", &builtin_exit},
        {"setenv", &my_setenv},
        {"unsetenv", &my_unsetenv},
        {"env", &print_env_list},
        {NULL, NULL}
    };

    return handlers;
}

int builtin_cd(char **word, env_t **envr, char *buff)
{
    char *home_dir = NULL;

    (void)buff;
    if (word[1] == NULL) {
        home_dir = search_in_env(*envr, "HOME=");
        if (home_dir == NULL)
            return 1;
        if (chdir(home_dir) != 0)
            return 1;
    } else {
        if (chdir(word[1]) != 0) {
            my_putstr(word[1]);
            my_putstr(": No such file or directory.\n");
            return 1;
        }
    }
    return 0;
}

int builtin_exit(char **word, env_t **envr, char *buff)
{
    int exit_code = 0;

    (void)envr;
    (void)buff;
    if (word[1] != NULL)
        exit_code = 0;
    if (isatty(STDIN_FILENO))
        my_putstr("exit\n");
    exit(exit_code);
    return exit_code;
}

int is_builtin(char *cmd)
{
    command_handler_t *handlers = get_command_handlers();

    for (int i = 0; handlers[i].cmd != NULL; i++) {
        if (my_strcmp(cmd, handlers[i].cmd) == 0)
            return 1;
    }
    return 0;
}

int execute_builtin(char **args, env_t **envr, char *buff)
{
    command_handler_t *handlers = get_command_handlers();

    for (int i = 0; handlers[i].cmd != NULL; i++) {
        if (my_strcmp(args[0], handlers[i].cmd) == 0)
            return handlers[i].handler(args, envr, buff);
    }
    return -1;
}

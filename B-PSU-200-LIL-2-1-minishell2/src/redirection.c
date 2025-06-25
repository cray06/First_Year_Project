/*
** EPITECH PROJECT, 2025
** redirection.c
** File description:
** Handle file redirections for the shell
*/

#include "lib.h"
#include "my.h"

static int is_redirection(char *token)
{
    return (my_strcmp(token, "<") == 0 || my_strcmp(token, ">") == 0 ||
        my_strcmp(token, ">>") == 0 || my_strcmp(token, "<<") == 0);
}

static int get_redirection_type(char *token)
{
    if (my_strcmp(token, "<") == 0)
        return 1;
    if (my_strcmp(token, ">") == 0)
        return 2;
    if (my_strcmp(token, ">>") == 0)
        return 3;
    if (my_strcmp(token, "<<") == 0)
        return 4;
    return 0;
}

static void add_redirection(redirection_t **redirections, int type, char *file)
{
    redirection_t *new_redir = malloc(sizeof(redirection_t));
    redirection_t *current;

    if (new_redir == NULL)
        return;
    new_redir->type = type;
    new_redir->file = my_strdup(file);
    new_redir->next = NULL;
    if (*redirections == NULL) {
        *redirections = new_redir;
        return;
    }
    current = *redirections;
    while (current->next != NULL)
        current = current->next;
    current->next = new_redir;
}

char **parse_redirections(char *input, redirection_t **redirections)
{
    char **array = my_str_to_word_array(input, " \t\n");
    char **command = malloc(sizeof(char *) * (my_strlen(input) + 1));
    int cmd_index = 0;

    if (command == NULL || array == NULL)
        return NULL;
    for (int i = 0; array[i] != NULL; i++) {
        if (is_redirection(array[i]) && array[i + 1] != NULL) {
            add_redirection(redirections, get_redirection_type(array[i]),
                array[i + 1]);
            i++;
        } else {
            command[cmd_index] = my_strdup(array[i]);
            cmd_index++;
        }
    }
    command[cmd_index] = NULL;
    free_word_array(array);
    return command;
}

static int handle_input_redirection(redirection_t *redir)
{
    int fd = open(redir->file, O_RDONLY);

    if (fd == -1) {
        my_putstr(redir->file);
        my_putstr(": No such file or directory.\n");
        return -1;
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
    return 0;
}

static int handle_output_redirection(redirection_t *redir)
{
    int fd;
    int flags;

    if (redir->type == 2)
        flags = O_WRONLY | O_CREAT | O_TRUNC;
    else
        flags = O_WRONLY | O_CREAT | O_APPEND;
    fd = open(redir->file, flags, 0644);
    if (fd == -1)
        return -1;
    dup2(fd, STDOUT_FILENO);
    close(fd);
    return 0;
}

static int handle_heredoc(redirection_t *redir)
{
    char *line = NULL;
    size_t len = 0;
    int pipe_fd[2];

    if (pipe(pipe_fd) == -1)
        return -1;
    my_putstr("heredoc> ");
    while (getline(&line, &len, stdin) != -1) {
        line[my_strlen(line) - 1] = '\0';
        if (my_strcmp(line, redir->file) == 0)
            break;
        write(pipe_fd[1], line, my_strlen(line));
        write(pipe_fd[1], "\n", 1);
        my_putstr("heredoc> ");
    }
    free(line);
    close(pipe_fd[1]);
    return pipe_fd[0];
}

static int handle_single_redirection(redirection_t *redir)
{
    int fd;

    if (redir->type == 1)
        return handle_input_redirection(redir);
    if (redir->type == 2 || redir->type == 3)
        return handle_output_redirection(redir);
    if (redir->type == 4) {
        fd = handle_heredoc(redir);
        if (fd == -1)
            return -1;
        dup2(fd, STDIN_FILENO);
        close(fd);
    }
    return 0;
}

static int *cleanup_redirections(int *saved)
{
    if (saved == NULL)
        return NULL;
    dup2(saved[0], STDIN_FILENO);
    dup2(saved[1], STDOUT_FILENO);
    close(saved[0]);
    close(saved[1]);
    free(saved);
    return NULL;
}

int *setup_redirections(redirection_t *redirections)
{
    int *saved = malloc(2 * sizeof(int));
    redirection_t *current = redirections;

    if (saved == NULL)
        return NULL;
    saved[0] = dup(STDIN_FILENO);
    saved[1] = dup(STDOUT_FILENO);
    if (saved[0] == -1 || saved[1] == -1) {
        free(saved);
        return NULL;
    }
    while (current != NULL) {
        if (handle_single_redirection(current) == -1)
            return cleanup_redirections(saved);
        current = current->next;
    }
    return saved;
}

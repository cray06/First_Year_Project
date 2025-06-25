/*
** EPITECH PROJECT, 2025
** redirection_bis.c
** File description:
** redirection_bis.c
*/

#include "my.h"
#include "lib.h"

void restore_redirections(int *saved_fds)
{
    if (saved_fds == NULL)
        return;
    dup2(saved_fds[0], STDIN_FILENO);
    dup2(saved_fds[1], STDOUT_FILENO);
    close(saved_fds[0]);
    close(saved_fds[1]);
    free(saved_fds);
}

void free_redirections(redirection_t *redirections)
{
    redirection_t *temp;

    while (redirections != NULL) {
        temp = redirections;
        redirections = redirections->next;
        free(temp->file);
        free(temp);
    }
}

/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** main.c
*/

#include "include/my.h"

void handle_terminal_echo(struct termios *term, int enable)
{
    tcgetattr(fileno(stdin), term);
    if (enable)
        term->c_lflag |= ECHO;
    else
        term->c_lflag &= ~ECHO;
    tcsetattr(fileno(stdin), 0, term);
}

int validate_password_attempt(char *passwd, user_t *user_info, int attempt)
{
    struct termios term;

    printf("[my_sudo] password for %s: ", user_info->user);
    handle_terminal_echo(&term, 0);
    scanf("%s", passwd);
    handle_terminal_echo(&term, 1);
    if (check_passwd(passwd, user_info) == 1) {
        write(1, "\n", 1);
        return 1;
    }
    if (attempt == 2) {
        printf("\nmy_sudo: 3 incorrect password attempts\n");
        return 84;
    }
    printf("\nSorry, try again.\n");
    return 0;
}

int request_passwd(char *passwd, user_t *user_info)
{
    int result;

    if (!my_strcmp(user_info->user, "root"))
        return 1;
    for (int i = 0; i < 3; i++) {
        result = validate_password_attempt(passwd, user_info, i);
        if (result == 1 || result == 84)
            return result;
    }
    return 84;
}

int executing(char *argv[], char *passwd, user_t *user_info)
{
    if (user_info->sudo_ers != NULL) {
        if (check_in_sudoers(user_info) == 84)
            return 84;
    }
    if (request_passwd(passwd, user_info) == 1) {
        setuid(user_info->user_id);
        setgid(user_info->group_id);
        execvp(argv[0], argv);
    }
    return 0;
}

int main(int argc, char *argv[])
{
    user_t *user_info = malloc(sizeof(user_t));
    char passwd[256];

    if (user_info == NULL)
        return 84;
    if (argc < 2 || (argv[1][0] == '-' && argv[1][1] == 'h')) {
        write(1, "usage: ./my_sudo -h\n", 20);
        write(1, "usage: ./my_sudo [-ugEs] [command [args ...]]\n", 46);
        return 0;
    }
    user_info->user = get_id(user_info);
    user_info->user_id = 0;
    user_info->group_id = 0;
    process_flags(argv, user_info);
    return executing(command(argv), passwd, user_info);
}

/*
** EPITECH PROJECT, 2024
** printing_file_l.c
** File description:
** printing_file_l.c
*/

#include "include/my.h"

void get_permissions(mode_t mode, char *permissions)
{
    permissions[0] = (S_ISDIR(mode)) ? 'd' : '-';
    permissions[1] = (mode & S_IRUSR) ? 'r' : '-';
    permissions[2] = (mode & S_IWUSR) ? 'w' : '-';
    permissions[3] = (mode & S_IXUSR) ? 'x' : '-';
    permissions[4] = (mode & S_IRGRP) ? 'r' : '-';
    permissions[5] = (mode & S_IWGRP) ? 'w' : '-';
    permissions[6] = (mode & S_IXGRP) ? 'x' : '-';
    permissions[7] = (mode & S_IROTH) ? 'r' : '-';
    permissions[8] = (mode & S_IWOTH) ? 'w' : '-';
    permissions[9] = (mode & S_IXOTH) ? 'x' : '-';
    permissions[10] = '\0';
}

char *get_time(time_t mod_time)
{
    char *full_time = ctime(&mod_time);
    char *formatted_time = malloc(15);

    my_strncpy(formatted_time, full_time + 4, 3);
    formatted_time[3] = ' ';
    my_strncpy(formatted_time + 4, full_time + 8, 2);
    formatted_time[6] = ' ';
    my_strncpy(formatted_time + 7, full_time + 11, 2);
    formatted_time[9] = ':';
    my_strncpy(formatted_time + 10, full_time + 14, 2);
    formatted_time[12] = '\0';
    return formatted_time;
}

void get_file_info(const char *filename, struct FileInfo *file_info)
{
    struct stat file_stat;
    struct passwd *pw;
    struct group *grp;

    if (stat(filename, &file_stat) != 0) {
        perror("stat");
        return;
    }
    pw = getpwuid(file_stat.st_uid);
    grp = getgrgid(file_stat.st_gid);
    get_permissions(file_stat.st_mode, file_info->permissions);
    file_info->links = file_stat.st_nlink;
    file_info->owner = my_strdup(pw->pw_name);
    file_info->group = my_strdup(grp->gr_name);
    file_info->size = file_stat.st_size;
    file_info->mod_time = get_time(file_stat.st_mtime);
    file_info->mod_time_comp = file_stat.st_mtime;
}

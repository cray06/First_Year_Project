/*
** EPITECH PROJECT, 2024
** printing_file.c
** File description:
** printing_file
*/

#include "include/my.h"

void file_information(DIR *dir, struct DirectoryContent *content, char *flags,
    int *count)
{
    struct dirent *file;
    int i = 0;

    file = readdir(dir);
    while (file != NULL) {
        if (file->d_name[0] != '.' || include_hidden(flags) == 1) {
            content->files[i].name = my_strdup(file->d_name);
            i++;
        }
        file = readdir(dir);
    }
    *count = i;
}

void create_array(struct DirectoryContent *content, int count)
{
    for (int i = 0; i < count; i++) {
        content->files[i].name = my_strdup(content->files[i].name);
    }
}

void print_file_names(struct DirectoryContent *content, int count)
{
    for (int i = 0; i < count; i++) {
        my_putstr(content->files[i].name);
        my_putchar(' ');
        free(content->files[i].name);
    }
    my_putchar('\n');
}

void free_memory(struct DirectoryContent *content)
{
    free(content->files);
}

static void print_file_info(struct FileInfo *file_info)
{
    my_putstr(file_info->permissions);
    my_putchar(' ');
    my_put_nbr(file_info->links);
    my_putchar(' ');
    my_putstr(file_info->owner);
    my_putchar(' ');
    my_putstr(file_info->group);
    my_putchar(' ');
    my_put_nbr(file_info->size);
    my_putchar(' ');
    my_putstr(file_info->mod_time);
    my_putchar(' ');
    my_putstr(file_info->name);
    my_putchar('\n');
}

static char *build_full_path(const char *directory_path, const char *file_name)
{
    char *path;

    path = malloc(my_strlen(file_name) + my_strlen(directory_path) + 2);
    path = my_strcpy(path, directory_path);
    path = my_strcat(path, "/");
    path = my_strcat(path, file_name);
    return path;
}

static void print_file_details(struct DirectoryContent *content,
    char *directory_path, int count)
{
    char *full_path;

    for (int i = 0; i < count; i++) {
        full_path = build_full_path(directory_path, content->files[i].name);
        get_file_info(full_path, &content->files[i]);
        print_file_info(&content->files[i]);
        free(full_path);
    }
}

static void handle_time_sorting(struct TimeSortingParams *params)
{
    char *directory_path;
    char *full_path;

    if (params->argc == 1)
        directory_path = "./";
    else
        directory_path = params->argv;
    for (int i = 0; i < params->count; i++) {
        full_path = build_full_path(directory_path,
            params->content->files[i].name);
        get_file_info(full_path, &params->content->files[i]);
        free(full_path);
    }
    sort_file_time(params->content, params->count, params->flags);
}

static void initialize_time_sorting_params(struct TimeSortingParams *params,
    int argc, int count, char *flags)
{
    params->flags = flags;
    params->argc = argc;
    params->count = count;
}

void print_files_in_directory(DIR *dir, char *flags, int argc, char *argv)
{
    struct DirectoryContent content;
    struct TimeSortingParams params;
    int count = 0;
    char *directory_path = (argc == 1) ? "./" : argv;

    content.files = malloc(sizeof(struct FileInfo) * 20000);
    file_information(dir, &content, flags, &count);
    create_array(&content, count);
    sort_files(&content, count, flags);
    if (time_sorting(flags) == 1) {
        params.content = &content;
        params.argv = argv;
        initialize_time_sorting_params(&params, argc, count, flags);
        handle_time_sorting(&params);
    }
    if (long_print(flags) == 0) {
        print_file_names(&content, count);
        free_memory(&content);
    } else
        print_file_details(&content, directory_path, count);
}

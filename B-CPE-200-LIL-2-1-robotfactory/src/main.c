/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/
#include "asm.h"

linked_list_t *change_file_in_list(FILE *fptr)
{
    char *line = NULL;
    char **array;
    line_t *line_list;
    linked_list_t *list = NULL;

    while (getline(&line, &(size_t){1}, fptr) != -1){
        line[my_strlen(line) - 1] = '\0';
        array = my_str_to_word_array(line, " ,\t");
        line_list = set_line(array);
        push_to_list(&list, line_list);
    }
    free(line);
    return list;
}

void free_list(linked_list_t *list)
{
    if (list != NULL){
        if (list->next != NULL)
            free_list(list->next);
        free_word_array((line_t *){list->data}->array);
        free(list->data);
        free(list);
    }
}

static char *create_name(char **words)
{
    char *filename = malloc(sizeof(char) *
        (my_strlen(words[len_word_array(words) - 2]) + 5));

    if (filename == NULL){
        free_word_array(words);
        return NULL;
    }
    my_strcpy(filename, words[len_word_array(words) - 2]);
    filename = my_strcat(filename, ".cor");
    free_word_array(words);
    return filename;
}

FILE *create_cor_file(char *path)
{
    FILE *fptr = NULL;
    char *filename;
    char **words = my_str_to_word_array(path, "/. ");

    if (path == NULL)
        return NULL;
    if (my_strcmp(words[len_word_array(words) - 1], "s"))
        return NULL;
    filename = create_name(words);
    fptr = fopen(filename, "w");
    free(filename);
    return fptr;
}

static void write_in_file(FILE *cor_file, linked_list_t *list)
{
    header_t header = get_header_file(list);

    fwrite(&header, sizeof(header), 1, cor_file);
    write_body(list, cor_file, list);
}

int main(int ac, char **av)
{
    FILE *fptr = fopen(av[1], "r");
    FILE *cor_file = NULL;
    linked_list_t *list = NULL;

    if (fptr == NULL)
        return 84;
    list = change_file_in_list(fptr);
    if (!check_file(list)){
        free_list(list);
        fclose(fptr);
        return 84;
    }
    cor_file = create_cor_file(av[1]);
    if (cor_file == NULL)
        return 84;
    write_in_file(cor_file, list);
    fclose(fptr);
    fclose(cor_file);
    free_list(list);
    return 0;
}

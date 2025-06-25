/*
** EPITECH PROJECT, 2025
** check_types
** File description:
** check_types
*/

#include "dataframe.h"

int is_int(char *data)
{
    for (int i = 0; data[i] != '\0'; i++){
        if ((data[i] < 48 || data[i] > 57) ||
            (data[0] != '-' || data[0] != '+'))
            return 0;
    }
    return 1;
}

int is_uint(char *data)
{
    for (int i = 0; data[i] != '\0'; i++){
        if ((data[i] < 48 || data[i] > 57))
            return 0;
    }
    return 1;
}

int is_float(char *data)
{
    int point = 0;

    for (int i = 0; data[i] != '\0'; i++){
        if ((data[i] < 48 || data[i] > 57) && data[i] != '-' && data[i] != '.')
            return 0;
        if (data[i] == '.')
            point++;
    }
    if (point == 1 && data[strlen(data) - 1] != '.')
        return 1;
    return 0;
}

int is_bool(char *data)
{
    char *temp = my_strlowcase(my_strdup(data));

    if (!strcmp(temp, "true") || !strcmp(temp, "false")){
        free(temp);
        return 1;
    }
    free(temp);
    return 0;
}

int is_string(char *data)
{
    if (!is_uint(data) && !is_float(data) &&
        !is_bool(data) && is_int(data))
        return 1;
    return 0;
}

/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Main File
*/

#include "include/shell.h"

void split_list(linked_t *source, linked_t **first_half,
    linked_t **second_half)
{
    linked_t *one_per_one;
    linked_t *two_per_two;

    one_per_one = source;
    two_per_two = source->next;
    while (two_per_two != NULL) {
        two_per_two = two_per_two->next;
        if (two_per_two != NULL) {
            one_per_one = one_per_one->next;
            two_per_two = two_per_two->next;
        }
    }
    *first_half = source;
    *second_half = one_per_one->next;
    one_per_one->next = NULL;
}

linked_t *sorted_merge(linked_t *a, linked_t *b, sort_params_t *params)
{
    linked_t *result = NULL;
    int cmp_result = 0;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    for (int i = 0; i < params->cmp_count && cmp_result == 0; i++)
        cmp_result = params->cmps[i].compare(a, b);
    if (params->reverse)
        cmp_result = -cmp_result;
    if (cmp_result <= 0) {
        result = a;
        result->next = sorted_merge(a->next, b, params);
    } else {
        result = b;
        result->next = sorted_merge(a, b->next, params);
    }
    return result;
}

void merge_sort(linked_t **head_ref, sort_params_t *params)
{
    linked_t *head = *head_ref;
    linked_t *a;
    linked_t *b;

    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    split_list(head, &a, &b);
    merge_sort(&a, params);
    merge_sort(&b, params);
    *head_ref = sorted_merge(a, b, params);
}

int set_comparators(const char *arg, compare_func_t *cmps,
    int *cmp_count, int *reverse)
{
    const char *valid_args[] = {"ID", "NAME", "TYPE"};
    int (*comparators[])(linked_t *, linked_t *) = {
        compare_by_id,
        compare_by_name,
        compare_by_type
    };

    for (int i = 0; i < 3; ++i) {
        if (my_strcmp(arg, valid_args[i]) == 0) {
            cmps[*cmp_count].compare = comparators[i];
            (*cmp_count)++;
            return 0;
        }
    }
    if (my_strcmp(arg, "-r") == 0) {
        *reverse = 1;
        return 0;
    }
    return 84;
}

int sort(void *data, char **args)
{
    linked_t **list = data;
    compare_func_t cmps[3];
    int cmp_count = 0;
    int reverse = 0;
    sort_params_t params;

    if (list == NULL || *list == NULL)
        return 84;
    for (int i = 0; args[i] != NULL; i++) {
        if (set_comparators(args[i], cmps, &cmp_count, &reverse) != 0)
            return 84;
    }
    params.cmps = cmps;
    params.cmp_count = cmp_count;
    params.reverse = reverse;
    merge_sort(list, &params);
    return 0;
}

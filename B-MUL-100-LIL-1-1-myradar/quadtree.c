/*
** EPITECH PROJECT, 2025
** quadtree.c
** File description:
** quadtree.c
*/

#include "include/my.h"

quad_tree_t *create_quadtree(Rectangleshape_t border, int capacity)
{
    quad_tree_t *qt = malloc(sizeof(quad_tree_t));

    if (qt == NULL)
        return NULL;
    qt->border = border;
    qt->capacity = capacity;
    qt->planes = malloc(sizeof(plane_parsing_t *) * capacity);
    if (qt->planes == NULL)
        return NULL;
    qt->count = 0;
    qt->topleft = NULL;
    qt->topright = NULL;
    qt->bottomleft = NULL;
    qt->bottomright = NULL;
    return qt;
}

bool is_in_border(Rectangleshape_t border, plane_parsing_t *plane)
{
    return plane->x_current >= border.left
        && plane->x_current < border.left + border.width
        && plane->y_current >= border.top
        && plane->y_current < border.top + border.height;
}

void split(quad_tree_t *qt)
{
    float x = qt->border.left;
    float y = qt->border.top;
    float w = qt->border.width / 2;
    float h = qt->border.height / 2;

    qt->topleft =
        create_quadtree((Rectangleshape_t){x, y, w, h}, qt->capacity);
    qt->topright =
        create_quadtree((Rectangleshape_t){x + w, y, w, h}, qt->capacity);
    qt->bottomleft =
        create_quadtree((Rectangleshape_t){x, y + h, w, h}, qt->capacity);
    qt->bottomright =
        create_quadtree((Rectangleshape_t){x + w, y + h, w, h}, qt->capacity);
}

void redistribute_planes(quad_tree_t *qt)
{
    for (int i = 0; i < qt->count; i++) {
        if (insert(qt->topleft, qt->planes[i]))
            continue;
        if (insert(qt->topright, qt->planes[i]))
            continue;
        if (insert(qt->bottomleft, qt->planes[i]))
            continue;
        if (insert(qt->bottomright, qt->planes[i]))
            continue;
    }
    qt->count = 0;
}

bool insert(quad_tree_t *qt, plane_parsing_t *plane)
{
    if (!is_in_border(qt->border, plane))
        return false;
    if (qt->count < qt->capacity && qt->topleft == NULL) {
        qt->planes[qt->count] = plane;
        qt->count++;
        return true;
    }
    if (qt->topleft == NULL) {
        split(qt);
        redistribute_planes(qt);
    }
    if (insert(qt->topleft, plane))
        return true;
    if (insert(qt->topright, plane))
        return true;
    if (insert(qt->bottomleft, plane))
        return true;
    if (insert(qt->bottomright, plane))
        return true;
    return false;
}

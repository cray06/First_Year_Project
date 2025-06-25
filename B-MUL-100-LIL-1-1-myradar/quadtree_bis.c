/*
** EPITECH PROJECT, 2025
** quadtree_bis.c
** File description:
** quadtree_bis.c
*/

#include "include/my.h"

void search(quad_tree_t *qt, Rectangleshape_t range,
    plane_parsing_t **found, int *count)
{
    if (!rectangles_intersect(qt->border, range)) {
        return;
    }
    for (int i = 0; i < qt->count; i++) {
        if (is_in_border(range, qt->planes[i])) {
            found[(*count)] = qt->planes[i];
            (*count)++;
        }
    }
    if (qt->topleft == NULL)
        return;
    search(qt->topleft, range, found, count);
    search(qt->topright, range, found, count);
    search(qt->bottomleft, range, found, count);
    search(qt->bottomright, range, found, count);
}

bool is_in_control_area(plane_parsing_t *plane,
    tower_parsing_t **towers, int num_towers)
{
    float dx = 0;
    float dy = 0;
    float distance = 0;

    for (int i = 0; i < num_towers; i++) {
        dx = plane->x_current - towers[i]->x_pos;
        dy = plane->y_current - towers[i]->y_pos;
        distance = sqrt(dx * dx + dy * dy);
        if (distance < towers[i]->radius * 5)
            return true;
    }
    return false;
}

bool rectangles_intersect(Rectangleshape_t rect1, Rectangleshape_t rect2)
{
    return (rect1.left < rect2.left + rect2.width &&
            rect1.left + rect1.width > rect2.left &&
            rect1.top < rect2.top + rect2.height &&
            rect1.top + rect1.height > rect2.top);
}

bool check_collision(plane_parsing_t *plane1, plane_parsing_t *plane2)
{
    sfVector2f size1;
    sfVector2f size2;
    sfVector2f position1;
    sfVector2f position2;
    Rectangleshape_t rect1;
    Rectangleshape_t rect2;

    position1 = (sfVector2f){plane1->x_current, plane1->y_current};
    position2 = (sfVector2f){plane2->x_current, plane2->y_current};
    size1 = sfRectangleShape_getSize(plane1->rectangle);
    size2 = sfRectangleShape_getSize(plane2->rectangle);
    rect1 = (Rectangleshape_t){position1.x, position1.y, size1.x, size1.y};
    rect2 = (Rectangleshape_t){position2.x, position2.y, size2.x, size2.y};
    return rectangles_intersect(rect1, rect2);
}

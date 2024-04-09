/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** delete_link
*/

#include <stdlib.h>
#include "link_team_user.h"

void delete_link(link_team_user_t *link)
{
    if (link == NULL)
        return;
    free(link);
}

void clear_link_list(link_team_user_list_t *list)
{
    link_team_user_t *tmp;
    link_team_user_t *next = NULL;

    if (list == NULL)
        return;
    for (tmp = list->head; tmp; tmp = next) {
        next = tmp->next;
        delete_link(tmp);
    }
}

void delete_link_list(link_team_user_list_t *list)
{
    if (list == NULL)
        return;
    clear_link_list(list);
    free(list);
}

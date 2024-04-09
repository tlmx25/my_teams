/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** add_link
*/

#include <stdlib.h>
#include "link_team_user.h"

void add_link(link_team_user_list_t *list, link_team_user_t *link)
{
    if (list == NULL || link == NULL)
        return;
    if (list->head == NULL) {
        list->head = link;
        list->tail = link;
        link->prev = NULL;
        link->next = NULL;
    } else {
        list->tail->next = link;
        link->prev = list->tail;
        link->next = NULL;
        list->tail = link;
    }
    list->size++;
}

void create_link_and_add(link_team_user_list_t *list, uuid_t team_uuid,
    uuid_t user_uuid)
{
    link_team_user_t *link = create_link(team_uuid, user_uuid);

    if (link == NULL)
        return;
    add_link(list, link);
}

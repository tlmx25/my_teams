/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** create_link
*/

#include <stdlib.h>
#include "link_team_user.h"

link_team_user_t *create_link(uuid_t team_uuid, uuid_t user_uuid)
{
    link_team_user_t *link = malloc(sizeof(link_team_user_t));

    if (link == NULL)
        return NULL;
    uuid_copy(link->team_uuid, team_uuid);
    uuid_copy(link->user_uuid, user_uuid);
    link->prev = NULL;
    link->next = NULL;
    return link;
}

link_team_user_list_t *create_link_list(void)
{
    link_team_user_list_t *list = malloc(sizeof(link_team_user_list_t));

    if (list == NULL)
        return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

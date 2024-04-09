/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** remove_link
*/

#include <stdlib.h>
#include "link_team_user.h"

void remove_link(link_team_user_list_t *list, link_team_user_t *link)
{
    if (list == NULL || link == NULL)
        return;
    if (link->prev)
        link->prev->next = link->next;
    if (link->next)
        link->next->prev = link->prev;
    if (list->head == link)
        list->head = link->next;
    if (list->tail == link)
        list->tail = link->prev;
    list->size--;
    delete_link(link);
}

void remove_link_by_uuid(link_team_user_list_t *list, uuid_t team_uuid,
    uuid_t user_uuid)
{
    link_team_user_t *tmp;

    if (list == NULL)
        return;
    for (tmp = list->head; tmp; tmp = tmp->next) {
        if (uuid_compare(tmp->team_uuid, team_uuid) == 0 &&
            uuid_compare(tmp->user_uuid, user_uuid) == 0) {
            remove_link(list, tmp);
            return;
        }
    }
}

void remove_link_by_uuid_str(link_team_user_list_t *list, char const *team_uuid,
    char const *user_uuid)
{
    uuid_t uuid_team_uuid;
    uuid_t uuid_user_uuid;

    if (list == NULL)
        return;
    uuid_parse(team_uuid, uuid_team_uuid);
    uuid_parse(user_uuid, uuid_user_uuid);
    remove_link_by_uuid(list, uuid_team_uuid, uuid_user_uuid);
}

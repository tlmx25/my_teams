/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** get_link
*/

#include <stdlib.h>
#include "link_team_user.h"

link_team_user_t *get_link(link_team_user_list_t *list, uuid_t team_uuid,
uuid_t user_uuid)
{
    link_team_user_t *tmp;

    if (list == NULL)
        return NULL;
    for (tmp = list->head; tmp; tmp = tmp->next) {
        if (uuid_compare(tmp->team_uuid, team_uuid) == 0 &&
            uuid_compare(tmp->user_uuid, user_uuid) == 0)
            return tmp;
    }
    return NULL;
}

link_team_user_t *get_link_str(link_team_user_list_t *list, char *team_uuid,
    char *user_uuid)
{
    uuid_t team_uuid_uuid;
    uuid_t user_uuid_uuid;

    if (list == NULL)
        return NULL;
    uuid_parse(team_uuid, team_uuid_uuid);
    uuid_parse(user_uuid, user_uuid_uuid);
    return get_link(list, team_uuid_uuid, user_uuid_uuid);
}

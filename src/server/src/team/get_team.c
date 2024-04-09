/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** get_team
*/

#include <string.h>
#include "team.h"

team_t *get_team_by_uuid(team_list_t *list, uuid_t uuid)
{
    team_t *tmp;

    if (list == NULL)
        return NULL;
    for (tmp = list->head; tmp; tmp = tmp->next) {
        if (uuid_compare(tmp->uuid, uuid) == 0)
            return tmp;
    }
    return NULL;
}

team_t *get_team_by_name(team_list_t *list, char const *name)
{
    team_t *tmp;

    if (list == NULL)
        return NULL;
    for (tmp = list->head; tmp; tmp = tmp->next) {
        if (strcmp(tmp->name, name) == 0)
            return tmp;
    }
    return NULL;
}

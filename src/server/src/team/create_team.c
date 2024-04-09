/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** create_team
*/

#include <stdlib.h>
#include "my.h"
#include "team.h"

team_t *create_team(char const *name, char const *description, uuid_t uuid,
    uuid_t owner_uuid)
{
    team_t *team = malloc(sizeof(team_t));

    if (team == NULL)
        return NULL;
    uuid_copy(team->uuid, uuid);
    uuid_copy(team->owner_uuid, owner_uuid);
    team->name = my_strdup(name);
    team->description = my_strdup(description);
    team->prev = NULL;
    team->next = NULL;
    return team;
}

team_list_t *create_team_list(void)
{
    team_list_t *list = malloc(sizeof(team_list_t));

    if (list == NULL)
        return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

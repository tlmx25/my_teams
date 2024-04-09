/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** delete_team
*/

#include <stdlib.h>
#include "team.h"

void delete_team(team_t *team)
{
    if (team == NULL)
        return;
    if (team->name)
        free(team->name);
    if (team->description)
        free(team->description);
    free(team);
}

void clear_team_list(team_list_t *list)
{
    team_t *tmp;
    team_t *next = NULL;

    if (list == NULL)
        return;
    for (tmp = list->head; tmp; tmp = next) {
        next = tmp->next;
        delete_team(tmp);
    }
}

void delete_team_list(team_list_t *list)
{
    team_t *tmp;
    team_t *next = NULL;

    if (list == NULL)
        return;
    for (tmp = list->head; tmp; tmp = next) {
        next = tmp->next;
        delete_team(tmp);
    }
    free(list);
}

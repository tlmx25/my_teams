/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** remove_team
*/

#include "team.h"

void remove_team_from_list(team_list_t *list, team_t *team)
{
    team_t *tmp;

    if (list == NULL || team == NULL)
        return;
    for (tmp = list->head; tmp; tmp = tmp->next);
    if (tmp == NULL)
        return;
    if (tmp->prev)
        tmp->prev->next = tmp->next;
    if (tmp->next)
        tmp->next->prev = tmp->prev;
    if (tmp == list->head)
        list->head = tmp->next;
    if (tmp == list->tail)
        list->tail = tmp->prev;
    list->size--;
    delete_team(tmp);
}

void remove_team_by_uuid(team_list_t *list, uuid_t uuid)
{
    team_t *tmp;

    if (list == NULL)
        return;
    for (tmp = list->head; tmp; tmp = tmp->next) {
        if (uuid_compare(tmp->uuid, uuid) == 0) {
            remove_team_from_list(list, tmp);
            return;
        }
    }
}

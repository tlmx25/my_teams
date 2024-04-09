/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** add_team
*/

#include "team.h"

void add_team_to_list(team_list_t *list, team_t *team)
{
    if (list->head == NULL) {
        list->head = team;
        list->tail = team;
        team->next = NULL;
        team->prev = NULL;
    } else {
        list->tail->next = team;
        team->prev = list->tail;
        list->tail = team;
        team->next = NULL;
    }
    list->size++;
}

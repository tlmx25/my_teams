/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** remove_thread
*/

#include <stdlib.h>
#include "thread_teams.h"

void remove_thread_from_list(thread_list_t *list, thread_t *thread)
{
    thread_t *tmp;

    if (list == NULL || thread == NULL)
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
    delete_thread(tmp);
}

void remove_thread_by_uuid(thread_list_t *list, uuid_t uuid)
{
    thread_t *tmp;

    if (list == NULL)
        return;
    for (tmp = list->head; tmp; tmp = tmp->next) {
        if (uuid_compare(tmp->uuid, uuid) == 0) {
            remove_thread_from_list(list, tmp);
            return;
        }
    }
}

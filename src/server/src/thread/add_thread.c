/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** add_thread_to_list
*/

#include <stdlib.h>
#include "thread_teams.h"

void add_thread_to_list(thread_list_t *list, thread_t *thread)
{
    if (list == NULL || thread == NULL)
        return;
    if (list->head == NULL) {
        list->head = thread;
        list->tail = thread;
    } else {
        list->tail->next = thread;
        thread->prev = list->tail;
        list->tail = thread;
    }
    list->size++;
}

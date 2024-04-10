/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** delete_thread
*/

#include <stdlib.h>
#include "thread.h"

void delete_thread(thread_t *thread)
{
    if (thread == NULL)
        return;
    if (thread->message)
        free(thread->message);
    if (thread->title)
        free(thread->title);
    free(thread);
}

void clear_thread_list(thread_list_t *list)
{
    thread_t *tmp;
    thread_t *next = NULL;

    if (list == NULL)
        return;
    tmp = list->head;
    while (tmp) {
        next = tmp->next;
        delete_thread(tmp);
        tmp = next;
    }
}

void delete_thread_list(thread_list_t *list)
{
    if (list == NULL)
        return;
    clear_thread_list(list);
    free(list);
}

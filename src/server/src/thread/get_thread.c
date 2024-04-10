/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** get_thread
*/

#include <stdlib.h>
#include "thread.h"
#include "my.h"

thread_t *get_thread_by_uuid(thread_list_t *list, uuid_t uuid)
{
    thread_t *tmp;

    if (list == NULL)
        return NULL;
    for (tmp = list->head; tmp; tmp = tmp->next) {
        if (uuid_compare(tmp->uuid, uuid) == 0)
            return tmp;
    }
    return NULL;
}

thread_t *get_thread_by_title(thread_list_t *list, char const *title)
{
    thread_t *tmp;

    if (list == NULL || title == NULL)
        return NULL;
    for (tmp = list->head; tmp; tmp = tmp->next) {
        if (tmp->title && my_strcmp(tmp->title, title) == 0)
            return tmp;
    }
    return NULL;
}

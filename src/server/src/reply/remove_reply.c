/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** remove_reply
*/

#include <stdlib.h>
#include "reply.h"

void remove_reply_from_list(reply_list_t *list, reply_t *reply)
{
    reply_t *tmp;

    if (list == NULL || reply == NULL)
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
    delete_reply(tmp);
}

void remove_reply_by_uuid(reply_list_t *list, uuid_t uuid)
{
    reply_t *tmp;

    if (list == NULL)
        return;
    for (tmp = list->head; tmp; tmp = tmp->next) {
        if (uuid_compare(tmp->uuid, uuid) == 0) {
            remove_reply_from_list(list, tmp);
            return;
        }
    }
}

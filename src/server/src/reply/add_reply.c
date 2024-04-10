/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** add_reply
*/

#include <stdlib.h>
#include "reply.h"

void add_reply_to_list(reply_list_t *list, reply_t *reply)
{
    if (list == NULL || reply == NULL)
        return;
    if (list->head == NULL) {
        list->head = reply;
        list->tail = reply;
        list->size++;
        return;
    }
    list->tail->next = reply;
    reply->prev = list->tail;
    list->tail = reply;
    list->size++;
}

/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** delete_reply
*/

#include <stdlib.h>
#include "reply.h"

void delete_reply(reply_t *reply)
{
    if (reply == NULL)
        return;
    if (reply->body)
        free(reply->body);
    free(reply);
}

void clear_reply_list(reply_list_t *list)
{
    reply_t *tmp;
    reply_t *next = NULL;

    if (list == NULL)
        return;
    tmp = list->head;
    while (tmp) {
        next = tmp->next;
        delete_reply(tmp);
        tmp = next;
    }
}

void delete_reply_list(reply_list_t *list)
{
    if (list == NULL)
        return;
    clear_reply_list(list);
    free(list);
}

/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** get_reply
*/

#include <stdlib.h>
#include "reply.h"

reply_t *get_reply_by_uuid(reply_list_t *list, uuid_t uuid)
{
    reply_t *tmp;

    if (list == NULL)
        return NULL;
    for (tmp = list->head; tmp; tmp = tmp->next) {
        if (uuid_compare(tmp->uuid, uuid) == 0)
            return tmp;
    }
    return NULL;
}

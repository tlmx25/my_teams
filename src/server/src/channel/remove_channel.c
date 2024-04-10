/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** remove_channel
*/

#include <stdlib.h>
#include "channel.h"

void remove_channel_from_list(channel_list_t *list, channel_t *channel)
{
    channel_t *tmp;

    if (list == NULL || channel == NULL)
        return;
    tmp = list->head;
    for(; tmp; tmp = tmp->next);
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
    delete_channel(tmp);
}

void remove_channel_by_uuid(channel_list_t *list, uuid_t uuid)
{
    channel_t *tmp;

    if (list == NULL)
        return;
    tmp = list->head;
    for (; tmp; tmp = tmp->next) {
        if (uuid_compare(tmp->uuid, uuid) == 0) {
            remove_channel_from_list(list, tmp);
            return;
        }
    }
}

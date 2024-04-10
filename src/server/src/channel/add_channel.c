/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** add_channel
*/

#include <stdlib.h>
#include "channel.h"

void add_channel_to_list(channel_list_t *list, channel_t *channel)
{
    if (list == NULL || channel == NULL)
        return;
    if (list->head == NULL) {
        list->head = channel;
        list->tail = channel;
    } else {
        list->tail->next = channel;
        channel->prev = list->tail;
        list->tail = channel;
    }
    list->size++;
}

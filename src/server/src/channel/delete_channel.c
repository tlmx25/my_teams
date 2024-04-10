/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** delete_channel
*/

#include <stdlib.h>
#include "channel.h"

void delete_channel(channel_t *channel)
{
    if (channel == NULL)
        return;
    if (channel->name)
        free(channel->name);
    if (channel->description)
        free(channel->description);
    free(channel);
}

void clear_channel_list(channel_list_t *list)
{
    channel_t *tmp;
    channel_t *next = NULL;

    if (list == NULL)
        return;
    tmp = list->head;
    while (tmp) {
        next = tmp->next;
        delete_channel(tmp);
        tmp = next;
    }
}

void delete_channel_list(channel_list_t *list)
{
    if (list == NULL)
        return;
    clear_channel_list(list);
    free(list);
}

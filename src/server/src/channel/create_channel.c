/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** create_channel
*/

#include <stdlib.h>
#include "my.h"
#include "channel.h"

channel_t *create_channel(char const *name, char const *description,
    uuid_t team_uuid, uuid_t creator_uuid)
{
    channel_t *new_channel = malloc(sizeof(channel_t));

    if (!new_channel)
        return NULL;
    new_channel->name = my_strdup(name);
    new_channel->description = my_strdup(description);
    uuid_copy(new_channel->team_uuid, team_uuid);
    uuid_copy(new_channel->creator_uuid, creator_uuid);
    new_channel->created_at = time(NULL);
    new_channel->next = NULL;
    new_channel->prev = NULL;
    return new_channel;
}

channel_list_t *create_channel_list(void)
{
    channel_list_t *new_list = malloc(sizeof(channel_list_t));

    if (!new_list)
        return NULL;
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
    return new_list;
}

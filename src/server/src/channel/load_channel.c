/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** load_channel
*/

#include <stdlib.h>
#include <stdio.h>
#include "channel.h"
#include "my.h"

static channel_t *load_channel(channel_save_t save)
{
    channel_t *channel = create_channel(save.name, save.description,
    save.team_uuid, save.creator_uuid);

    if (channel == NULL)
        return NULL;
    channel->created_at = save.created_at;
    uuid_copy(channel->uuid, save.uuid);
    return channel;
}

void load_channel_list(channel_list_t *list)
{
    channel_save_t save;
    channel_t *channel;
    FILE *file = fopen(CHANNEL_FILE, "r+");

    if (file == NULL)
        return;
    while (fread(&save, sizeof(channel_save_t), 1, file) == 1) {
        channel = load_channel(save);
        if (channel)
            add_channel_to_list(list, channel);
    }
    fclose(file);
}

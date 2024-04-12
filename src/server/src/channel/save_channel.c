/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** save_channel
*/

#include <stdlib.h>
#include <stdio.h>
#include "channel.h"
#include "my.h"

static void save_channel(channel_t *channel, FILE *file)
{
    channel_save_t save = {0};

    if (channel == NULL || file == NULL)
        return;
    uuid_copy(save.uuid, channel->uuid);
    uuid_copy(save.team_uuid, channel->team_uuid);
    uuid_copy(save.creator_uuid, channel->creator_uuid);
    save.created_at = channel->created_at;
    my_strncpy(save.name, channel->name, MAX_NAME_LENGTH);
    my_strncpy(save.description, channel->description, MAX_DESCRIPTION_LENGTH);
    fwrite(&save, sizeof(channel_save_t), 1, file);
}

void save_channel_list(channel_list_t *list)
{
    FILE *file;
    channel_t *tmp;

    if (create_directory_if_not_exists(SAVE_DIR) == -1)
        return;
    if (list == NULL)
        return;
    file = fopen(CHANNEL_FILE, "w+");
    if (file == NULL)
        return;
    tmp = list->head;
    while (tmp) {
        save_channel(tmp, file);
        tmp = tmp->next;
    }
    fclose(file);
}

void add_channel_to_save(channel_t *channel)
{
    FILE *file;

    if (create_directory_if_not_exists(SAVE_DIR) == -1)
        return;
    file = fopen(CHANNEL_FILE, "a+");
    if (file == NULL)
        return;
    save_channel(channel, file);
    fclose(file);
}

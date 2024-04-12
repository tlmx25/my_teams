/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** save_reply
*/

#include <stdlib.h>
#include <stdio.h>
#include "reply.h"
#include "my.h"

static void save_reply(reply_t *reply, FILE *file)
{
    reply_save_t save = {0};

    uuid_copy(save.uuid, reply->uuid);
    uuid_copy(save.owner_uuid, reply->owner_uuid);
    uuid_copy(save.thread_uuid, reply->thread_uuid);
    save.timestamp = reply->timestamp;
    my_strncpy(save.body, reply->body, MAX_BODY_LENGTH_REPLY);
    fwrite(&save, sizeof(reply_save_t), 1, file);
}

void save_reply_list(reply_list_t *list)
{
    FILE *file;
    reply_t *tmp;

    if (create_directory_if_not_exists(SAVE_DIR) == -1)
        return;
    if (list == NULL)
        return;
    file = fopen(REPLY_FILE, "w+");
    if (file == NULL)
        return;
    tmp = list->head;
    while (tmp) {
        save_reply(tmp, file);
        tmp = tmp->next;
    }
    fclose(file);
}

void add_reply_to_save(reply_t *reply)
{
    FILE *file;

    if (create_directory_if_not_exists(SAVE_DIR) == -1)
        return;
    file = fopen(REPLY_FILE, "a+");
    if (file == NULL)
        return;
    save_reply(reply, file);
    fclose(file);
}

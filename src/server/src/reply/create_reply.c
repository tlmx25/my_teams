/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** create_reply
*/

#include <stdlib.h>
#include "reply.h"
#include "my.h"

reply_t *create_reply(char *body, uuid_t author_uuid, uuid_t thread_uuid)
{
    reply_t *reply = calloc(sizeof(reply_t), 1);

    if (reply == NULL)
        return NULL;
    uuid_generate(reply->uuid);
    uuid_copy(reply->thread_uuid, thread_uuid);
    uuid_copy(reply->owner_uuid, author_uuid);
    reply->body = my_strdup(body);
    reply->timestamp = time(NULL);
    return reply;
}

reply_list_t *create_reply_list(void)
{
    reply_list_t *list = calloc(sizeof(reply_list_t), 1);

    if (list == NULL)
        return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

reply_t *create_reply_from_save(reply_save_t save)
{
    reply_t *reply = calloc(sizeof(reply_t), 1);

    if (reply == NULL)
        return NULL;
    uuid_copy(reply->uuid, save.uuid);
    uuid_copy(reply->owner_uuid, save.owner_uuid);
    uuid_copy(reply->thread_uuid, save.thread_uuid);
    reply->timestamp = save.timestamp;
    reply->body = my_strdup(save.body);
    return reply;
}

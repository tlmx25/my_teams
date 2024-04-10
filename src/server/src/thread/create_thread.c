/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** create_thread
*/

#include <stdlib.h>
#include "thread_teams.h"
#include "my.h"

thread_t *create_thread(char const *title, char const *message,
    uuid_t creator_uuid, uuid_t channel_uuid)
{
    thread_t *thread = calloc(sizeof(thread_t), 1);

    if (thread == NULL)
        return NULL;
    uuid_generate(thread->uuid);
    uuid_copy(thread->creator_uuid, creator_uuid);
    uuid_copy(thread->channel_uuid, channel_uuid);
    if (title != NULL)
        my_strncpy(thread->title, title, 255);
    if (message != NULL)
        my_strncpy(thread->message, message, 4095);
    return thread;
}

thread_list_t *create_thread_list(void)
{
    thread_list_t *list = calloc(sizeof(thread_list_t), 1);

    if (list == NULL)
        return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

thread_t *create_thread_from_save(thread_save_t save)
{
    thread_t *thread = create_thread(save.title, save.message,
        save.creator_uuid, save.channel_uuid);

    if (thread == NULL)
        return NULL;
    uuid_copy(thread->uuid, save.uuid);
    thread->created_at = save.created_at;
    return thread;
}

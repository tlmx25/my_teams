/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** save_thread
*/

#include <stdlib.h>
#include <stdio.h>
#include "thread.h"
#include "my.h"

static void save_thread(thread_t *thread, FILE *file)
{
    thread_save_t save;

    if (thread == NULL || file == NULL)
        return;
    uuid_copy(save.uuid, thread->uuid);
    my_strncpy(save.title, thread->title, MAX_NAME_LENGTH);
    my_strncpy(save.message, thread->message, MAX_DESCRIPTION_LENGTH);
    uuid_copy(save.creator_uuid, thread->creator_uuid);
    uuid_copy(save.channel_uuid, thread->channel_uuid);
    save.created_at = thread->created_at;
    fwrite(&save, sizeof(thread_save_t), 1, file);
}

void save_threads_list(thread_list_t *list)
{
    FILE *file;

    if (create_directory_if_not_exists(SAVE_DIR) == -1)
        return;
    file = fopen(THREAD_SAVE_FILE, "w+");
    if (file == NULL)
        return;
    for (thread_t *tmp = list->head; tmp; tmp = tmp->next)
        save_thread(tmp, file);
    fclose(file);
}

void add_thread_to_save(thread_t *thread)
{
    FILE *file;

    if (create_directory_if_not_exists(SAVE_DIR) == -1)
        return;
    file = fopen(THREAD_SAVE_FILE, "a+");
    if (file == NULL)
        return;
    save_thread(thread, file);
    fclose(file);
}

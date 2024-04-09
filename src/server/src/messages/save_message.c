/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** save_message
*/

#include "my.h"
#include "messages.h"
#include "client.h"

void save_message(message_t *message, FILE *file)
{
    message_save_t save = {0};

    uuid_copy(save.sender_uuid, message->sender_uuid);
    uuid_copy(save.receiver_uuid, message->receiver_uuid);
    my_strncpy(save.message, message->message, MAX_BODY_LENGTH);
    fwrite(&save, sizeof(message_save_t), 1, file);
}

void save_message_list(message_list_t *list)
{
    message_t *tmp = list->head;
    FILE *file;

    if (create_directory_if_not_exists(SAVE_DIR) == -1)
        return;
    file = fopen(MESSAGE_FILE, "w+");
    if (file == NULL)
        return;
    for (; tmp; tmp = tmp->next) {
        save_message(tmp, file);
    }
    fclose(file);
}

void append_message_to_save(message_t *message)
{
    FILE *file;

    if (create_directory_if_not_exists(SAVE_DIR) == -1)
        return;
    file = fopen("messages.txt", "a+");
    if (file == NULL)
        return;
    save_message(message, file);
    fclose(file);
}

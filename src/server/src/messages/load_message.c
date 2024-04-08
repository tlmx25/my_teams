/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** load_message
*/

#include <stdio.h>
#include "messages.h"

void load_message(message_list_t *list, message_save_t save)
{
    message_t *new_message = create_message_from_save(save);

    if (new_message == NULL)
        return;
    add_message(list, new_message);
}

void load_messages_to_list(message_list_t *list)
{
    FILE *file = fopen(MESSAGE_FILE, "r");
    message_save_t save;
    char sender_uuid[37] = {0};
    char receiver_uuid[37] = {0};

    if (file == NULL)
        return;
    while (fread(&save, sizeof(message_save_t), 1, file) == 1) {
        uuid_unparse(save.sender_uuid, sender_uuid);
        uuid_unparse(save.receiver_uuid, receiver_uuid);
        load_message(list, save);
    }
    fclose(file);
}

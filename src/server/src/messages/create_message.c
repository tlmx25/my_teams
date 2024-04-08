/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** create_message
*/

#include "my.h"
#include <string.h>
#include <stdlib.h>
#include "messages.h"

message_t *create_message(char *sender_uuid, char *receiver_uuid,
    char *message)
{
    message_t *new_message = calloc(sizeof(message_t), 1);

    if (new_message == NULL)
        return NULL;
    uuid_parse(sender_uuid, new_message->sender_uuid);
    uuid_parse(receiver_uuid, new_message->receiver_uuid);
    memset(new_message->message, 0, MAX_BODY_LENGTH + 1);
    my_strncpy(new_message->message, message, MAX_BODY_LENGTH);
    new_message->next = NULL;
    new_message->prev = NULL;
    return new_message;
}

message_t *create_message_from_save(message_save_t save)
{
    message_t *new_message = calloc(sizeof(message_t), 1);

    if (new_message == NULL)
        return NULL;
    uuid_copy(new_message->sender_uuid, save.sender_uuid);
    uuid_copy(new_message->receiver_uuid, save.receiver_uuid);
    memset(new_message->message, 0, MAX_BODY_LENGTH + 1);
    my_strncpy(new_message->message, save.message, MAX_BODY_LENGTH);
    new_message->next = NULL;
    new_message->prev = NULL;
    return new_message;
}

message_list_t *create_message_list(void)
{
    message_list_t *list = calloc(sizeof(message_list_t), 1);

    if (list == NULL)
        return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

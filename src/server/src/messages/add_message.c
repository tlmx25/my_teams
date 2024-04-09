/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** add_message
*/

#include "messages.h"

void add_message(message_list_t *list, message_t *message)
{
    if (list->head == NULL) {
        list->head = message;
        list->tail = message;
    } else {
        list->tail->next = message;
        message->prev = list->tail;
        list->tail = message;
    }
    list->size++;
}

void create_add_message(message_list_t *list, char *sender_uuid,
    char *receiver_uuid, char *message)
{
    message_t *new_message;

    new_message = create_message(sender_uuid, receiver_uuid, message);
    if (new_message == NULL)
        return;
    add_message(list, new_message);
}

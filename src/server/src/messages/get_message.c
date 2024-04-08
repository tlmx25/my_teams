/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** get_message
*/

#include "messages.h"

message_t *get_message(message_list_t *list, uuid_t uuid_sender, uuid_t uuid_receiver)
{
    message_t *tmp = list->head;

    for (; tmp && (uuid_compare(tmp->sender_uuid, uuid_sender) != 0
    && uuid_compare(tmp->receiver_uuid, uuid_receiver) != 0); tmp = tmp->next);
    return tmp;
}

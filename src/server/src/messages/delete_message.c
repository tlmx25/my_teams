/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** delete_message
*/

#include <stdlib.h>
#include "messages.h"

void clear_message_list(message_list_t *list)
{
    message_t *tmp = list->head;
    message_t *next = NULL;

    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void delete_message_list(message_list_t *list)
{
    if (list == NULL)
        return;
    clear_message_list(list);
    free(list);
}

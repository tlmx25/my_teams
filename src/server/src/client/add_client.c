/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** add_client
*/

#include <stdio.h>
#include "client.h"

void add_client_to_list(client_list_t *list, client_t *client)
{
    if (list->head == NULL) {
        list->head = client;
        list->tail = client;
        client->next = NULL;
        client->prev = NULL;
    } else {
        list->tail->next = client;
        client->prev = list->tail;
        list->tail = client;
        client->next = NULL;
    }
}

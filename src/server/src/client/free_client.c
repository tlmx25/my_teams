/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** free_client
*/

#include <stdlib.h>
#include <stdio.h>
#include "client.h"

void free_client(client_t *client)
{
    if (client == NULL)
        return;
    if (client->username)
        free(client->username);
    if (client->password)
        free(client->password);
    free_request_list(client->requests_received);
    free_request_list(client->requests_sent);
    free(client);
}

void clear_client_list(client_list_t *list)
{
    client_t *tmp;
    client_t *next = NULL;

    if (list == NULL)
        return;
    tmp = list->head;
    for (; tmp; tmp = next) {
        next = tmp->next;
        free_client(tmp);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void delete_client_list(client_list_t *list)
{
    clear_client_list(list);
    free(list);
}

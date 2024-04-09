/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** remove_client
*/

#include <stdio.h>
#include "client.h"

void remove_client_from_list(client_list_t *list, client_t *client)
{
    if (client->prev)
        client->prev->next = client->next;
    if (client->next)
        client->next->prev = client->prev;
    if (list->head == client)
        list->head = client->next;
    if (list->tail == client)
        list->tail = client->prev;
    free_client(client);
    list->size--;
}

void remove_client_by_fd(client_list_t *list, int fd)
{
    client_t *tmp = list->head;

    for (; tmp && tmp->fd != fd; tmp = tmp->next);
    if (tmp)
        remove_client_from_list(list, tmp);
}

void remove_client_by_uuid(client_list_t *list, uuid_t uuid)
{
    client_t *tmp = list->head;

    for (; tmp && uuid_compare(tmp->uuid, uuid) != 0; tmp = tmp->next);
    if (tmp)
        remove_client_from_list(list, tmp);
}

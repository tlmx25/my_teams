/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** create_client
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "client.h"

client_t *create_client(int fd, char *username, char *password, char *uuid)
{
    client_t *client = malloc(sizeof(client_t));

    if (client == NULL)
        return NULL;
    client->fd = fd;
    if (uuid)
        uuid_parse(uuid, client->uuid);
    else
        uuid_generate(client->uuid);
    client->username = my_strdup(username);
    client->password = my_strdup(password);
    client->is_connected = (fd > 0) ? true : false;
    client->requests_received = create_request_list();
    client->requests_sent = create_request_list();
    client->next = NULL;
    client->prev = NULL;
    return client;
}

client_list_t *create_client_list(void)
{
    client_list_t *list = malloc(sizeof(client_list_t));

    if (list == NULL)
        return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

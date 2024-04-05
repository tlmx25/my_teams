/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** command_manager
*/

#include <stdio.h>
#include "server.h"

void manage_request(UNUSED server_t *server, client_t *client)
{
    if (client->requests_received->head == NULL || !client->is_connected)
        return;
    printf("Request received: %s\n", client->requests_received->head->request->body);
    remove_request_from_list(client->requests_received, client->requests_received->head->request->uuid);
    add_request_to_list(client->requests_sent, create_request(10, 200, "OK"));
}

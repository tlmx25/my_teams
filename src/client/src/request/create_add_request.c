/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** send_to_server
*/

#include <stdlib.h>
#include "client_cli.h"

void create_add_request(client_t *client, char *msg)
{
    request_t *request;

    if (client == NULL)
        return;
    request = create_request(0, 200, msg);
    if (request == NULL)
        return;
    add_request_to_list(client->requests_to_send, request);
}

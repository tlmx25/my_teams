/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** free_client
*/

#include <stdlib.h>
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

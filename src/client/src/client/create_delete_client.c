/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** create_delete_client
*/

#include <stdio.h>
#include <stdlib.h>
#include "request.h"
#include "client_cli.h"

client_t *create_client(char *ip, int port)
{
    client_t *client = malloc(sizeof(client_t));

    if (client == NULL)
        return NULL;
    client->config_select = init_select();
    if (client->config_select == NULL) {
        free(client);
        return NULL;
    }
    client->ip = ip;
    client->port = port;
    client->fd_server = -1;
    client->is_running = true;
    client->requests_to_send = create_request_list();
    if (client->requests_to_send == NULL) {
        free(client);
        return NULL;
    }
    return client;
}

void delete_client(client_t *client)
{
    if (client == NULL)
        return;
    if (client->ip)
        free(client->ip);
    if (client->config_select)
        free(client->config_select);
    if (client->fd_server > 0)
        close(client->fd_server);
    if (client->requests_to_send)
        free_request_list(client->requests_to_send);
    free(client);
}

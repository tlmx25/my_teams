/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** create_server
*/

#include <stdlib.h>
#include "server.h"


server_t *create_server(int port)
{
    server_t *server = calloc(sizeof(server_t), 1);

    if (server == NULL)
        return NULL;
    server->is_running = true;
    server->port = port;
    server->socket = create_socket(port);
    if (server->socket == -1) {
        free(server);
        return NULL;
    }
    server->select_config = init_select();
    server->clients = create_client_list();
    return server;
}

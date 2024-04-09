/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** create_server
*/

#include <stdlib.h>
#include "server.h"

static server_t *create_server_2(server_t *server)
{
    server->clients_loaded = create_client_list();
    server->clients = create_client_list();
    server->messages = create_message_list();
    if (server->clients == NULL || server->clients_loaded == NULL
        || server->messages == NULL) {
        delete_server(server);
        return NULL;
    }
    load_client_list(server->clients_loaded);
    load_messages_to_list(server->messages);
    return server;
}

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
    if (server->select_config == NULL) {
        delete_server(server);
        return NULL;
    }
    server->select_config->max_fd = server->socket;
    return create_server_2(server);
}

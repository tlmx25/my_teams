/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** create_server
*/

#include <stdlib.h>
#include "server.h"

static server_t *create_server_3(server_t *server)
{
    load_channel_list(server->channels);
    load_client_list(server->clients_loaded);
    load_messages_to_list(server->messages);
    load_team_list(server->teams);
    load_link_list(server->link_team_user);
    return server;
}

static server_t *create_server_2(server_t *server)
{
    server->clients_loaded = create_client_list();
    server->clients = create_client_list();
    server->messages = create_message_list();
    server->teams = create_team_list();
    server->link_team_user = create_link_list();
    server->channels = create_channel_list();
    if (!server->clients || !server->clients_loaded
        || !server->link_team_user || !server->channels
        || !server->messages || !server->teams) {
        delete_server(server);
        return NULL;
    }
    return create_server_3(server);
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

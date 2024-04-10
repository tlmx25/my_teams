/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** delete_server
*/

#include <stdlib.h>
#include "server.h"

void delete_server(server_t *server)
{
    if (server == NULL)
        return;
    close(server->socket);
    delete_client_list(server->clients);
    delete_client_list(server->clients_loaded);
    delete_message_list(server->messages);
    delete_team_list(server->teams);
    delete_link_list(server->link_team_user);
    delete_channel_list(server->channels);
    delete_thread_list(server->threads);
    delete_reply_list(server->replies);
    free(server->select_config);
    free(server);
}

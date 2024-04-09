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
    free(server->select_config);
    free(server);
}

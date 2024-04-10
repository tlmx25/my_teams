/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** server
*/

#include "server.h"

static void set_fds(server_t *server)
{
    reset_select(server->select_config);
    add_to_select(server->select_config, server->socket);
    add_to_select(server->select_config, STDIN_FILENO);
    for (client_t *tmp = server->clients->head; tmp; tmp = tmp->next) {
        add_to_select(server->select_config, tmp->fd);
    }
}

int run_server(server_t *server)
{
    while (server->is_running) {
        set_fds(server);
        if (exec_select(server->select_config) == ERROR)
            return 84;
        manage_server(server);
    }
    return 0;
}

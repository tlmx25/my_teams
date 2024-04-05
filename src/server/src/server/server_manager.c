/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** server_manager
*/

#include <stdio.h>
#include "server.h"
#include "my.h"

static void check_read_client(server_t *server, client_t *client)
{
    request_t *req = NULL;

    if (!FD_ISSET(client->fd, &server->select_config->readfds))
        return;
    req = read_socket(client->fd);
    if (req == NULL) {
        remove_client_from_list(server->clients, client);
        return;
    }
    add_request_to_list(client->requests_received, req);
}

static void check_write_client(server_t *server, client_t *client)
{
    linked_request_t *req = client->requests_sent->head;
    linked_request_t *next;

    if (!FD_ISSET(client->fd, &server->select_config->writefds))
        return;
    for (; req; req = next) {
        next = req->next;
        if (write_socket(client->fd, req->request) == ERROR)
            return;
        remove_request_from_list(client->requests_sent, req->request->uuid);
    }
}

static void read_stdin(server_t *server)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (!FD_ISSET(STDIN_FILENO, &server->select_config->readfds))
        return;
    read = getline(&line, &len, stdin);
    if (read == -1)
        return;
    if (my_strcmp(line, "stop\n") == 0)
        server->is_running = false;
}

void manage_server(server_t *server)
{
    client_t *client = server->clients->head;
    client_t *next = NULL;

    read_stdin(server);
    for (; client; client = next) {
        next = client->next;
        check_read_client(server, client);
        check_write_client(server, client);
    }
}

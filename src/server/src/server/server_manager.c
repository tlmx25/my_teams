/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** server_manager
*/

#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include "server.h"
#include "logging_server.h"
#include "my.h"

static void check_read_client(server_t *server, client_t *client)
{
    request_t *req = NULL;
    char uuid_str[37] = {0};

    if (!FD_ISSET(client->fd, &server->select_config->readfds))
        return;
    req = read_socket(client->fd);
    if (req == NULL) {
        uuid_unparse(client->uuid, uuid_str);
        if (client->username)
            server_event_user_logged_out(uuid_str);
        client->is_connected = false;
        return;
    }
    add_request_to_list(client->requests_received, req);
}

static void check_write_client(server_t *server, client_t *client)
{
    linked_request_t *req = client->requests_sent->head;
    linked_request_t *next;

    if (!FD_ISSET(client->fd, &server->select_config->writefds) &&
    !client->is_connected)
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
    free(line);
}

static void accept_new_client(server_t *server)
{
    int new_socket = 0;
    struct sockaddr_in *address;
    int addrlen = sizeof(struct sockaddr);
    client_t *new_client = NULL;

    if (!FD_ISSET(server->socket, &server->select_config->readfds))
        return;
    address = calloc(sizeof(struct sockaddr_in), 1);
    if (address == NULL)
        return;
    new_socket = accept(server->socket, (struct sockaddr *)address,
        (socklen_t *)&addrlen);
    if (new_socket == -1)
        return free(address);
    server->select_config->max_fd = (server->select_config->max_fd <
        new_socket) ? new_socket : server->select_config->max_fd;
    new_client = create_client(new_socket, NULL, NULL, NULL);
    add_client_to_list(server->clients, new_client);
    free(address);
}

void manage_server(server_t *server)
{
    client_t *client = server->clients->head;
    client_t *next = NULL;

    read_stdin(server);
    accept_new_client(server);
    for (; client; client = next) {
        next = client->next;
        check_read_client(server, client);
        check_write_client(server, client);
        manage_request(server, client);
        if (!client->is_connected) {
            remove_client_from_list(server->clients, client);
        }
    }
}

/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** client
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "client_cli.h"
#include "socket.h"
#include "my.h"

static int command_error_handling(char **command)
{
    for (int i = 1; command[i]; i++) {
        if (command[i][0] != '"' ||
            command[i][strlen(command[i]) - 2] != '"') {
            return 1;
        }
    }
    return 0;
}

static void process_command(client_t *client, char *line)
{
    char **command = my_str_to_word_array(line, " \t");
    int check_error = 0;

    if (command == NULL)
        return;
    if (my_arrsize((char const **)command) > 1)
        check_error = command_error_handling(command);
    if (check_error == 1) {
        printf("Error: Command must be between quotes\n");
        free_tab(command);
        return;
    }
    line = my_array_to_str_separator((char const **)command, "\r");
    create_add_request_to_list(client->requests_to_send, NONE, 200, line);
    free_tab(command);
    free(line);
}

static void read_stdin(client_t *client)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (!FD_ISSET(STDIN_FILENO, &client->config_select->readfds))
        return;
    read = getline(&line, &len, stdin);
    if (read == -1)
        return;
    if (my_strcmp(line, "/stop\n") == 0)
        client->is_running = false;
    process_command(client, line);
}

static void read_server_response(client_t *client)
{
    request_t *req;

    if (!FD_ISSET(client->fd_server, &client->config_select->readfds))
        return;
    req = read_socket(client->fd_server);
    if (req == NULL) {
        client->is_running = false;
        return;
    }
    command_manager(client, req);
    free(req);
}

static void set_fd(client_t *client)
{
    reset_select(client->config_select);
    add_to_select(client->config_select, STDIN_FILENO);
    add_to_select(client->config_select, client->fd_server);
}

static void write_to_server(client_t *client)
{
    linked_request_t *req = client->requests_to_send->head;
    linked_request_t *next;

    if (!FD_ISSET(client->fd_server, &client->config_select->writefds))
        return;
    for (; req; req = next) {
        next = req->next;
        if (write_socket(client->fd_server, req->request) == ERROR)
            return;
        remove_request_from_list(client->requests_to_send, req->request->uuid);
    }
}

int run_client(client_t *client)
{
    if (connect_to_server(client) == ERROR)
        return ERROR;
    client->config_select->max_fd = client->fd_server;
    while (client->is_running) {
        set_fd(client);
        if (exec_select(client->config_select) == ERROR)
            return ERROR;
        read_stdin(client);
        read_server_response(client);
        write_to_server(client);
    }
    return 0;
}

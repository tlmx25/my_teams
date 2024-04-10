/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** login_command
*/

#include "logging_server.h"
#include <stdlib.h>
#include "server.h"
#include "my.h"

void send_error_response(client_t *client, char *message)
{
    request_t *request = create_request(PRINT_ERROR, 401, message);

    if (request == NULL)
        return;
    add_request_to_list(client->requests_sent, request);
}

static void request_logged_in(server_t *server, client_t *client)
{
    request_t *request = create_request(LOGGED_IN, 200, NULL);
    char *body;
    char uuid_str[37] = {0};

    if (request == NULL)
        return;
    body = my_strcat(client->username, "\r");
    uuid_unparse(client->uuid, uuid_str);
    body = my_strcat_free(body, uuid_str, 1, 0);
    my_strncpy(request->body, body, 4095);
    free(body);
    send_notification_all(server->clients, request);
    free(request);
}

static void user_exist(server_t *server, client_t *client,
    client_t *log_client)
{
    char uuid_str[37] = {0};

    client->username = my_strdup(log_client->username);
    client->password = my_strdup(log_client->password);
    uuid_copy(client->uuid, log_client->uuid);
    client->is_connected = true;
    request_logged_in(server, client);
    uuid_unparse(client->uuid, uuid_str);
    server_event_user_logged_in(uuid_str);
}

static void user_not_exist(server_t *server, client_t *client, char *username)
{
    client_t *dup_client;
    char uuid_str[37] = {0};

    client->username = my_strdup(username);
    uuid_generate(client->uuid);
    dup_client = duplicate_client(client);
    dup_client->fd = -1;
    add_client_to_list(server->clients_loaded, dup_client);
    add_client_to_save(dup_client);
    request_logged_in(server, client);
    uuid_unparse(client->uuid, uuid_str);
    server_event_user_created(uuid_str, client->username);
    server_event_user_logged_in(uuid_str);
}

void login_command(UNUSED server_t *server, client_t *client,
    UNUSED char **command)
{
    client_t *log_client;

    if (client->username != NULL) {
        send_error_response(client, "You are already logged in");
        return;
    }
    log_client = get_client_by_name(server->clients_loaded, command[1]);
    if (log_client == NULL) {
        user_not_exist(server, client, command[1]);
    } else
        user_exist(server, client, log_client);
}

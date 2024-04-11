/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** user_command
*/

#include "logging_server.h"
#include <stdlib.h>
#include "server.h"
#include "my.h"

static void print_user(client_t *client, client_t *to_sent,
    client_list_t *connected)
{
    char uuid_str[37] = {0};
    char status_str[12];
    char *body;
    int connect = (get_client_by_uuid(connected, client->uuid)) ? 1 : 0;
    request_t *request = create_request(NT_PRINT_USER, 200, NULL);

    uuid_unparse(client->uuid, uuid_str);
    body = my_strcat(uuid_str, "\r");
    body = my_strcat_free(body, client->username, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    sprintf(status_str, "%d", connect);
    body = my_strcat_free(body, status_str, 1, 0);
    my_strncpy(request->body, body, MAX_BODY_LENGTH);
    free(body);
    add_request_to_list(to_sent->requests_sent, request);
}

void user_command(UNUSED server_t *server, client_t *client,
    UNUSED char **command)
{
    client_t *current = server->clients_loaded->head;
    char uuid_str[37] = {0};

    if (client->is_connected == false) {
        add_request_to_list(client->requests_sent,
            create_request(PRINT_ERROR, 200, "You are not logged in"));
        return;
    }
    while (current) {
        uuid_unparse(current->uuid, uuid_str);
        if (my_strcmp(uuid_str, command[1]) == 0) {
            print_user(current, client, server->clients);
            return;
        }
        current = current->next;
    }
    add_request_to_list(client->requests_sent,
        create_request(PRINT_ERROR, 200, "User not found"));
}
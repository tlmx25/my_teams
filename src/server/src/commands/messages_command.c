/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** messages_command
*/

#include "logging_server.h"
#include <stdlib.h>
#include "server.h"
#include "my.h"

static void print_messages(client_t *current_client, client_t *client, char *uuid)
{
    request_t *request = create_request(PRINT_PRV_MSG, 200, NULL);
    char *body = NULL;

    body = my_strcat(uuid, "\r");
}

void messages_command(UNUSED server_t *server, client_t *client,
    UNUSED char **command)
{
    client_t *current_client = server->clients_loaded->head;
    char uuid_str[37] = {0};

    if (client->is_connected == false) {
        add_request_to_list(client->requests_sent,
            create_request(PRINT_ERROR, 200, "You are not logged in"));
        return;
    }
    while (current_client) {
        uuid_unparse(current_client->uuid, uuid_str);
        if (my_strcmp(uuid_str, command[1]) == 0) {
            print_messages(current_client, client, uuid_str);
            return;
        }
        current_client = current_client->next;
    }
    add_request_to_list(client->requests_sent,
        create_request(PRINT_ERROR, 200, "User not found"));
}

/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** logout_command
*/

#include "logging_server.h"
#include <stdlib.h>
#include "server.h"
#include "my.h"

void logout_command(UNUSED server_t *server, client_t *client,
    UNUSED char **command)
{
    request_t *request;
    char uuid_str[37] = {0};
    char *body;

    if (client->is_connected == false) {
        request = create_request(PRINT_ERROR, 200, "You are not logged in");
        if (request == NULL)
            return;
        add_request_to_list(client->requests_sent, request);
        return;
    }
    uuid_unparse(client->uuid, uuid_str);
    body = my_strcat(uuid_str, "\r");
    body = my_strcat_free(body, client->username, 1, 0);
    request = create_request(LOGGED_OUT, 200, body);
    free(body);
     add_request_to_list(client->requests_sent, request);
    if (request == NULL)
        return;
}

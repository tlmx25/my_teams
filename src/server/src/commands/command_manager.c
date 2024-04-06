/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** command_manager
*/

#include "stdlib.h"
#include <stdio.h>
#include "my.h"
#include "server.h"

void manage_request(UNUSED server_t *server, client_t *client)
{
    if (client->requests_received->head == NULL || !client->is_connected)
        return;
    printf("Request received: %s\n", client->requests_received->head->request->body);
    remove_request_from_list(client->requests_received, client->requests_received->head->request->uuid);
    uuid_t tmp;
    uuid_generate(tmp);
    char *str_uuid = calloc(37, sizeof(char));
    uuid_unparse(tmp, str_uuid);
    char *body = my_strcat(str_uuid, "\rUsername");
    printf("Body to send: %s\n", body);
    add_request_to_list(client->requests_sent, create_request(LOGGED_IN, 200, body));
}

/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** messages_command
*/

#include "logging_server.h"
#include <stdlib.h>
#include "server.h"
#include "time_utils.h"
#include "my.h"

static void send_request(client_t *client, message_t *msg, char *uuid_str)
{
    char *body = my_strcat(uuid_str, "\r");

    body = my_strcat_free(body, timestamp_to_str(msg->timestamp), 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, msg->message, 1, 0);
    add_request_to_list(client->requests_sent,
        create_request(PRINT_PRV_MSG, 200, body));
}

static void print_messages(client_t *current_client, client_t *client,
    server_t *server)
{
    message_t *current_message = server->messages->head;
    char uuid_str_sender[37] = {0};
    char uuid_str_receiver[37] = {0};
    char uuid_str_client[37] = {0};
    char uuid_str_current_client[37] = {0};

    uuid_unparse(client->uuid, uuid_str_client);
    uuid_unparse(current_client->uuid, uuid_str_current_client);
    while (current_message) {
        uuid_unparse(current_message->sender_uuid, uuid_str_sender);
        uuid_unparse(current_message->receiver_uuid, uuid_str_receiver);
        if (my_strcmp(uuid_str_receiver, uuid_str_current_client) == 0
            && my_strcmp(uuid_str_sender, uuid_str_client) == 0)
            send_request(client, current_message, uuid_str_sender);
        if (my_strcmp(uuid_str_receiver, uuid_str_client) == 0
            && my_strcmp(uuid_str_sender, uuid_str_current_client) == 0)
            send_request(client, current_message, uuid_str_receiver);
        current_message = current_message->next;
    }
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
            print_messages(current_client, client, server);
            return;
        }
        current_client = current_client->next;
    }
    add_request_to_list(client->requests_sent,
        create_request(PRINT_ERROR, 200, "User not found"));
}

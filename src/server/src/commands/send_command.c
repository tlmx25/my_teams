/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** send_command
*/

#include "logging_server.h"
#include <stdlib.h>
#include "server.h"
#include "my.h"

static void save_message_command(client_t *client, client_t *to_send,
    char *message, server_t *server)
{
    message_t *message_to_save;
    char uuid_str_sender[37] = {0};
    char uuid_str_receiver[37] = {0};
    char *tmp;
    client_t *tmp_client = get_client_by_uuid(server->clients, to_send->uuid);

    uuid_unparse(client->uuid, uuid_str_sender);
    uuid_unparse(to_send->uuid, uuid_str_receiver);
    message_to_save = create_message(uuid_str_sender, uuid_str_receiver,
        message);
    add_message(server->messages, message_to_save);
    append_message_to_save(message_to_save);
    if (tmp_client == NULL)
        return;
    tmp = my_strcat(uuid_str_sender, "\r");
    tmp = my_strcat_free(tmp, message, 1, 0);
    create_add_request_to_list(tmp_client->requests_sent, MSG_PRV_RCVD, 200,
        tmp);
    free(tmp);
}

static void send_message(client_t *client, client_t *to_send, char *message,
    server_t *server)
{
    request_t *request;
    char uuid_str_sender[37] = {0};
    char uuid_str_receiver[37] = {0};
    char *body;

    body = my_strcat(client->username, ": ");
    body = my_strcat_free(body, message, 1, 0);
    request = create_request(MSG_PRV_RCVD, 200, body);
    free(body);
    add_request_to_list(to_send->requests_sent, request);
    uuid_unparse(client->uuid, uuid_str_sender);
    uuid_unparse(to_send->uuid, uuid_str_receiver);
    server_event_private_message_sended(uuid_str_sender,
        uuid_str_receiver, message);
    save_message_command(client, to_send, message, server);
}

void send_command(UNUSED server_t *server, client_t *client,
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
            send_message(client, current, command[2], server);
            return;
        }
        current = current->next;
    }
    add_request_to_list(client->requests_sent,
        create_request(PRINT_ERROR, 200, "User not found"));
}

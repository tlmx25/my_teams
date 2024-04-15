/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** create_channel_command
*/

#include <stdlib.h>
#include "server.h"
#include "my.h"
#include "logging_server.h"

static void notif_channel_created(server_t *server, client_t *client,
    channel_t *channel)
{
    request_t *request;
    char *body;
    char uuid_channel_str[37] = {0};
    char uuid_team_str[37] = {0};

    uuid_unparse(channel->uuid, uuid_channel_str);
    body = my_strcat(uuid_channel_str, "\r");
    body = my_strcat_free(body, channel->name, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, channel->description, 1, 0);
    request = create_request(NT_CHANNEL_CREATED, 201, body);
    send_notification_subscribed(server, request, client, channel->team_uuid);
    request->action = CHANNEL_CREATED;
    add_request_to_list(client->requests_sent, request);
    uuid_unparse(channel->team_uuid, uuid_team_str);
    server_event_channel_created(uuid_team_str, uuid_channel_str,
    channel->name);
    free(body);
    add_channel_to_save(channel);
}

void create_channel_command(server_t *server, client_t *client, char **command)
{
    channel_t *channel;

    if (my_arrsize((char const **) command) != 3)
        return create_add_request_to_list(client->requests_sent, PRINT_ERROR,
        400, "Invalid number of  arguments (2 required)");
    if (!check_team_exist(server, client->context->uuid_team, client))
        return;
    channel = create_channel(command[1], command[2],
    client->context->uuid_team, client->uuid);
    if (channel == NULL)
        return create_add_request_to_list(client->requests_sent, PRINT_ERROR,
        400, "Failed to create channel");
    add_channel_to_list(server->channels, channel);
    notif_channel_created(server, client, channel);
    delete_context(client->context);
    client->context = NULL;
}

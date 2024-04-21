/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** list_channel_command.c
*/

#include <stdlib.h>
#include "server.h"
#include "command_server.h"
#include "time_utils.h"
#include "request.h"
#include "my.h"

static void send_channel_display_list(client_t *client, channel_t *channel)
{
    char *body;
    char uuid_str[37] = {0};

    uuid_unparse(channel->uuid, uuid_str);
    body = my_strcat(uuid_str, "\r");
    body = my_strcat_free(body, channel->name, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, channel->description, 1, 0);
    create_add_request_to_list(client->requests_sent, NT_PRINT_CHANNEL, 200,
        body);
    free(body);
}

static channel_t *check_channel_display_list(client_t *client, channel_t
    *channel, bool_t *verif)
{
    if (uuid_compare(channel->team_uuid, client->context->uuid_team) != 0)
        return channel->next;
    *verif = true;
    send_channel_display_list(client, channel);
    return channel->next;
}

void channel_display_list(server_t *server, client_t *client)
{
    channel_t *channel;
    bool_t verif = false;

    if (!check_subscribed(server, client))
        return;
    if (server->channels->head == NULL)
        return create_add_request_to_list(client->requests_sent, PRINT_ERROR,
            404, "No channel found");
    channel = server->channels->head;
    while (channel) {
        channel = check_channel_display_list(client, channel, &verif);
        if (channel == NULL)
            break;
    }
    if (verif == false) {
        create_add_request_to_list(client->requests_sent, PRINT_ERROR,
            404, "No channel found");
    }
}

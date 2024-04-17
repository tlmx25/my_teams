/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** info_command.c
*/

#include <stdlib.h>
#include "server.h"
#include "command_server.h"
#include "time_utils.h"
#include "request.h"
#include "my.h"

void send_thread_display_info(char *body, client_t *client, thread_t *thread)
{
    char *time_str = timestamp_to_str(thread->created_at);

    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, time_str, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, thread->title, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, thread->message, 1, 0);
    create_add_request_to_list(client->requests_sent, NT_PRINT_THREAD, 200,
        body);
    free(body);
    free(time_str);
}

static void user_display_info(client_t *client)
{
    char uuid_str[37] = {0};
    char *body;

    uuid_unparse(client->uuid, uuid_str);
    body = my_strcat(uuid_str, "\r");
    body = my_strcat_free(body, client->username, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, client->username ? "1" : "0", 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    my_strncpy(body, body, MAX_BODY_LENGTH);
    create_add_request_to_list(client->requests_sent, NT_PRINT_USER, 200,
        body);
    free(body);
}

static void team_display_info(server_t *server, client_t *client)
{
    char uuid_str[37] = {0};
    char *body;
    team_t *team;

    if (!check_team_exist(server, client->context->uuid_team, client))
        return;
    team = get_team_by_uuid(server->teams, client->context->uuid_team);
    if (team == NULL)
        return;
    uuid_unparse(team->uuid, uuid_str);
    body = my_strcat(uuid_str, "\r");
    body = my_strcat_free(body, team->name, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, team->description, 1, 0);
    create_add_request_to_list(client->requests_sent, NT_PRINT_TEAM,
    200, body);
    free(body);
}

static void channel_display_info(server_t *server, client_t *client)
{
    char uuid_str[37] = {0};
    char *body;
    channel_t *channel;

    if (!check_channel_exist(server, client->context->uuid_channel, client) ||
    !check_subscribed(server, client))
        return;
    channel = get_channel_by_uuid(server->channels, client->context->uuid_channel);
    if (!channel)
        return;
    uuid_unparse(channel->uuid, uuid_str);
    body = my_strcat(uuid_str, "\r");
    body = my_strcat_free(body, channel->name, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, channel->description, 1, 0);
    create_add_request_to_list(client->requests_sent, NT_PRINT_CHANNEL,
    200, body);
    free(body);
}

static void thread_display_info(server_t *server, client_t *client)
{
    char uuid_str_thread[37] = {0};
    char uuid_str_client[37] = {0};
    char *body;
    thread_t *thread;

    if (!check_thread_exist(server, client->context->uuid_thread, client) ||
        !check_subscribed(server, client))
            return;
        thread = get_thread_by_uuid(server->threads,
        client->context->uuid_thread);
        if (thread == NULL)
            return;
        uuid_unparse(thread->creator_uuid, uuid_str_thread);
        uuid_unparse(thread->uuid, uuid_str_thread);
        body = my_strcat(uuid_str_thread, "\r");
        body = my_strcat_free(body, uuid_str_client, 1, 0);
        send_thread_display_info(body, client, thread);
}

void info_command(server_t *server, client_t *client, UNUSED char **command)
{
    if (client->context == NULL)
        return user_display_info(client);
    switch (client->context->nb_uuid) {
        case 1:
            team_display_info(server, client);
            break;
        case 2:
            channel_display_info(server, client);
            break;
        case 3:
            thread_display_info(server, client);
            break;
    }
    delete_context(client->context);
    client->context = NULL;
}

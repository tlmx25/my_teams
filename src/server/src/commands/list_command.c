/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** list_command.c
*/

#include <stdlib.h>
#include "server.h"
#include "command_server.h"
#include "time_utils.h"
#include "request.h"
#include "my.h"

team_t *send_team_display_list(char *body, client_t *client, team_t *team)
{
    char uuid_str[37] = {0};

    uuid_unparse(team->uuid, uuid_str);
    body = my_strcat(uuid_str, "\r");
    body = my_strcat_free(body, team->name, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, team->description, 1, 0);
    create_add_request_to_list(client->requests_sent, NT_PRINT_TEAM,
        200, body);
    return team->next;
}

static void team_display_list(server_t *server, client_t *client)
{
    char uuid_str[37] = {0};
    char *body;
    team_t *team;

    if (server->teams->head == NULL)
        return create_add_request_to_list(client->requests_sent, PRINT_ERROR,
            404, "No team found");
    team = get_team_by_uuid(server->teams, server->teams->head->uuid);
    while (team) {
        team = send_team_display_list(body, client, team);
        if (team == NULL)
            break;
    }
}

channel_t *send_channel_display_list(char *body, client_t *client, channel_t
    *channel)
{
    char uuid_str[37] = {0};

    uuid_unparse(channel->uuid, uuid_str);
    body = my_strcat(uuid_str, "\r");
    body = my_strcat_free(body, channel->name, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, channel->description, 1, 0);
    create_add_request_to_list(client->requests_sent, NT_PRINT_CHANNEL,
        200, body);
    return channel->next;
}

static void channel_display_list(server_t *server, client_t *client)
{
    char *body;
    channel_t *channel;

    if (!check_subscribed(server, client))
        return;
    if (server->channels->head == NULL)
        return create_add_request_to_list(client->requests_sent, PRINT_ERROR,
            404, "No channel found");
    channel = get_channel_by_uuid(server->channels,
        server->channels->head->uuid);
    while (channel) {
        channel = send_channel_display_list(body, client, channel);
        if (channel == NULL)
            return;
    }
}

thread_t *send_thread_display_list(char *body, client_t *client, thread_t
    *thread)
{
    char uuid_str_thread[37] = {0};
    char uuid_str_client[37] = {0};
    char *time_str = timestamp_to_str(thread->created_at);

    uuid_unparse(thread->uuid, uuid_str_thread);
    uuid_unparse(thread->creator_uuid, uuid_str_client);
    body = my_strcat(uuid_str_thread, "\r");
    body = my_strcat_free(body, uuid_str_client, 1, 0);
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
    return thread->next;
}

static void thread_display_list(server_t *server, client_t *client)
{
    char *body;
    thread_t *thread;

    if (!check_subscribed(server, client))
        return;
    if (server->threads->head == NULL)
        return create_add_request_to_list(client->requests_sent, PRINT_ERROR,
            404, "No thread found");
    thread = get_thread_by_uuid(server->threads, server->channels->head->uuid);
    while (thread) {
        thread = send_thread_display_list(body, client, thread);
        if (thread == NULL)
            return;
    }
}

reply_t *send_replies_display_list(char *body, client_t *client, reply_t
    *reply)
{
    char *time_str = timestamp_to_str(reply->timestamp);
    char uuid_str_thread[37] = {0};
    char uuid_str_client[37] = {0};

    uuid_unparse(reply->thread_uuid, uuid_str_thread);
    uuid_unparse(client->uuid, uuid_str_client);
    body = my_strcat(uuid_str_thread, "\r");
    body = my_strcat_free(body, uuid_str_client, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, time_str, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, reply->body, 1, 0);
    create_add_request_to_list(client->requests_sent, NT_PRINT_REPLY,
        200, body);
    return reply->next;
}

static void replies_display_list(UNUSED server_t *server, UNUSED client_t
    *client)
{
    char *body;
    reply_t *reply;

    if (!check_subscribed(server, client))
        return;
    if (server->replies->head == NULL)
        return create_add_request_to_list(client->requests_sent, PRINT_ERROR,
            404, "No channel found");
    reply = get_reply_by_uuid(server->replies, server->channels->head->uuid);
    while (reply) {
        reply = send_replies_display_list(body, client, reply);
        if (reply == NULL)
            return;
    }
}

void list_command(server_t *server, client_t *client, UNUSED char **command)
{
    if (client->context == NULL) {
        team_display_list(server, client);
        return;
    }
    switch (client->context->nb_uuid) {
        case 0:
            team_display_list(server, client);
            break;
        case 1:
            channel_display_list(server, client);
            break;
        case 2:
            thread_display_list(server, client);
            break;
        case 3:
            replies_display_list(server, client);
            break;
    }
    delete_context(client->context);
    client->context = NULL;
}

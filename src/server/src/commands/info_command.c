/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** info_command.c
*/

#include <stdlib.h>
#include "server.h"
#include "command_server.h"
#include "request.h"
#include "my.h"

static bool_t error_non_existing(team_t *team, channel_t *channel,
    thread_t *thread, client_t *client)
{
    if (team == NULL && channel == NULL && thread == NULL) {
        create_add_request_to_list(client->requests_sent, PRINT_ERROR,
            404, "Context not valid");
        return false;
    }
    return true;
}

team_t find_team(server_t *server, char *uuid_str)
{
    team_t *team = server->teams->head;

    while (team) {
        if (my_strcmp(uuid_str, team->uuid) == 0)
            return *team;
        team = team->next;
    }
    return (channel_t){0};
}

channel_t find_channel(server_t *server, char *uuid_str)
{
    channel_t *channel = server->channels->head;

    while (channel) {
        if (my_strcmp(uuid_str, channel->uuid) == 0)
            return *channel;
        channel = channel->next;
    }
    return (channel_t){0};
}

thread_t find_thread(server_t *server, char *uuid_str)
{
    thread_t *thread = server->threads->head;

    while (thread) {
        if (my_strcmp(uuid_str, thread->uuid) == 0)
            return *thread;
        thread = thread->next;
    }
    return (thread_t){0};
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
    char uuid_str_tmp[37] = {0};
    char *body;
    team_t *team = server->teams->head;

    uuid_unparse(client->context->uuid_team, uuid_str_tmp);
    team = find_team(server, uuid_str_tmp);
    if (error_non_existing(team, NULL, NULL, client) == false)
        return;
    body = my_strcat(uuid_str, "\r");
    body = my_strcat_free(body, team->name, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, team->description, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    my_strncpy(body, body, MAX_BODY_LENGTH);
    create_add_request_to_list(client->requests_sent, NT_PRINT_TEAM, 200,
                               body);
    free(body);
}

static void channel_display_info(server_t *server, client_t *client)
{
    char uuid_str[37] = {0};
    char uuid_str_tmp[37] = {0};
    char *body;
    channel_t *channel = server->channels->head;

    uuid_unparse(client->context->uuid_channel, uuid_str_tmp);
    channel = find_channel(server, uuid_str_tmp);
    if (error_non_existing(NULL, channel, NULL, client) == false)
        return;
    uuid_unparse(channel->uuid, uuid_str);
    body = my_strcat(uuid_str, "\r");
    body = my_strcat_free(body, channel->name, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, channel->description, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    my_strncpy(body, body, MAX_BODY_LENGTH);
    create_add_request_to_list(client->requests_sent, NT_PRINT_CHANNEL, 200,
                               body);
    free(body);
}

void send_thread_display_info(char *body, client_t *client, thread_t thread)
{
    body = my_strcat_free(body, thread->created_at, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, thread.title, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, thread.message, 1, 0);
    my_strncpy(body, body, MAX_BODY_LENGTH);
    create_add_request_to_list(client.requests_sent, NT_PRINT_THREAD, 200,
                               body);
    free(body);
}

static void thread_display_info(server_t *server, client_t *client)
{
    char uuid_str_thread[37] = {0};
    char uuid_str_client[37] = {0};
    char *body;
    thread_t *thread = server->threads->head;

    uuid_unparse(client->context->uuid_thread, uuid_str_client);
    thread = find_thread(server, uuid_str_client);
    if (error_non_existing(NULL, NULL, thread, client) == false)
        return;
    uuid_unparse(thread->uuid, uuid_str_thread);
    uuid_unparse(thread->creator_uuid, uuid_str_client);
    body = my_strcat(uuid_str_thread, "\r");
    body = my_strcat_free(body, uuid_str_client, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    send_thread_display_info(body, client, thread);
}

void info_command(server_t *server, client_t *client, char **command)
{
    if (client->context == NULL) {
        user_display_info(client);
        return;
    }
    switch (client->context->nb_uuid) {
        case 0:
            user_display_info(client);
            break;
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
}

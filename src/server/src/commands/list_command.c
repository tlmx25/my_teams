/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** list_command.c
*/

#include <stdlib.h>
#include "server.h"
#include "command_server.h"
#include "request.h"
#include "my.h"

static bool_t error_non_existing(int team, int channel, int thread, client_t
    *client)
{
    if (team == 0 && channel == 0 && thread == 0) {
        create_add_request_to_list(client->requests_sent, PRINT_ERROR,
                                   404, "Context not valid");
        return false;
    }
    return true;
}

void send_team_display_list(char *body, client_t *client, team_t *team)
{
    body = my_strcat_free(body, team->name, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, team->description, 1, 0);
    my_strncpy(body, body, MAX_BODY_LENGTH);
    printf("body = %s\n", body);
    create_add_request_to_list(client->requests_sent, NT_PRINT_TEAM, 200,
                               body);
    free(body);
}

void send_channel_display_list(char *body, client_t *client, channel_t *channel)
{
    body = my_strcat_free(body, channel->name, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, channel->description, 1, 0);
    my_strncpy(body, body, MAX_BODY_LENGTH);
    create_add_request_to_list(client->requests_sent, NT_PRINT_CHANNEL, 200,
                               body);
    free(body);
}

void send_thread_display_list(char *body, client_t *client, thread_t *thread)
{
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, thread->created_at, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, thread->title, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, thread->message, 1, 0);
    my_strncpy(body, body, MAX_BODY_LENGTH);
    create_add_request_to_list(client->requests_sent, NT_PRINT_THREAD, 200,
                               body);
    free(body);
}

static void team_display_list(server_t *server, client_t *client)
{
    char uuid_str[37] = {0};
    char uuid_str_tmp[37] = {0};
    char *body;
    team_t *team;

    printf("nbr of team = %d\n", server->teams->size);
    if (error_non_existing(server->teams->size, NULL, NULL, client) == false)
        return;
    team = server->teams->head;
    while(team) {
        body = NULL;
        uuid_unparse(client->context->uuid_team, uuid_str_tmp);
        uuid_unparse(team->uuid, uuid_str);
        body = my_strcat(uuid_str, "\r");
        send_team_display_list(body, client, team);
        team = team->next;
    }
}

static void channel_display_list(server_t *server, client_t *client)
{
    char uuid_str[37] = {0};
    char uuid_str_tmp[37] = {0};
    char *body;
    channel_t *channel;

    if (error_non_existing(NULL, server->channels->size, NULL, client) == false)
        return;
    channel = server->channels->head;
    while (channel) {
        body = NULL;
        uuid_unparse(client->context->uuid_channel, uuid_str_tmp);
        uuid_unparse(channel->uuid, uuid_str);
        body = my_strcat(uuid_str, "\r");
        send_channel_display_list(body, client, channel);
        channel = channel->next;
    }
}

static void thread_display_list(server_t *server, client_t *client)
{
    char uuid_str_thread[37] = {0};
    char uuid_str_client[37] = {0};
    char *body;
    thread_t *thread;

    if (error_non_existing(NULL, NULL, server->threads->size, client) == false)
        return;
    thread = server->threads->head;
    while (thread) {
        body = NULL;
        uuid_unparse(client->context->uuid_thread, uuid_str_client);
        uuid_unparse(thread->uuid, uuid_str_thread);
        uuid_unparse(thread->creator_uuid, uuid_str_client);
        body = my_strcat(uuid_str_thread, "\r");
        body = my_strcat_free(body, uuid_str_client, 1, 0);
        send_thread_display_list(body, client, thread);
        thread = thread->next;
    }
}

static void replies_display_list(UNUSED server_t *server, UNUSED client_t *client)
{
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
}

/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** create_thread_command
*/

#include <stdlib.h>
#include "server.h"
#include "logging_server.h"
#include "my.h"
#include "time_utils.h"

static char *create_body(char *uuid_thread_str, char *uuid_user_str, thread_t *thread)
{
    char *body = NULL;
    char *time_str = timestamp_to_str(thread->created_at);

    body = my_strcat(uuid_thread_str, "\r");
    body = my_strcat_free(body, uuid_user_str, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, time_str, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, thread->title, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, thread->message, 1, 0);
    return body;
}

static void send_request_thread(server_t *server, client_t *client,\
    thread_t *thread, request_t *request)
{
    team_t *team = get_team_by_thread(server, thread);

    if (team == NULL)
        return;
    send_notification_subscribed(server, request, client, team->uuid);
    request->action = THREAD_CREATED;
    add_request_to_list(client->requests_sent, request);
}

static void notif_thread_created(server_t *server, client_t *client, thread_t *thread)
{
    request_t *request;
    char *body;
    char uuid_thread_str[37] = {0};
    char uuid_channel_str[37] = {0};
    char uuid_user_str[37] = {0};

    uuid_unparse(thread->uuid, uuid_thread_str);
    uuid_unparse(thread->channel_uuid, uuid_channel_str);
    uuid_unparse(client->uuid, uuid_user_str);
    server_event_thread_created(uuid_channel_str, uuid_thread_str,
    uuid_user_str, thread->title, thread->message);
    body = create_body(uuid_thread_str, uuid_user_str, thread);
    request = create_request(NT_THREAD_CREATED, 200, body);
    send_request_thread(server, client, thread, request);
    free(body);
}

void create_thread_command(server_t *server, client_t *client, char **command)
{
    thread_t *thread;

    if (my_arrsize((char const **)command) != 3)
        return create_add_request_to_list(client->requests_sent, PRINT_ERROR,
        400, "Invalid number of  arguments (2 required)");
    thread = create_thread(command[1], command[2],
    client->uuid, client->context->uuid_channel);
    if (thread == NULL)
        return create_add_request_to_list(client->requests_sent, PRINT_ERROR,
        500, "Failed to create thread");
    add_thread_to_list(server->threads, thread);
    notif_thread_created(server, client, thread);
}

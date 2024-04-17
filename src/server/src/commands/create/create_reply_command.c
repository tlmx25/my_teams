/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** create_reply
*/

#include <stdlib.h>
#include "server.h"
#include "my.h"
#include "time_utils.h"
#include "logging_server.h"

static int check_error_reply(server_t *server, client_t *client)
{
    if (!check_team_exist(server, client->context->uuid_team, client))
        return 0;
    if (!check_channel_exist(server, client->context->uuid_channel, client))
        return 0;
    if (!check_thread_exist(server, client->context->uuid_thread, client))
        return 0;
    return 1;
}

static char *create_body(char uuid_user_str[37], char uuid_thread_str[37],
    char uuid_team_str[37], reply_t *reply)
{
    char *body;

    body = my_strcat(uuid_team_str, "\r");
    body = my_strcat_free(body, uuid_thread_str, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, uuid_user_str, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, reply->body, 1, 0);
    server_event_reply_created(uuid_thread_str, uuid_user_str, reply->body);
    return body;
}

static void send_to_client(server_t *server, client_t *client, reply_t *reply)
{
    char *time_str = timestamp_to_str(reply->timestamp);
    char *body;
    char uuid_user_str[37] = {0};
    char uuid_thread_str[37] = {0};
    char uuid_team_str[37] = {0};
    team_t *team = get_team_by_reply(server, reply);

    if (team == NULL)
        return;
    uuid_unparse(team->uuid, uuid_team_str);
    uuid_unparse(client->uuid, uuid_user_str);
    uuid_unparse(reply->thread_uuid, uuid_thread_str);
    body = create_body(uuid_user_str, uuid_thread_str, uuid_team_str, reply);
    create_add_request_to_list(client->requests_sent,
    MSG_THREAD_REPLY, 200, body);
    free(body);
    free(time_str);
}

static char *create_body_notif(char uuid_thread_str[37],
    char uuid_user_str[37], char *time_str, reply_t *reply)
{
    char *body;

    body = my_strcat(uuid_thread_str, "\r");
    body = my_strcat_free(body, uuid_user_str, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, time_str, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, reply->body, 1, 0);
    return body;
}

static void notif_reply_created(server_t *server, client_t *client,
    reply_t *reply)
{
    team_t *team = get_team_by_reply(server, reply);
    request_t *request;
    char uuid_thread_str[37] = {0};
    char uuid_user_str[37] = {0};
    char *time_str = timestamp_to_str(reply->timestamp);
    char *body;

    if (team == NULL)
        return;
    uuid_unparse(reply->thread_uuid, uuid_thread_str);
    uuid_unparse(client->uuid, uuid_user_str);
    body = create_body_notif(uuid_thread_str, uuid_user_str, time_str, reply);
    request = create_request(NT_PRINT_REPLY, 200, body);
    send_notification_subscribed(server, request, client, team->uuid);
    free(body);
    free(time_str);
    free_request(request);
    send_to_client(server, client, reply);
}

void create_reply_command(server_t *server, client_t *client, char **command)
{
    reply_t *reply;

    if (my_arrsize((char const **)command) != 2)
        return create_add_request_to_list(client->requests_sent, PRINT_ERROR,
        400, "Invalid number of arguments (1 required)");
    if (!check_error_reply(server, client) ||
    !check_subscribed(server, client))
        return;
    reply = create_reply(command[1], client->uuid,
    client->context->uuid_thread);
    if (reply == NULL)
        return create_add_request_to_list(client->requests_sent, PRINT_ERROR,
        400, "Failed to create reply");
    add_reply_to_list(server->replies, reply);
    add_reply_to_save(reply);
    notif_reply_created(server, client, reply);
    delete_context(client->context);
    client->context = NULL;
}

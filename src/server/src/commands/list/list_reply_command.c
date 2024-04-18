/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** list_replies.c
*/

#include <stdlib.h>
#include "server.h"
#include "command_server.h"
#include "time_utils.h"
#include "request.h"
#include "my.h"

static void send_reply_display_list(client_t *client, reply_t *reply)
{
    char *time_str = timestamp_to_str(reply->timestamp);
    char uuid_str_thread[37] = {0};
    char uuid_str_client[37] = {0};
    char *body;

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
    free(body);
}

static reply_t *check_reply_display_list(client_t *client, reply_t
    *reply, server_t *server, bool_t *verif)
{
    team_t *team = get_team_by_reply(server, reply);

    if (team == NULL)
        return reply->next;
    if (uuid_compare(team->uuid, client->context->uuid_team) != 0)
        return reply->next;
    if (uuid_compare(reply->thread_uuid, client->context->uuid_thread) != 0)
        return reply->next;
    *verif = true;
    send_reply_display_list(client, reply);
    return reply->next;
}

void replies_display_list(server_t *server, client_t *client)
{
    reply_t *reply;
    bool_t verif = false;

    if (!check_subscribed(server, client))
        return;
    if (server->threads->head == NULL) {
        return create_add_request_to_list(client->requests_sent, PRINT_ERROR,
            404, "No reply found");
    }
    reply = server->replies->head;
    while (reply) {
        reply = check_reply_display_list(client, reply, server, &verif);
        if (reply == NULL)
            break;
    if (verif == false)
        create_add_request_to_list(client->requests_sent, PRINT_ERROR,
            404, "No reply found");
    }
}

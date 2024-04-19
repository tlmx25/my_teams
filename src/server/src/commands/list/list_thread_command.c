/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** list_thread_command.c
*/

#include <stdlib.h>
#include "server.h"
#include "command_server.h"
#include "time_utils.h"
#include "request.h"
#include "my.h"

static void send_thread_display_list(client_t *client, thread_t *thread)
{
    char *body;
    char uuid_str[37] = {0};
    char *time_str = timestamp_to_str(thread->created_at);

    uuid_unparse(thread->uuid, uuid_str);
    body = my_strcat(uuid_str, "\r");
    uuid_unparse(thread->creator_uuid, uuid_str);
    body = my_strcat_free(body, uuid_str, 1, 0);
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

static thread_t *check_thread_display_list(client_t *client, thread_t
    *thread, server_t *server, bool_t *verif)
{
    team_t *team = get_team_by_thread(server, thread);

    if (team == NULL)
        return thread->next;
    if (uuid_compare(team->uuid, client->context->uuid_team) != 0)
        return thread->next;
    if (uuid_compare(thread->channel_uuid, client->context->uuid_channel) != 0)
        return thread->next;
    *verif = true;
    send_thread_display_list(client, thread);
    return thread->next;
}

void thread_display_list(server_t *server, client_t *client)
{
    thread_t *thread;
    bool_t verif = false;

    if (!check_subscribed(server, client))
        return;
    if (server->threads->head == NULL) {
        return create_add_request_to_list(client->requests_sent, PRINT_ERROR,
            404, "No thread found");
    }
    thread = server->threads->head;
    while (thread) {
        thread = check_thread_display_list(client, thread, server, &verif);
        if (thread == NULL)
            break;
    }
    if (verif == false) {
        create_add_request_to_list(client->requests_sent, PRINT_ERROR,
            404, "No thread found");
    }
}

/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** send_notification
*/

#include "server.h"

void send_notification_all(client_list_t *list, request_t *request)
{
    request_t *dreq;
    client_t *tmp = list->head;

    for (; tmp; tmp = tmp->next) {
        if (tmp->username == NULL)
            continue;
        dreq = create_request(request->action, request->code, request->body);
        add_request_to_list(tmp->requests_sent, dreq);
    }
}

void send_notification_other(client_list_t *list, request_t *request,
    client_t *client)
{
    request_t *dreq;
    client_t *tmp = list->head;

    for (; tmp; tmp = tmp->next) {
        if (tmp->username == NULL ||
            uuid_compare(tmp->uuid, client->uuid) == 0)
            continue;
        dreq = create_request(request->action, request->code, request->body);
        add_request_to_list(tmp->requests_sent, dreq);
    }
}

int is_subscribed(link_team_user_list_t *link, uuid_t team_uuid,
    uuid_t user_uuid)
{
    link_team_user_t *tmp = link->head;

    for (; tmp; tmp = tmp->next) {
        if (uuid_compare(tmp->team_uuid, team_uuid) == 0 &&
            uuid_compare(tmp->user_uuid, user_uuid) == 0)
            return 1;
    }
    return 0;
}

void send_notification_subscribed(server_t *server,
    request_t *request, client_t *client, uuid_t team_uuid)
{
    request_t *dreq;
    client_t *tmp = server->clients->head;

    for (; tmp; tmp = tmp->next) {
        if (tmp->username == NULL ||
            !is_subscribed(server->link_team_user, team_uuid, tmp->uuid) ||
                uuid_compare(tmp->uuid, client->uuid) == 0)
            continue;
        dreq = create_request(request->action, request->code, request->body);
        add_request_to_list(tmp->requests_sent, dreq);
    }
}

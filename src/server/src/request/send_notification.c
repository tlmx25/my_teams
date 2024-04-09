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

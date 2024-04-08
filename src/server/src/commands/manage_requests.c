/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** manage_requests
*/

#include "my.h"
#include "server.h"

void manage_request(UNUSED server_t *server, client_t *client)
{
    linked_request_t *tmp = client->requests_received->head;
    linked_request_t *next;
    char **command = NULL;

    if (tmp == NULL || !client->is_connected)
        return;
    for (; tmp; tmp = next) {
        next = tmp->next;
        command = get_request_arg(tmp->request);
        if (command == NULL)
            return;
        command_manager(server, client, command);
        free_tab(command);
        remove_request_from_list(client->requests_received,
        tmp->request->uuid);
    }
}

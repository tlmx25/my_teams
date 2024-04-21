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

team_t *send_team_display_list(client_t *client, team_t *team)
{
    char uuid_str[37] = {0};
    char *body;

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
    team_t *team;

    if (server->teams->head == NULL)
        return create_add_request_to_list(client->requests_sent, PRINT_ERROR,
            404, "No team found");
    team = get_team_by_uuid(server->teams, server->teams->head->uuid);
    while (team) {
        team = send_team_display_list(client, team);
        if (team == NULL)
            break;
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

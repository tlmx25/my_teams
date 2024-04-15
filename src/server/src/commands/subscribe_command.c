/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** subscribe_command
*/

#include <stdlib.h>
#include "logging_server.h"
#include "server.h"
#include "my.h"

static void send_request_subscribe(client_t *client, char *team_uuid)
{
    char usr_uuid[37];
    request_t *request;
    char *body;

    uuid_unparse(client->uuid, usr_uuid);
    body = my_strcat(usr_uuid, "\r");
    body = my_strcat_free(body, team_uuid, 1, 0);
    create_add_request_to_list(client->requests_sent, NT_PRINT_SUB, 200, body);
    free(body);
}

void subscribe_command(server_t *server, client_t *client, char **command)
{
    uuid_t team_uuid;
    team_t *team;
    char usr_uuid[37];

    if (uuid_parse(command[1], team_uuid) == -1)
        return create_add_request_to_list(client->requests_sent, UNKNOWN_TEAM,
        400, command[1]);
    team = get_team_by_uuid(server->teams, team_uuid);
    if (team == NULL)
        return create_add_request_to_list(client->requests_sent, UNKNOWN_TEAM,
        400, command[1]);
    if (is_subscribed(server->link_team_user, team_uuid, client->uuid))
        return create_add_request_to_list(client->requests_sent, PRINT_ERROR,
        400, "You are already subscribed to this team");
    uuid_unparse(client->uuid, usr_uuid);
    server_event_user_subscribed(command[1], usr_uuid);
    create_link_and_add(server->link_team_user, team_uuid, client->uuid);
    send_request_subscribe(client, command[1]);
    save_link_list(server->link_team_user);
}

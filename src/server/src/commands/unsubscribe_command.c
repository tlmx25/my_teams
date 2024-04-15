/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** unsubscribe_command
*/

#include <stdlib.h>
#include "server.h"
#include "my.h"
#include "logging_server.h"

void send_request_unsub(client_t *client, char *team_uuid, char *user_uuid)
{
    char *body = NULL;

    body = my_strcat(user_uuid, "\r");
    body = my_strcat_free(body, team_uuid, 1, 0);
    create_add_request_to_list(client->requests_sent,
    NT_PRINT_UNSUB, 200, body);
    free(body);
}

void unsubscribe_command(server_t *server, client_t *client, char **command)
{
    uuid_t team_uuid;
    team_t *team;
    char user_uuid[37] = {0};

    if (uuid_parse(command[1], team_uuid) == -1)
        return create_add_request_to_list(client->requests_sent,
        UNKNOWN_TEAM, 400, command[1]);
    team = get_team_by_uuid(server->teams, team_uuid);
    if (team == NULL)
        return create_add_request_to_list(client->requests_sent,
        UNKNOWN_TEAM, 400, command[1]);
    if (!is_subscribed(server->link_team_user, team_uuid, client->uuid))
        return create_add_request_to_list(client->requests_sent,
        PRINT_ERROR, 400, "You are not subscribed to this team");
    uuid_unparse(client->uuid, user_uuid);
    server_event_user_unsubscribed(command[1], user_uuid);
    remove_link_by_uuid(server->link_team_user, team_uuid, client->uuid);
    save_link_list(server->link_team_user);
    send_request_unsub(client, command[1], user_uuid);
}

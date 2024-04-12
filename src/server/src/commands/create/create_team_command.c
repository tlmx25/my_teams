/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** create_team_command
*/

#include <stdlib.h>
#include "server.h"
#include "logging_server.h"
#include "my.h"

static void notif_team_created(server_t *server, client_t *client, team_t *team)
{
    char team_uuid[37] = {0};
    char user_uuid[37] = {0};
    char *body;

    uuid_unparse(client->uuid, user_uuid);
    uuid_unparse(team->uuid, team_uuid);
    body = my_strcat(team_uuid, "\r");
    body = my_strcat_free(body, team->name, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, team->description, 1, 0);
    send_notification_other(server->clients, create_request(NT_TEAM_CREATED,
    200, body), client);
    create_add_request_to_list(client->requests_sent, TEAM_CREATED,
    200, body);
    server_event_team_created(team_uuid, team->name, team->description);
    add_team_to_save(team);
    free(body);
}

void create_team_command(server_t *server, client_t *client, char **command)
{
    uuid_t uuid;
    team_t *team = NULL;

    if (my_arrsize((char const **)command) != 3)
        return create_add_request_to_list(client->requests_sent, PRINT_ERROR,
                                          400, "Invalid number of  arguments (2 required)");
    uuid_generate(uuid);
    team = create_team(command[1], command[2], uuid, client->uuid);
    if (team == NULL)
        return create_add_request_to_list(client->requests_sent, PRINT_ERROR,
                                          400, "Failed to create team");
    add_team_to_list(server->teams, team);
    notif_team_created(server, client, team);
}

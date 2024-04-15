/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** subscribed_command
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"
#include "my.h"

static void send_request_subscribed(server_t *server, client_t *client,
    uuid_t team_uuid)
{
    team_t *team = get_team_by_uuid(server->teams, team_uuid);
    char *body;
    char uuid_team_str[37] = {0};

    if (team == NULL)
        return;
    uuid_unparse(team->uuid, uuid_team_str);
    body = my_strcat(uuid_team_str, "\r");
    body = my_strcat_free(body, team->name, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    body = my_strcat_free(body, team->description, 1, 0);
    create_add_request_to_list(client->requests_sent, PRINT_TEAMS, 200, body);
    free(body);
}

static void list_all_team(server_t *server, client_t *client)
{
    link_team_user_t *tmp = server->link_team_user->head;

    for (; tmp; tmp = tmp->next) {
        if (uuid_compare(tmp->user_uuid, client->uuid) == 0)
            send_request_subscribed(server, client, tmp->team_uuid);
    }
}

static void send_user_sub(server_t *server, client_t *client,
    uuid_t client_sub)
{
    char usr_uuid[37];
    char *body;
    char is_connected[2] = {0};
    client_t *client_sub_data = get_client_by_uuid(server->clients_loaded,
    client_sub);

    if (client_sub_data == NULL)
        return;
    uuid_unparse(client_sub, usr_uuid);
    body = my_strcat(usr_uuid, "\r");
    body = my_strcat_free(body, client_sub_data->username, 1, 0);
    body = my_strcat_free(body, "\r", 1, 0);
    is_connected[0] = (get_client_by_uuid(server->clients,
    client_sub)) ? '1' : '0';
    body = my_strcat_free(body, is_connected, 1, 0);
    create_add_request_to_list(client->requests_sent, PRINT_USERS, 200, body);
    free(body);
}

static void list_all_users_sub(server_t *server, client_t *client,
    char *team_uuid)
{
    uuid_t team_uuid_t;
    team_t *team;

    if (uuid_parse(team_uuid, team_uuid_t) == -1)
        return create_add_request_to_list(client->requests_sent, UNKNOWN_TEAM,
        400, team_uuid);
    team = get_team_by_uuid(server->teams, team_uuid_t);
    if (team == NULL)
        return create_add_request_to_list(client->requests_sent, UNKNOWN_TEAM,
        400, team_uuid);
    for (link_team_user_t *tmp = server->link_team_user->head; tmp;
        tmp = tmp->next) {
        if (uuid_compare(tmp->team_uuid, team_uuid_t) == 0)
            send_user_sub(server, client, tmp->user_uuid);
    }
}

void subscribed_command(server_t *server, client_t *client, char **command)
{
    int nb_arg = my_arrsize((char const **)command);

    if (nb_arg > 2)
        return create_add_request_to_list(client->requests_sent, PRINT_ERROR,
        404, "Invalid number of  arguments (1 | 2 required)");
    if (nb_arg == 1)
        return list_all_team(server, client);
    list_all_users_sub(server, client, command[1]);
}

/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** use_command
*/

#include "server.h"
#include "my.h"

static int set_context_use(client_t *client, char *team_uuid, char *channel_uuid,
    char *thread_uuid)
{
    client->context = create_context(team_uuid, channel_uuid, thread_uuid);
    if (client->context == NULL) {
        create_add_request_to_list(client->requests_sent, PRINT_ERROR,
        400, "Failed to change context");
        return 0;
    }
    return 1;
}

static int check_thread_exist(server_t *server, char *thread_uuid,
    client_t *client)
{
    uuid_t thread_uuid_t;

    if (uuid_parse(thread_uuid, thread_uuid_t) == -1)
        return 0;
    if (get_thread_by_uuid(server->threads, thread_uuid_t))
        return 1;
    create_add_request_to_list(client->requests_sent, PRINT_ERROR,
    400, "Thread does not exist");
    return 0;
}

static int check_channel_exist(server_t *server, char *channel_uuid,
    client_t *client)
{
    uuid_t channel_uuid_t;

    if (uuid_parse(channel_uuid, channel_uuid_t) == -1)
        return 0;
    if (get_channel_by_uuid(server->channels, channel_uuid_t))
        return 1;
    create_add_request_to_list(client->requests_sent, PRINT_ERROR,
    400, "Channel does not exist");
    return 0;
}

static int check_team_exist(server_t *server, char *team_uuid,
    client_t *client)
{
    uuid_t team_uuid_t;

    if (uuid_parse(team_uuid, team_uuid_t) == -1)
        return 0;
    if (get_team_by_uuid(server->teams, team_uuid_t))
        return 1;
    create_add_request_to_list(client->requests_sent, PRINT_ERROR,
    400, "Team does not exist");
    return 0;
}

void use_command(server_t *server, client_t *client, char **command)
{
    int nb_args = my_arrsize((char const **)command) - 1;

    if (nb_args < 1 || nb_args > 3) {
        create_add_request_to_list(client->requests_sent, PRINT_ERROR,
        400, "Invalid number of arguments");
        return;
    }
    if (!check_team_exist(server, command[1], client))
        return;
    if (nb_args == 2 && !check_channel_exist(server, command[2], client))
        return;
    if (nb_args == 3 && !check_thread_exist(server, command[3], client))
        return;
    if (!set_context_use(client, command[1], command[2],
        (command[2]) ? command[3] : NULL))
        return;
    create_add_request_to_list(client->requests_sent, PRINT_ERROR, 200,
        "Successfully changed context");
}

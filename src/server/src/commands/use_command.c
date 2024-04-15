/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** use_command
*/

#include "server.h"
#include "my.h"

int set_context_use(client_t *client, char *team_uuid,
    char *channel_uuid, char *thread_uuid)
{
    if (client->context)
        delete_context(client->context);
    client->context = create_context(team_uuid, channel_uuid, thread_uuid);
    if (client->context == NULL) {
        create_add_request_to_list(client->requests_sent, PRINT_ERROR,
        400, "Failed to change context");
        return 0;
    }
    return 1;
}

int check_thread_exist(server_t *server, uuid_t thread_uuid, client_t *client)
{
    char thread_uuid_str[37] = {0};

    if (get_thread_by_uuid(server->threads, thread_uuid))
        return 1;
    uuid_unparse(thread_uuid, thread_uuid_str);
    create_add_request_to_list(client->requests_sent, UNKNOWN_THREAD,
    400, thread_uuid_str);
    return 0;
}

int check_channel_exist(server_t *server, uuid_t channel_uuid,
    client_t *client)
{
    char channel_uuid_str[37] = {0};

    if (get_channel_by_uuid(server->channels, channel_uuid))
        return 1;
    uuid_unparse(channel_uuid, channel_uuid_str);
    create_add_request_to_list(client->requests_sent, UNKNOWN_CHANNEL,
    400, channel_uuid_str);
    return 0;
}

int check_team_exist(server_t *server, uuid_t team_uuid, client_t *client)
{
    char team_uuid_str[37] = {0};

    if (get_team_by_uuid(server->teams, team_uuid))
        return 1;
    uuid_unparse(team_uuid, team_uuid_str);
    create_add_request_to_list(client->requests_sent, UNKNOWN_TEAM,
    400, team_uuid_str);
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
    if (!set_context_use(client, command[1], command[2],
        (command[2]) ? command[3] : NULL))
        return;
    create_add_request_to_list(client->requests_sent, PRINT_ERROR, 200,
        "Successfully changed context");
}

//    if (!check_team_exist(server, command[1], client))
//        return;
//    if (nb_args == 2 && !check_channel_exist(server, command[2], client))
//        return;
//    if (nb_args == 3 && !check_thread_exist(server, command[3], client))
//        return;

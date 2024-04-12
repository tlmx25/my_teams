/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** create_command
*/

#include "server.h"
#include "my.h"

void create_command(server_t *server, client_t *client, char **command)
{
    if (client->context == NULL)
        return create_team_command(server, client, command);
    if (client->context != NULL && client->context->nb_uuid == 1)
        return create_channel_command(server, client, command);
}

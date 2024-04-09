/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** creation_commands
*/

#include <stdio.h>
#include "client_cli.h"
#include "logging_client.h"

void creation_team_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 3);

    if (args == NULL) {
        printf("Invalid number of arguments for creation team command\n");
        return;
    }
    client_event_team_created(args[0], args[1], args[2]);
    free(args);
}

void creation_channel_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 3);

    if (args == NULL) {
        printf("Invalid number of arguments for creation channel command\n");
        return;
    }
    client_event_channel_created(args[0], args[1], args[2]);
    free(args);
}

void creation_thread_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 5);

    if (args == NULL) {
        printf("Invalid number of arguments for creation thread command\n");
        return;
    }
    client_event_thread_created(args[0], args[1], args[2], args[3], args[4]);
    free(args);
}

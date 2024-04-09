/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** creation_commands
*/

#include <stdio.h>
#include <time.h>
#include "client_cli.h"
#include "my.h"
#include "logging_client.h"
#include "time_utils.h"

void creation_team_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 3);

    if (args == NULL) {
        printf("Invalid number of arguments for creation team command\n");
        return;
    }
    client_event_team_created(args[0], args[1], args[2]);
    free_tab(args);
}

void creation_channel_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 3);

    if (args == NULL) {
        printf("Invalid number of arguments for creation channel command\n");
        return;
    }
    client_event_channel_created(args[0], args[1], args[2]);
    free_tab(args);
}

void creation_thread_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 5);
    time_t time;

    if (args == NULL) {
        printf("Invalid number of arguments for creation team command\n");
        return;
    }
    time = str_to_timestamp(args[2]);
    client_event_thread_created(args[0], args[1], time, args[3], args[4]);
    free_tab(args);
}

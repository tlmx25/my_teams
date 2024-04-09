/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** print_commands
*/

#include <stdio.h>
#include "client_cli.h"
#include "logging_client.h"

void print_users_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 3);

    if (args == NULL) {
        printf("Invalid number of arguments for print users command\n");
        return;
    }
    client_print_users(args[0], args[1], args[2]);
    free(args);
}

void print_teams_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 3);

    if (args == NULL) {
        printf("Invalid number of arguments for print teams command\n");
        return;
    }
    client_print_teams(args[0], args[1], args[2]);
    free(args);
}

void print_channels_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 3);

    if (args == NULL) {
        printf("Invalid number of arguments for print channels command\n");
        return;
    }
    client_team_print_channels(args[0], args[1], args[2]);
    free(args);
}

void print_threads_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 5);

    if (args == NULL) {
        printf("Invalid number of arguments for print threads command\n");
        return;
    }
    client_channel_print_threads(args[0], args[1], args[2], args[3], args[4]);
    free(args);
}

void print_replies_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 4);

    if (args == NULL) {
        printf("Invalid number of arguments for print replies command\n");
        return;
    }
    client_event_print_replies(args[0], args[1], args[2], args[3]);
    free(args);
}

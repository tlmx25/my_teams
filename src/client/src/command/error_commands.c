/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** error command
*/

#include <stdio.h>
#include "client_cli.h"
#include "logging_client.h"

void error_team_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 1);

    if (args == NULL) {
        printf("Invalid number of arguments for error team command\n");
        return;
    }
    client_error_unknown_team(args[0]);
    free(args);
}

void error_channel_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 1);

    if (args == NULL) {
        printf("Invalid number of arguments for error channel command\n");
        return;
    }
    client_error_unknown_channel(args[0]);
    free(args);
}

void error_thread_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 1);

    if (args == NULL) {
        printf("Invalid number of arguments for error team command\n");
        return;
    }
    client_error_unknown_thread(args[0]);
    free(args);
}

void error_user_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 1);

    if (args == NULL) {
        printf("Invalid number of arguments for error user command\n");
        return;
    }
    client_error_unknown_user(args[0]);
    free(args);
}

void error_unauthorized_command(UNUSED client_t *client,
    UNUSED request_t *request)
{
    client_error_unauthorized();
}

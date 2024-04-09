/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** nt_print_commands
*/

#include <stdio.h>
#include "client_cli.h"
#include "logging_client.h"

void nt_print_user_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 3);

    if (args == NULL) {
        printf("Invalid number of arguments for print user command\n");
        return;
    }
    client_print_user(args[0], args[1], atoi(args[2]));
    free(args);
}

void nt_print_team_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 3);

    if (args == NULL) {
        printf("Invalid number of arguments for print team command\n");
        return;
    }
    client_print_team(args[0], args[1], args[2]);
    free(args);
}

void nt_print_channel_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 3);

    if (args == NULL) {
        printf("Invalid number of arguments for print channel command\n");
        return;
    }
    client_print_channel(args[0], args[1], args[2]);
    free(args);
}

void nt_print_thread_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 5);

    if (args == NULL) {
        printf("Invalid number of arguments for print thread command\n");
        return;
    }
    client_print_thread(args[0], args[1], args[2], args[3], args[4]);
    free(args);
}

void nt_team_created_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 3);

    if (args == NULL) {
        printf("Invalid number of arguments for team created command\n");
        return;
    }
    client_print_team_created(args[0], args[1], args[2]);
    free(args);
}

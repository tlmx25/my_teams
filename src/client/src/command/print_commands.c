/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** print_commands
*/

#include <stdio.h>
#include "client_cli.h"
#include "logging_client.h"
#include "time_utils.h"
#include "my.h"

void print_users_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 3);

    if (args == NULL) {
        printf("Invalid number of arguments for print users command\n");
        return;
    }
    client_print_users(args[0], args[1], my_getnbr(args[2]));
    free_tab(args);
}

void print_teams_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 3);

    if (args == NULL) {
        printf("Invalid number of arguments for print teams command\n");
        return;
    }
    client_print_teams(args[0], args[1], args[2]);
    free_tab(args);
}

void print_channels_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 3);

    if (args == NULL) {
        printf("Invalid number of arguments for print channels command\n");
        return;
    }
    client_team_print_channels(args[0], args[1], args[2]);
    free_tab(args);
}

void print_threads_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 5);
    time_t time;

    if (args == NULL) {
        printf("Invalid number of arguments for print threads command\n");
        return;
    }
    time = str_to_timestamp(args[2]);
    client_channel_print_threads(args[0], args[1], time, args[3], args[4]);
    free_tab(args);
}

void print_replies_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 4);
    time_t time;

    if (args == NULL) {
        printf("Invalid number of arguments for print replies command\n");
        return;
    }
    time = str_to_timestamp(args[2]);
    client_thread_print_replies(args[0], args[1], time, args[3]);
    free_tab(args);
}

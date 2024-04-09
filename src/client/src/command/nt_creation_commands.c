/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** nt_creation_commands
*/

#include <stdio.h>
#include "client_cli.h"
#include "my.h"
#include "logging_client.h"
#include "time_utils.h"

void nt_channel_created_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 3);

    if (args == NULL) {
        printf("Invalid number of arguments for channel created command\n");
        return;
    }
    client_print_channel_created(args[0], args[1], args[2]);
    free_tab(args);
}

void nt_thread_created_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 5);
    time_t time;

    if (args == NULL) {
        printf("Invalid number of arguments for team created command\n");
        return;
    }
    time = str_to_timestamp(args[2]);
    client_print_thread_created(args[0], args[1], time, args[3], args[4]);
    free_tab(args);
}

void nt_print_reply_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 4);
    time_t time;

    if (args == NULL) {
        printf("Invalid number of arguments for print reply command\n");
        return;
    }
    time = str_to_timestamp(args[2]);
    client_print_reply_created(args[0], args[1], time, args[3]);
    free_tab(args);
}

void nt_print_sub_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 2);

    if (args == NULL) {
        printf("Invalid number of arguments for print subscribed command\n");
        return;
    }
    client_print_subscribed(args[0], args[1]);
    free_tab(args);
}

void nt_print_unsub_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 2);

    if (args == NULL) {
        printf("Invalid number of arguments for print unsubscribed command\n");
        return;
    }
    client_print_unsubscribed(args[0], args[1]);
    free_tab(args);
}

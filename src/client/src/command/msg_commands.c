/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** msg_commands
*/

#include <stdio.h>
#include "client_cli.h"
#include "logging_client.h"

void print_prv_msg_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 3);

    if (args == NULL) {
        printf("Invalid number of arguments for private messages command\n");
        return;
    }
    client_private_message_print_messages(args[0], args[1], args[2]);
    free(args);
}

void thread_reply_rcvd_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 4);

    if (args == NULL) {
        printf("Invalid number of arguments for thread reply command\n");
        return;
    }
    client_event_thread_reply_received(args[0], args[1], args[2], args[3]);
    free(args);
}

void prv_msg_rcvd_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 2);

    if (args == NULL) {
        printf("Invalid number of arguments for private message received command\n");
        return;
    }
    client_event_private_message_received(args[0], args[1]);
    free(args);
}

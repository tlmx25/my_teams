/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** logged_in_command
*/

#include <stdio.h>
#include "client_cli.h"
#include "my.h"
#include "logging_client.h"

void logged_in_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 2);

    if (args == NULL) {
        printf("Invalid number of arguments for logged in command\n");
        return;
    }
    client_event_logged_in(args[0], args[1]);
    free_tab(args);
}

void logged_out_command(UNUSED client_t *client, request_t *request)
{
    char **args = get_request_nb_arg(request, 2);

    if (args == NULL) {
        printf("Invalid number of arguments for logged out command\n");
        return;
    }
    client_event_logged_out(args[0], args[1]);
    free_tab(args);
    client->is_running = false;
}

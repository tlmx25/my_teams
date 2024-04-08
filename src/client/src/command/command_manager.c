/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** command_manger
*/

#include "client_cli.h"
#include "command_client.h"

static const command_t COMMANDS[] = {
    {LOGGED_IN, &logged_in_command},
    {PRINT_ERROR, &print_error_command},
    {NONE, NULL}
};

void command_manager(client_t *client, request_t *request)
{
    if (request->action == NONE)
        return;
    for (int i = 0; COMMANDS[i].action != NONE; i++) {
        if (COMMANDS[i].action == request->action) {
            COMMANDS[i].func(client, request);
            return;
        }
    }
}

/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** command_manager
*/

#include "stdlib.h"
#include <stdio.h>
#include "my.h"
#include "command_server.h"

static const command_t COMMANDS[] = {
    {"/login", login_command, false, 1},
    {NULL, NULL, false, 0}
};

static int check_nb_arg(client_t *client, char **command, int i)
{
    if (COMMANDS[i].nb_args == -1)
        return 1;
    if (COMMANDS[i].nb_args == my_arrsize((char const **)command) - 1) {
        return 1;
    }
    create_add_request_to_list(client->requests_sent, PRINT_ERROR,
    400, "Invalid number of arguments");
    return 0;
}

static int check_is_connected(client_t *client, int i)
{
    if (COMMANDS[i].need_logged == false)
        return 1;
    if (client->username == NULL) {
        create_add_request_to_list(client->requests_sent, PRINT_ERROR,
        400, "You need to be logged in to use this command");
        return 0;
    }
    return 1;
}

void command_manager(server_t *server, client_t *client, char **command)
{
    int i = 0;

    if (command == NULL)
        return;
    for (; COMMANDS[i].command; i++) {
        if (my_strcmp(command[0], COMMANDS[i].command) != 0)
            continue;
        if (!check_nb_arg(client, command, i))
            return;
        if (!check_is_connected(client, i))
            return;
        COMMANDS[i].func(server, client, command);
    }
}
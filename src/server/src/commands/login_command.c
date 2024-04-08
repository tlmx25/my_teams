/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** login_command
*/

#include <stdio.h>
#include "server.h"

void login_command(UNUSED server_t *server, client_t *client,
    UNUSED char **command)
{
    printf("Login command\n");
    create_add_request_to_list(client->requests_sent, LOGGED_IN,
    200, "2FA23892-B80B-40D6-8544-4C1C3923E022\rtom");
}

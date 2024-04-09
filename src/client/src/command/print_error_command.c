/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** print_error_command
*/

#include <stdio.h>
#include "client_cli.h"
#include "logging_client.h"

void print_error_command(UNUSED client_t *client, request_t *request)
{
    printf("%s\n", request->body);
}

void print_error_existing_client_command(UNUSED client_t *client,
    request_t *request)
{
    client_error_already_exist();
}

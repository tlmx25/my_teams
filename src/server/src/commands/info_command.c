/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** info_command.c
*/

#include "server.h"

void info_command(server_t *server, client_t *client, char **command)
{
	if (client->is_connected == false) {
		add_request_to_list(client->requests_sent,create_request
		(PRINT_ERROR, 200, "You are not logged in"));
		return;
	}
}

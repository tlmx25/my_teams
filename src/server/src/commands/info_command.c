/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** info_command.c
*/

#include "server.h"
#include "command_server.h"
#include "request.h"
#include "my.h"

void info_command(server_t *server, client_t *client, char **command)
{
	client_t *current = server->clients_loaded->head;

	while (current) {
		uuid_unparse(current->uuid, uuid_str);
		if (my_strcmp(uuid_str, command[1]) == 0) {
			return;
		}
		current = current->next;
	}
}

/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** load_client
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "logging_server.h"
#include "client.h"

static client_t *convert_client(client_save_t client)
{
    client_t *new_client;
    char *uuid_str = calloc(37, sizeof(char));

    if (!uuid_str)
        return NULL;
    uuid_unparse(client.uuid, uuid_str);
    new_client = create_client(-1, client.username, client.password, uuid_str);
    free(uuid_str);
    return new_client;
}

static void print_loaded(client_save_t client)
{
    char *uuid_str = calloc(37, sizeof(char));

    if (!uuid_str)
        return;
    uuid_unparse(client.uuid, uuid_str);
    server_event_user_loaded(client.username, uuid_str);
    free(uuid_str);
}

void load_client_list(client_list_t *list)
{
    client_save_t client = {0};
    int fd = open(CLIENT_FILE, O_RDONLY);

    if (fd == -1)
        return;
    while (read(fd, &client, sizeof(client_save_t)) > 0) {
        add_client_to_list(list, convert_client(client));
        print_loaded(client);
    }
    close(fd);
}

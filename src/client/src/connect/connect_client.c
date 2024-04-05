/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** connect_client
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include "client.h"

int connect_to_server(client_t *client)
{
    struct sockaddr_in serv_addr;

    client->fd_server = socket(AF_INET, SOCK_STREAM, 0);
    if (client->fd_server < 0)
        return 84;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(client->port);
    serv_addr.sin_addr.s_addr = inet_addr(client->ip);
    if (connect(client->fd_server, (struct sockaddr *)&serv_addr,
        sizeof(serv_addr)) < 0) {
        printf("Connection failed\n");
        return ERROR;
    }
    return 0;
}

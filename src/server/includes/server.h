/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** server
*/

#pragma once

#ifndef PRIVATE_TEAMS_SERVER_H
    #define PRIVATE_TEAMS_SERVER_H
    #include <sys/types.h>
    #include "socket.h"
    #include "management_socket.h"
    #include "request.h"
    #include "client.h"

typedef enum {
    false,
    true
} bool;

typedef struct server_s {
    bool is_running;
    int port;
    int socket;
    select_t *select_config;
    client_list_t *clients;
} server_t;

/**
 * @brief Create a new server
 *
 * @param port port of the server
 * @return server_t*
 */
server_t *create_server(int port);

/**
 * @brief Delete a server
 *
 * @param server server to delete
 */
void delete_server(server_t *server);

/**
 * @brief run the server
 * @param server server to run
 * @return int 0 if success, 84 if error
 */
int run_server(server_t *server);

/**
 * @brief manage server, read and write on socket of client and
 * accept new client
 * @param server server to manage
 */
void manage_server(server_t *server);
#endif //PRIVATE_TEAMS_SERVER_H

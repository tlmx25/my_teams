/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** client
*/

#pragma once

#ifndef PRIVATE_TEAMS_CLIENT_H
    #define PRIVATE_TEAMS_CLIENT_H
    #include "management_socket.h"
    #define ERROR 84
    #define UNUSED __attribute__((unused))
    #include "actions.h"
    #include "request.h"
typedef enum bool_e {
    false,
    true
} bool_t;

typedef struct client_s {
    char *ip;
    int port;
    int fd_server;
    bool_t is_running;
    select_t *config_select;
    request_list_t *requests_to_send;
} client_t;

typedef struct command_s {
    action_t action;
    void (*func)(client_t *, request_t *);
} command_t;

typedef struct parse_cmd_s {
    char *cmd;
    char **args;
    int nb_args;
    int in_quotes;
    int start;
    int check_error;
} parse_cmd_t;

/**
 * @brief Create a client object
 *
 * @param ip The ip to connect to
 * @param port The port to connect to
 */
client_t *create_client(char *ip, int port);

/**
 * @brief Delete a client object
 *
 * @param client The client object to delete
 */
void delete_client(client_t *client);

/**
 * @brief Run the client logic
 *
 * @param client The client object
 *
 * @return int The return code
 */
int run_client(client_t *client);

/**
 * @brief Connect client to server
 *
 * @param client The client object to connect to server
 *
 * @return int Return 0 if success, 84(ERROR) if error
 */
int connect_to_server(client_t *client);

/**
 * @brief Create a request to add to the list of requests to send
 *
 * @param client The client object
 * @param msg The message to send
 */
void create_add_request(client_t *client, char *msg);

/**
 * @brief Check if request action exist and execute it
 *
 * @param client The client object
 * @param request The request object
 */
void command_manager(client_t *client, request_t *request);

/**
 * @brief Parse the command line
 *
 * @param line The command line
 * @return char** The parsed command
 */
char **parse_arguments(char *line);

/**
 * @brief Check if the command is correct
 *
 * @param command The command to check
 * @return int The return code
 */
int command_error_handling(char **command);
#endif //PRIVATE_TEAMS_CLIENT_H

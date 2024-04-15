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
    #include "messages.h"
    #include "team.h"
    #include "link_team_user.h"
    #include "channel.h"
    #include "thread_teams.h"
    #include "reply.h"
    #define UNUSED __attribute__((unused))


typedef struct server_s {
    bool_t is_running;
    int port;
    int socket;
    select_t *select_config;
    client_list_t *clients_loaded;
    client_list_t *clients;
    message_list_t *messages;
    team_list_t *teams;
    link_team_user_list_t *link_team_user;
    channel_list_t *channels;
    thread_list_t *threads;
    reply_list_t *replies;
} server_t;

typedef struct command_s {
    char *command;
    void (*func)(server_t *server, client_t *client, char **command);
    bool_t need_logged;
    int nb_args;
} command_t;

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

/**
 * @brief manage request of client
 * @param server server
 * @param client client to manage request
 */
void manage_request(server_t *server, client_t *client);

/**
 * @brief Manage command of request of client
 * @param server server
 * @param client
 * @param command
 */
void command_manager(server_t *server, client_t *client, char **command);

/**
 * @brief Send a response error to a client
 * @param client client to send to
 * @param message message to send
 */
void send_error_response(client_t *client, char *message);

/**
 * @brief Send a request to all clients
 * @param list list of clients
 * @param request template of request to send
 */
void send_notification_all(client_list_t *list, request_t *request);

/**
 * @brief Send a request to all clients except one
 * @param list list of clients
 * @param request template of request to send
 * @param client client to not send
 */
void send_notification_other(client_list_t *list, request_t *request,
    client_t *client);

/**
 * @brief
 * @param server
 * @param client
 * @param command
 */
void use_command(server_t *server, client_t *client, char **command);

/**
 * @brief Must be called when a new team is created
 * @param server
 * @param client
 * @param command
 */
void create_team_command(server_t *server, client_t *client, char **command);

/**
 * @brief Must be called when a new channel is created
 * @param server
 * @param client
 * @param command
 */
void create_channel_command(server_t *server, client_t *client,
    char **command);

/**
 * @brief Must be called for create team, channel, thread, reply
 * @param server
 * @param client
 * @param command
 */
void create_command(server_t *server, client_t *client, char **command);

/**
 * @brief Called for send notification for subscribed user
 * @param server
 * @param request
 * @param client
 * @param team_uuid
 */
void send_notification_subscribed(server_t *server,
    request_t *request, client_t *client, uuid_t team_uuid);

/**
 * @brief Check if a user is subscribed to a team
 * @param link
 * @param team_uuid
 * @param user_uuid
 * @return int
 */
int is_subscribed(link_team_user_list_t *link, uuid_t team_uuid,
    uuid_t user_uuid);

/**
 * @brief Get a team by channel
 * @param list
 * @param channel
 * @return team_t*
 */
team_t *get_team_by_channel(team_list_t *list, channel_t *channel);

/**
 * @brief Get a team by thread
 * @param server
 * @param list
 * @param thread
 * @return team_t*
 */
team_t *get_team_by_thread(server_t *server, thread_t *thread);

/**
 * @brief Get a team by reply
 * @param server
 * @param list
 * @param reply
 * @return team_t*
 */
team_t *get_team_by_reply(server_t *server, reply_t *reply);

/**
 * @brief create a new thread
 * @param server
 * @param client
 * @param command
 */
void create_thread_command(server_t *server, client_t *client, char **command);

/**
 * @brief subscribed command
 * @param server
 * @param client
 * @param command
 */
void subscribed_command(server_t *server, client_t *client, char **command);

/**
 * @brief subscribe command
 * @param server
 * @param client
 * @param command
 */
void subscribe_command(server_t *server, client_t *client, char **command);

/**
 * @brief unsubscribe command
 * @param server
 * @param client
 * @param command
 */
void unsubscribe_command(server_t *server, client_t *client, char **command);

int check_channel_exist(server_t *server, uuid_t channel_uuid,
    client_t *client);
int check_thread_exist(server_t *server, uuid_t thread_uuid, client_t *client);
int check_team_exist(server_t *server, uuid_t team_uuid, client_t *client);

/**
 * @brief create a new reply
 * @param server
 * @param client
 * @param command
 */
void create_reply_command(server_t *server, client_t *client, char **command);
#endif //PRIVATE_TEAMS_SERVER_H

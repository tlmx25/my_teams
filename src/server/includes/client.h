/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** client
*/

#pragma once

#ifndef PRIVATE_TEAMS_CLIENT_H
    #define PRIVATE_TEAMS_CLIENT_H
    #include "request.h"

typedef struct client_s {
    uuid_t uuid;
    int fd;
    char *username;
    char *password;
    request_list_t *requests_received;
    request_list_t *requests_sent;
    struct client_s *next;
    struct client_s *prev;
} client_t;

typedef struct client_list_s {
    client_t *head;
    client_t *tail;
} client_list_t;

/**
 * @brief Create a new client
 *
 * @param fd fd of the client
 * @param username username of the client
 * @param password password of the client
 * @return client_t*
 */
client_t *create_client(int fd, char *username, char *password);

/**
 * @brief Create a new client list
 *
 * @return client_list_t*
 */
client_list_t *create_client_list(void);

/**
 * @brief Add a client to a client list
 *
 * @param list list to add the client to
 * @param client client to add
 */
void add_client_to_list(client_list_t *list, client_t *client);

/**
 * @brief free a client
 * @param client client to free
 */
void free_client(client_t *client);

/**
 * @brief Remove a client from a client list
 *
 * @param list list to remove the client from
 * @param client client to remove
 */
void remove_client_from_list(client_list_t *list, client_t *client);

/**
 * @brief remove a client from a client list with a fd
 *
 * @param list list to remove the client from
 * @param fd fd of the client to remove
 */
void remove_client_by_fd(client_list_t *list, int fd);

/**
 * @brief remove a client from a client list with a uuid
 *
 * @param list list to remove the client from
 * @param uuid uuid of the client to remove
 */
void remove_client_by_uuid(client_list_t *list, uuid_t uuid);

/**
 * @brief Get a client from a client list with a uuid
 *
 * @param list list to get the client from
 * @param uuid uuid of the client to get
 * @return client_t*
 */
client_t *get_client_by_uuid(client_list_t *list, uuid_t uuid);

/**
 * @brief Get a client from a client list with a fd
 *
 * @param list list to get the client from
 * @param fd fd of the client to get
 * @return client_t*
 */
client_t *get_client_by_fd(client_list_t *list, int fd);
#endif //PRIVATE_TEAMS_CLIENT_H

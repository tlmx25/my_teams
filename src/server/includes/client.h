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
    #define CLIENT_FILE ".save/client.save"
    #define SAVE_DIR ".save"
    #define MAX_NAME_LENGTH 32

typedef enum {
    false,
    true
} bool_t;

typedef struct context_s {
    uuid_t uuid_team;
    uuid_t uuid_channel;
    uuid_t uuid_thread;
    int nb_uuid;
} context_t;

typedef struct client_s {
    bool_t is_connected;
    uuid_t uuid;
    int fd;
    char *username;
    char *password;
    request_list_t *requests_received;
    request_list_t *requests_sent;
    context_t *context;
    struct client_s *next;
    struct client_s *prev;
} client_t;

typedef struct client_save_s {
    uuid_t uuid;
    char username[MAX_NAME_LENGTH + 1];
    char password[MAX_NAME_LENGTH + 1];
} client_save_t;

typedef struct client_list_s {
    client_t *head;
    client_t *tail;
    int size;
} client_list_t;

/**
 * @brief Create a new client
 *
 * @param fd fd of the client
 * @param username username of the client
 * @param password password of the client
 * @return client_t*
 */
client_t *create_client(int fd, char *username, char *password, char *uuid);

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

/**
 * @brief clear a client list
 *
 * @param list list to clear
 */
void clear_client_list(client_list_t *list);

/**
 * @brief free a client list
 *
 * @param list list to free
 */
void delete_client_list(client_list_t *list);

/**
 * @brief save a client list to file CLIENT_FILE
 *
 * @param list list to save
 */
void save_client_list(client_list_t *list);

/**
 * @brief load a client list from file CLIENT_FILE
 *
 * @param list list to store the loaded clients
 */
void load_client_list(client_list_t *list);

int create_directory_if_not_exists(const char *dir_path);

/**
 * @brief Add a new client to save
 *
 * @param client client to add to save
 */
void add_client_to_save(client_t *client);

/**
 * @brief get a client by name
 * @param list  list to search in
 * @param name name of the client
 * @return  client_t* corresponding client or NULL if not found
 */
client_t *get_client_by_name(client_list_t *list, char const *name);

/**
 * @brief duplicate a client
 *
 * @param client client to duplicate
 * @return client_t* duplicated client
 */
client_t *duplicate_client(client_t *client);


/**
 * @brief Create a new context
 *
 * @param thread team uuid
 * @param team team uuid
 * @param channel channel uuid
 * @return context_t*
 */
context_t *create_context(char const *thread, char const *team,
    char const *channel);

/**
 * @brief delete a context
 *
 * @param context context to delete
 */
void delete_context(context_t *context);

/**
 * @brief set a context to a client
 *
 * @param client client to set the context to
 * @param context context to set
 */
void set_context(client_t *client, context_t *context);

/**
 * @brief create and set a context to a client
 *
 * @param client client to add the context to
 * @param thread team uuid
 * @param team team uuid
 * @param channel channel uuid
 */
void add_context(client_t *client, char const *thread, char const *team,
    char const *channel);
#endif //PRIVATE_TEAMS_CLIENT_H

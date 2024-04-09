/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** messages
*/

#pragma once

#ifndef PRIVATE_TEAMS_MESSAGES_H
    #define PRIVATE_TEAMS_MESSAGES_H
    #include "uuid/uuid.h"
    #include <stdio.h>
    #define MAX_BODY_LENGTH 512
    #define MESSAGE_FILE ".save/messages.save"

typedef struct message_s {
    uuid_t sender_uuid;
    uuid_t receiver_uuid;
    time_t timestamp;
    char message[MAX_BODY_LENGTH + 1];
    struct message_s *next;
    struct message_s *prev;
} message_t;

typedef struct message_save_s {
    uuid_t sender_uuid;
    uuid_t receiver_uuid;
    time_t timestamp;
    char message[MAX_BODY_LENGTH + 1];
} message_save_t;

typedef struct message_list_s {
    message_t *head;
    message_t *tail;
    int size;
} message_list_t;

/**
 * @brief Create a new message
 *
 * @param sender_uuid uuid of the sender
 * @param receiver_uuid uuid of the receiver
 * @param message message
 * @return message_t*
 */
message_t *create_message(char *sender_uuid, char *receiver_uuid,
    char *message);

/**
 * @brief Create a new message from save of message
 *
 * @param save save of the message
 * @return message_list_t*
 */
message_t *create_message_from_save(message_save_t save);

/**
 * @brief Create a new message list
 *
 * @return message_list_t*
 */
message_list_t *create_message_list(void);

/**
 * @brief Delete a message list
 * @param list
 */
void delete_message_list(message_list_t *list);

/**
 * @brief clear message list
 * @param list to clear
 */
void clear_message_list(message_list_t *list);

/**
 * @brief Add a message to a message list
 *
 * @param list list to add to
 * @param message message to add
 */
void add_message(message_list_t *list, message_t *message);

/**
 * @brief Create a new message and add it to a message list
 *
 * @param list list to add to
 * @param sender_uuid uuid of the sender
 * @param receiver_uuid uuid of the receiver
 * @param message message
 */
void create_add_message(message_list_t *list, char *sender_uuid,
    char *receiver_uuid, char *message);

/**
 * @brief Get a message from a message list with a sender and receiver uuid
 * @param list
 * @param uuid_sender
 * @param uuid_receiver
 * @return message_t* corresponding message or NULL if not found
 */
message_t *get_message(message_list_t *list, uuid_t uuid_sender,
    uuid_t uuid_receiver);

/**
 * @brief save a message to a file
 * @param message
 * @param file
 */
void save_message(message_t *message, FILE *file);

/**
 * @brief save a message list to a file
 * @param list
 */
void save_message_list(message_list_t *list);

/**
 * @brief append a message to a file
 * @param message
 */
void append_message_to_save(message_t *message);

/**
 * @brief load messages from a file to a list
 * @param list
 */
void load_message(message_list_t *list, message_save_t save);

/**
 * @brief load messages from a file to a list
 * @param list
 */
void load_messages_to_list(message_list_t *list);
#endif //PRIVATE_TEAMS_MESSAGES_H

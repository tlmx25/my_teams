/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** reply
*/

#pragma once

#ifndef PRIVATE_TEAMS_REPLY_H
    #define PRIVATE_TEAMS_REPLY_H
    #include <uuid/uuid.h>
    #include <time.h>
    #define MAX_BODY_LENGTH_REPLY 4096
    #define SAVE_DIR ".save"
    #define REPLY_FILE ".save/reply.save"

typedef struct reply_s {
    uuid_t uuid;
    char *body;
    uuid_t owner_uuid;
    time_t timestamp;
    uuid_t thread_uuid;
    struct reply_s *next;
    struct reply_s *prev;
} reply_t;

typedef struct reply_list_s {
    reply_t *head;
    reply_t *tail;
    int size;
} reply_list_t;

typedef struct reply_save_s {
    uuid_t uuid;
    char body[MAX_BODY_LENGTH_REPLY + 1];
    uuid_t owner_uuid;
    time_t timestamp;
    uuid_t thread_uuid;
} reply_save_t;

/**
 * @brief Create a reply
 * @param body
 * @param author_uuid
 * @param thread_uuid
 * @return reply_t* the created reply
 */
reply_t *create_reply(char *body, uuid_t author_uuid, uuid_t thread_uuid);

/**
 * @brief Create a reply list
 * @return reply_list_t* the created reply list
 */
reply_list_t *create_reply_list(void);

/**
 * @brief Create a reply from save
 * @param save
 * @return reply_t* the created reply
 */
reply_t *create_reply_from_save(reply_save_t save);

/**
 * @brief Delete a reply
 * @param reply the reply to delete
 */
void delete_reply(reply_t *reply);

/**
 * @brief Delete a reply list
 * @param list the list to delete
 */
void delete_reply_list(reply_list_t *list);

/**
 * @brief Clear a reply list
 * @param list the list to clear
 */
void clear_reply_list(reply_list_t *list);

/**
 * @brief Add a reply to a reply list
 * @param list the list to add to
 * @param reply the reply to add
 */
void add_reply_to_list(reply_list_t *list, reply_t *reply);

/**
 * @brief Remove a reply from a reply list
 * @param list the list to remove from
 * @param reply the reply to remove
 */
void remove_reply_from_list(reply_list_t *list, reply_t *reply);

/**
 * @brief Remove a reply from a reply list by uuid
 * @param list the list to remove from
 * @param uuid the uuid of the reply to remove
 */
void remove_reply_by_uuid(reply_list_t *list, uuid_t uuid);

/**
 * @brief Get a reply from a reply list by uuid
 * @param list the list to get from
 * @param uuid the uuid of the reply to get
 * @return reply_t* the found reply
 */
reply_t *get_reply_by_uuid(reply_list_t *list, uuid_t uuid);

int create_directory_if_not_exists(char const *dir_path);

/**
 * @brief Save a reply list to file REPLY_FILE
 * @param list the list to save
 */
void save_reply_list(reply_list_t *list);

/**
 * @brief add a reply  to file REPLY_FILE
 * @param reply the reply to add
 */
void add_reply_to_save(reply_t *reply);

/**
 * @brief Load a reply list from file REPLY_FILE
 * @param list the list to store the loaded replies
 */
void load_reply_list(reply_list_t *list);
#endif //PRIVATE_TEAMS_REPLY_H

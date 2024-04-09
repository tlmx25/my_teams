/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** link_team_user
*/

#pragma once

#ifndef PRIVATE_TEAMS_LINK_TEAM_USER_H
    #define PRIVATE_TEAMS_LINK_TEAM_USER_H
    #include "uuid/uuid.h"
    #define LINK_TEAM_USER_FILE ".save/link_team_user.save"
    #define SAVE_DIR ".save"

typedef struct link_team_user_s {
    uuid_t team_uuid;
    uuid_t user_uuid;
    struct link_team_user_s *next;
    struct link_team_user_s *prev;
} link_team_user_t;

typedef struct link_team_user_save_s {
    uuid_t team_uuid;
    uuid_t user_uuid;
} link_team_user_save_t;

typedef struct link_team_user_list_s {
    link_team_user_t *head;
    link_team_user_t *tail;
    int size;
} link_team_user_list_t;

/**
 * @brief Create a link_team_user object
 * @param team_uuid
 * @param user_uuid
 * @return link_team_user_t*  the created link_team_user
 */
link_team_user_t *create_link(uuid_t team_uuid, uuid_t user_uuid);

/**
 * @brief Create a link_team_user list object
 * @return link_team_user_list_t*  the created link_team_user list
 */
link_team_user_list_t *create_link_list(void);

/**
 * @brief Delete a link_team_user object
 * @param link
 */
void delete_link(link_team_user_t *link);

/**
 * @brief Clear a link_team_user list
 * @param list the list to clear
 */
void clear_link_list(link_team_user_list_t *list);

/**
 * @brief Delete a link_team_user list
 * @param list the list to delete
 */
void delete_link_list(link_team_user_list_t *list);

/**
 * @brief Add a link_team_user to a link_team_user list
 * @param list the list to add to
 * @param link the link to add
 */
void add_link(link_team_user_list_t *list, link_team_user_t *link);

/**
 * @brief Create a link_team_user and add it to a link_team_user list
 * @param list the list to add to
 * @param team_uuid
 * @param user_uuid
 */
void create_link_and_add(link_team_user_list_t *list, uuid_t team_uuid,
    uuid_t user_uuid);

/**
 * @brief Remove a link_team_user from a link_team_user
 * @param list remove from
 * @param link to remove
 */
void remove_link(link_team_user_list_t *list, link_team_user_t *link);

/**
 * @brief Remove a link_team_user from a link_team_user list by uuid
 * @param list remove from
 * @param team_uuid
 * @param user_uuid
 */
void remove_link_by_uuid(link_team_user_list_t *list, uuid_t team_uuid,
    uuid_t user_uuid);

/**
 * @brief Remove a link_team_user from a link_team_user list by uuid
 * @param list remove from
 * @param team_uuid
 * @param user_uuid
 */
void remove_link_by_uuid_str(link_team_user_list_t *list,
    char const *team_uuid, char const *user_uuid);


/**
 * @brief Get a link_team_user from a link_team_user list by uuid
 * @param list
 * @param team_uuid
 * @param user_uuid
 * @return link_team_user_t* the link_team_user found or NULL
 */
link_team_user_t *get_link(link_team_user_list_t *list, uuid_t team_uuid,
    uuid_t user_uuid);

/**
 * @brief Get a link_team_user from a link_team_user list by uuid
 * @param list
 * @param team_uuid
 * @param user_uuid
 * @return link_team_user_t* the link_team_user found or NULL
 */
link_team_user_t *get_link_str(link_team_user_list_t *list, char *team_uuid,
    char *user_uuid);

int create_directory_if_not_exists(const char *dir_path);

/**
 * @brief Save a link_team_user_list to a file (LINK_TEAM_USER_FILE)
 * @param list the list to save
 */
void save_link_list(link_team_user_list_t *list);

/**
 * @brief Add a link_team_user to a save file
 * @param link the link to add
 */
void add_link_to_save(link_team_user_t *link);

/**
 * @brief Load a link_team_user from a save file (LINK_TEAM_USER_FILE)
 * @param save the save to load
 */
void load_link_list(link_team_user_list_t *list);
#endif //PRIVATE_TEAMS_LINK_TEAM_USER_H

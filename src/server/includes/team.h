/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** team
*/

#pragma once

#ifndef PRIVATE_TEAMS_THREAD_H
    #define PRIVATE_TEAMS_THREAD_H
    #include <uuid/uuid.h>
    #define TEAM_SAVE_FILE ".settings/.save/teams.save"
    #define SAVE_DIR ".settings/.save"
    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255

typedef struct team_s {
    uuid_t uuid;
    char *name;
    uuid_t owner_uuid;
    char *description;
    struct team_s *next;
    struct team_s *prev;
} team_t;

typedef struct team_save_s {
    uuid_t uuid;
    char name[MAX_NAME_LENGTH + 1];
    uuid_t owner_uuid;
    char description[MAX_DESCRIPTION_LENGTH + 1];
} team_save_t;

typedef struct team_list_s {
    team_t *head;
    team_t *tail;
    int size;
} team_list_t;

/**
 * @brief Create a team object
 * @param name
 * @param description
 * @param uuid
 * @param owner_uuid
 * @return team_t*  the created team
 */
team_t *create_team(char const *name, char const *description, uuid_t uuid,
    uuid_t owner_uuid);

/**
 * @brief Create a team list object
 * @return team_list_t*  the created team list

 */
team_list_t *create_team_list(void);

/**
 * @brief delete a team object
 * @param team to delete
 */
void delete_team(team_t *team);

/**
 * @brief clear a team list
 * @param list to clear
 */
void clear_team_list(team_list_t *list);

/**
 * @brief delete a team list
 * @param list to delete
 */
void delete_team_list(team_list_t *list);

/**
 * @brief add a team to a team list
 * @param list to add to
 * @param team to add
 */
void add_team_to_list(team_list_t *list, team_t *team);

/**
 * @brief remove a team from a team list
 * @param list to remove from
 * @param team to remove
 */
void remove_team_from_list(team_list_t *list, team_t *team);

/**
 * @brief remove a team from a team list by uuid
 * @param list to remove from
 * @param uuid to remove
 */
void remove_team_by_uuid(team_list_t *list, uuid_t uuid);

/**
 * @brief get a team from a team list by uuid
 * @param list to get from
 * @param uuid to get
 * @return team_t*  the team
 */
team_t *get_team_by_uuid(team_list_t *list, uuid_t uuid);

/**
 * @brief get a team from a team list by name
 * @param list to get from
 * @param name to get
 * @return team_t*  the team
 */
team_t *get_team_by_name(team_list_t *list, char const *name);

int create_directory_if_not_exists(const char *dir_path);

/**
 * @brief save a team list to a file(TEAM_SAVE_FILE)
 * @param list to save
 */
void save_teams_list(team_list_t *list);

/**
 * @brief load a team list from a file(TEAM_SAVE_FILE)
 * @param list to load
 */
void load_team_list(team_list_t *list);

/**
 * @brief add a team to a file(TEAM_SAVE_FILE)
 * @param team to save
 */
void add_team_to_save(team_t *team);

#endif //PRIVATE_TEAMS_THREAD_H

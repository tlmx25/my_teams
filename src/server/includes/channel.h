/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** channel
*/

#pragma once

#ifndef PRIVATE_TEAMS_CHANNEL_H
    #define PRIVATE_TEAMS_CHANNEL_H
    #include <uuid/uuid.h>
    #include <time.h>
    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define SAVE_DIR ".save"
    #define CHANNEL_FILE ".save/channel.save"

typedef struct channel_s {
    uuid_t uuid;
    char *name;
    char *description;
    uuid_t team_uuid;
    uuid_t creator_uuid;
    time_t created_at;
    struct channel_s *next;
    struct channel_s *prev;
} channel_t;

typedef struct channel_list_s {
    channel_t *head;
    channel_t *tail;
    int size;
} channel_list_t;

typedef struct channel_save_s {
    uuid_t uuid;
    char name[MAX_NAME_LENGTH + 1];
    char description[MAX_DESCRIPTION_LENGTH + 1];
    uuid_t team_uuid;
    uuid_t creator_uuid;
    time_t created_at;
} channel_save_t;

/**
 * @brief create a channel
 * @param name
 * @param description
 * @param team_uuid
 * @param creator_uuid
 * @return channel_t* channel created
 */
channel_t *create_channel(char const *name, char const *description,
    uuid_t team_uuid, uuid_t creator_uuid);

/*
 * @brief create a channel list
 * @return channel_list_t* channel list created
 */
channel_list_t *create_channel_list(void);

/**
 * @brief delete a channel
 * @param channel to delete
 */
void delete_channel(channel_t *channel);

/**
 * @brief clear a channel list(reset)
 * @param list to clear
 */
void clear_channel_list(channel_list_t *list);

/**
 * @brief delete a channel list
 * @param list to delete
 */
void delete_channel_list(channel_list_t *list);

/**
 * @brief add a channel to a channel list
 * @param list
 * @param channel
 */
void add_channel_to_list(channel_list_t *list, channel_t *channel);

/**
 * @brief remove a channel from a channel list
 * @param list
 * @param channel
 */
void remove_channel_from_list(channel_list_t *list, channel_t *channel);

/**
 * @brief remove a channel from a channel list by uuid
 * @param list
 * @param uuid
 */
void remove_channel_by_uuid(channel_list_t *list, uuid_t uuid);

/**
 * @brief get a channel by uuid
 * @param list
 * @param uuid
 * @return channel_t* channel found
 */
channel_t *get_channel_by_uuid(channel_list_t *list, uuid_t uuid);

/**
 * @brief get a channel by name
 * @param list
 * @param name
 * @return channel_t* channel found
 */
channel_t *get_channel_by_name(channel_list_t *list, char const *name);

int create_directory_if_not_exists(const char *dir_path);

/**
 * @brief load channel list from file
 * @param list list to save
 */
void save_channel_list(channel_list_t *list);

/**
 * @brief add channel  to file
 * @param channel to save
 */
void add_channel_to_save(channel_t *channel);

/**
 * @brief load channel list from file
 * @param list list to store the loaded channels
 */
void load_channel_list(channel_list_t *list);
#endif //PRIVATE_TEAMS_CHANNEL_H

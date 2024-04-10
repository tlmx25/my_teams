/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** thread_teams
*/

#pragma once

#ifndef PRIVATE_TEAMS_THREAD_TEAMS_H
    #define PRIVATE_TEAMS_THREAD_TEAMS_H
    #include <uuid/uuid.h>
    #include <time.h>
    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define SAVE_DIR ".save"
    #define THREAD_SAVE_FILE ".save/thread.save"

typedef struct thread_s {
    uuid_t uuid;
    char *title;
    char *message;
    uuid_t creator_uuid;
    uuid_t channel_uuid;
    time_t created_at;
    struct thread_s *next;
    struct thread_s *prev;
} thread_t;

typedef struct thread_list_s {
    thread_t *head;
    thread_t *tail;
    int size;
} thread_list_t;

typedef struct thread_save_s {
    uuid_t uuid;
    char title[MAX_NAME_LENGTH + 1];
    char message[MAX_DESCRIPTION_LENGTH + 1];
    uuid_t creator_uuid;
    uuid_t channel_uuid;
    time_t created_at;
} thread_save_t;

/**
 * @brief Create a thread
 * @param title
 * @param message
 * @param creator_uuid
 * @param channel_uuid
 * @return thread_t* the created thread
 */
thread_t *create_thread(char const *title, char const *message,
                        uuid_t creator_uuid, uuid_t channel_uuid);

/**
 * @brief Create a thread list
 * @return thread_list_t* the created thread list
 */
thread_list_t *create_thread_list(void);

/**
 * @brief Create a thread from save
 * @param save
 * @return thread_t* the created thread
 */
thread_t *create_thread_from_save(thread_save_t save);

/**
 * @brief Delete a thread
 * @param thread
 */
void delete_thread(thread_t *thread);

/**
 * @brief Clear a thread list
 * @param list the list to clear
 */
void clear_thread_list(thread_list_t *list);

/**
 * @brief Delete a thread list
 * @param list the list to delete
 */
void delete_thread_list(thread_list_t *list);

/**
 * @brief Add a thread to a thread list
 * @param list the list to add to
 * @param thread the thread to add
 */
void add_thread_to_list(thread_list_t *list, thread_t *thread);

/**
 * @brief remove a thread from a thread list
 * @param list the list to remove from
 * @param thread the thread to remove
 */
void remove_thread_from_list(thread_list_t *list, thread_t *thread);

/**
 * @brief remove a thread from a thread list by uuid
 * @param list the list to remove from
 * @param uuid the uuid of the thread to remove
 */
void remove_thread_by_uuid(thread_list_t *list, uuid_t uuid);

/**
 * @brief get a thread by uuid
 * @param list the list to search in
 * @param uuid the uuid of the thread to get
 * @return thread_t* the thread found or NULL if not found
 */
thread_t *get_thread_by_uuid(thread_list_t *list, uuid_t uuid);

/**
 * @brief get a thread by title
 * @param list the list to search in
 * @param title the title of the thread to get
 * @return thread_t* the thread found or NULL if not found
 */
thread_t *get_thread_by_title(thread_list_t *list, char const *title);

int create_directory_if_not_exists(char const *dir_path);

/**
 * @brief save thread list to file (THREAD_SAVE_FILE)
 * @param list list to save
 */
void save_thread_list(thread_list_t *list);

/**
 * @brief add a thread to save file (THREAD_SAVE_FILE)
 * @param thread the thread to add to save
 */
void add_thread_to_save(thread_t *thread);

/**
 * @brief load thread list from file (THREAD_SAVE_FILE)
 * @param list list to store the loaded threads
 */
void load_thread_list(thread_list_t *list);
#endif //PRIVATE_TEAMS_THREAD_TEAMS_H

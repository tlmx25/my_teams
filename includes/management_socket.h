/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** management_socket
*/

#pragma once

#ifndef PRIVATE_TEAMS_MANAGEMENT_SOCKET_H
    #define PRIVATE_TEAMS_MANAGEMENT_SOCKET_H
    #define ERROR 84
    #include <unistd.h>
    #include <sys/time.h>
    #include <sys/types.h>

typedef struct select_s {
    fd_set readfds;
    fd_set writefds;
    char use_timeout;
    int max_fd;
    struct timeval timeout;
} select_t;

/**
 * @brief create new select struct
 *
 * @return select_t*
 */
select_t *init_select(void);

/**
 * @brief add a fd to the select struct
 *
 * @param fd fd to add
 * @param select select struct
 */
void add_to_select(int fd, select_t *select);

/**
 * @brief reset the select struct
 *
 * @param select select struct to reset
 */
void reset_select(select_t *select);

/**
 * @brief execute the select
 *
 * @param select_config select struct
 * @return int 0 if success, 84 if error
 */
int exec_select(select_t *select_config);
#endif //PRIVATE_TEAMS_MANAGEMENT_SOCKET_H

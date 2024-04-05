/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** socket
*/

#pragma once

#ifndef PRIVATE_TEAMS_SOCKET_H
    #define PRIVATE_TEAMS_SOCKET_H
    #include "request.h"

/**
 * @brief Write a request to a socket
 * @param fd fd of the socket write to
 * @param req request to writee
 *
 * @return int 0 if success, 84(ERROR) if error
 */
int write_socket(int fd, request_t *req);
/**
 * @brief Read a request from a socket
 * @param fd fd of the socket read from
 * @param req request to read
 */
request_t *read_socket(int fd);

/**
 * @brief Create a socket
 * @param port port of the socket
 *
 * @return int fd of the socket or -1 if error
 */
int create_socket(int port);
#endif //PRIVATE_TEAMS_SOCKET_H

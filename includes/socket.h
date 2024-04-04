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
 */
int write_socket(int fd, request_t *req);
/**
 * @brief Read a request from a socket
 * @param fd fd of the socket read from
 * @param req request to read
 */
request_t *read_socket(int fd);
#endif //PRIVATE_TEAMS_SOCKET_H

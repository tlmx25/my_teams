/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** write_socket
*/

#include <stdlib.h>
#include <unistd.h>
#include "request.h"
#include "socket.h"


/**
 * @brief Write a request to a socket
 * @param fd fd of the socket write to
 * @param req request to write
 */

int write_socket(int fd, request_t *req)
{
    if (write(fd, req, sizeof(request_t)) == -1)
        return ERROR;
    return 0;
}

/**
 * @brief Read a request from a socket
 * @param fd fd of the socket read from
 * @param req request to read
 */
request_t *read_socket(int fd)
{
    request_t *req = malloc(sizeof(request_t));

    if (req == NULL)
        return NULL;
    if (read(fd, req, sizeof(request_t)) == 0) {
        free(req);
        return NULL;
    }
    return req;
}

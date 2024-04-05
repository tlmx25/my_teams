/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** write_socket
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
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

static int bind_listen(int sockfd, struct sockaddr_in *server_addr)
{
    if (bind(sockfd, (struct sockaddr *)server_addr,
    sizeof(struct sockaddr_in)) == -1) {
        free(server_addr);
        return -1;
    }
    if (listen(sockfd, 10) == -1) {
        perror("Erreur lors de l'association du port");
        free(server_addr);
        return -1;
    }
    return sockfd;
}

int create_socket(int port)
{
    int sockfd;
    struct sockaddr_in *server_addr = calloc(sizeof(struct sockaddr_in), 1);

    if (server_addr == NULL)
        return -1;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        return -1;
    server_addr->sin_family = AF_INET;
    server_addr->sin_port = htons(port);
    server_addr->sin_addr.s_addr = INADDR_ANY;
    if (bind_listen(sockfd, server_addr) == -1)
        return -1;
    free(server_addr);
    return sockfd;
}

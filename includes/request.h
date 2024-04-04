/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** request
*/

#pragma once

#ifndef PRIVATE_TEAMS_REQUEST_H
    #define PRIVATE_TEAMS_REQUEST_H
    #define ERROR 84
    #include "uuid/uuid.h"

/**
 * @brief Request struct
 *
 * id: id of the request
 * code: code of the request
 * uuid: uuid of the request
 * body: body of the request
 */
typedef struct request_s {
    int id;
    int code;
    uuid_t uuid;
    char body[4096];
} request_t;


typedef struct linked_request_s {
    request_t *request;
    struct linked_request_s *next;
    struct linked_request_s *prev;
} linked_request_t;

typedef struct request_list_s {
    linked_request_t *head;
    linked_request_t *tail;
} request_list_t;

/**
 * @brief Create a new request
 *
 * @param id id of the request
 * @param code code of the request
 * @param body body of the request
 * @return request_t*
 */
request_t *create_request(int id, int code, char *body);

/**
 * @brief Create a new request list
 *
 * @return request_list_t*
 */
request_list_t *create_request_list(void);

/**
 * @brief Add a request to a request list
 *
 * @param list list to add to
 * @param request request to add
 */
void add_request_to_list(request_list_t *list, request_t *request);

/**
 * @brief Remove a request from a request list by uuid
 *
 * @param list list to remove from
 * @param uuid uuid of the request to remove
 */
void remove_request_from_list(request_list_t *list, uuid_t uuid);
#endif //PRIVATE_TEAMS_REQUEST_H

/**
* @brief free a request
*/
void free_request(request_t *request);

/**
 * @brief free a request list
 *
 * @param list list to free
 */
void free_request_list(request_list_t *list);

/**
* @brief free a linked request
 *
 * @param linked_request linked request to free
 */
void free_linked_request(linked_request_t *linked_request);

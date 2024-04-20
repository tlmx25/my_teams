/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** request
*/

#include <stdlib.h>
#include "my.h"
#include "request.h"
#include "msecurity.h"

request_t *create_request(action_t action, int code, char *body)
{
    request_t *req = calloc(sizeof(request_t), 1);
    char *encrypted_body;

    if (req == NULL)
        return NULL;
    req->action = action;
    req->code = code;
    uuid_generate(req->uuid);
    if (body != NULL) {
        my_strncpy(req->body, body, 4095);
        encrypted_body = mcrypt_string(req->body, MCRYPT_KEY);
        if (encrypted_body != NULL) {
            my_strncpy(req->body, encrypted_body, 4095);
            req->hash = mhash(req->body);
            free(encrypted_body);
        }
    }
    return req;
}

request_list_t *create_request_list(void)
{
    request_list_t *list = calloc(sizeof(request_list_t), 1);

    if (list == NULL)
        return NULL;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

static linked_request_t *create_linked_request(request_t *req)
{
    linked_request_t *linked_req = calloc(sizeof(linked_request_t), 1);

    if (linked_req == NULL)
        return NULL;
    linked_req->request = req;
    linked_req->next = NULL;
    linked_req->prev = NULL;
    return linked_req;
}

void add_request_to_list(request_list_t *list, request_t *req)
{
    linked_request_t *linked_req = create_linked_request(req);

    if (list->head == NULL) {
        list->head = linked_req;
        list->tail = linked_req;
    } else {
        list->tail->next = linked_req;
        linked_req->prev = list->tail;
        list->tail = linked_req;
    }
}

void remove_request_from_list(request_list_t *list, uuid_t uuid)
{
    linked_request_t *tmp = list->head;

    while (tmp != NULL && uuid_compare(tmp->request->uuid, uuid) != 0)
        tmp = tmp->next;
    if (tmp == NULL)
        return;
    if (tmp->prev != NULL)
        tmp->prev->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;
    if (tmp == list->head)
        list->head = tmp->next;
    if (tmp == list->tail)
        list->tail = tmp->prev;
    free_linked_request(tmp);
}

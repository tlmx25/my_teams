/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** delete_request
*/

#include <stdlib.h>
#include "request.h"

void free_request(request_t *req)
{
    if (req == NULL)
        return;
    free(req);
}

void free_request_list(request_list_t *list)
{
    linked_request_t *tmp;
    linked_request_t *next = NULL;

    if (list == NULL)
            return;
    tmp = list->head;
    while (tmp) {
        next = tmp->next;
        free_request(tmp->request);
        free(tmp);
        tmp = next;
    }
    free(list);
}

void free_linked_request(linked_request_t *linked_req)
{
    if (linked_req == NULL)
        return;
    free_request(linked_req->request);
    free(linked_req);
}

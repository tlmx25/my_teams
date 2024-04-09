/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** duplicate_request
*/

#include <stdlib.h>
#include "request.h"
#include "my.h"

request_t *duplicate_request(request_t *request)
{
    request_t *new_request = calloc(sizeof(request_t), 1);

    if (new_request == NULL)
        return NULL;
    uuid_copy(new_request->uuid, request->uuid);
    new_request->action = request->action;
    new_request->code = request->code;
    my_strncpy(new_request->body, request->body, 4095);
    return new_request;
}

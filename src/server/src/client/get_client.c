/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** get_client
*/

#include "client.h"
#include "my.h"

client_t *get_client_by_fd(client_list_t *list, int fd)
{
    client_t *tmp = list->head;

    for (; tmp && tmp->fd != fd; tmp = tmp->next);
    return tmp;
}

client_t *get_client_by_uuid(client_list_t *list, uuid_t uuid)
{
    client_t *tmp = list->head;

    for (; tmp && uuid_compare(tmp->uuid, uuid) != 0; tmp = tmp->next);
    return tmp;
}

client_t *get_client_by_name(client_list_t *list, char const *name)
{
    client_t *tmp = list->head;

    for (; tmp && my_strcmp(tmp->username, name) != 0; tmp = tmp->next);
    return tmp;
}

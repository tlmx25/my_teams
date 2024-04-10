/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** get_channel
*/

#include "channel.h"
#include "my.h"

channel_t *get_channel_by_uuid(channel_list_t *list, uuid_t uuid)
{
    channel_t *tmp;

    if (list == NULL)
        return NULL;
    tmp = list->head;
    for (; tmp; tmp = tmp->next) {
        if (uuid_compare(tmp->uuid, uuid) == 0)
            return tmp;
    }
    return NULL;
}

channel_t *get_channel_by_name(channel_list_t *list, char const *name)
{
    channel_t *tmp;

    if (list == NULL)
        return NULL;
    tmp = list->head;
    for (; tmp; tmp = tmp->next) {
        if (my_strcmp(tmp->name, name) == 0)
            return tmp;
    }
    return NULL;
}

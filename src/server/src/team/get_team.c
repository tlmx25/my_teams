/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** get_team
*/

#include <string.h>
#include "server.h"
#include "team.h"

team_t *get_team_by_uuid(team_list_t *list, uuid_t uuid)
{
    team_t *tmp;

    if (list == NULL)
        return NULL;
    for (tmp = list->head; tmp; tmp = tmp->next) {
        if (uuid_compare(tmp->uuid, uuid) == 0)
            return tmp;
    }
    return NULL;
}

team_t *get_team_by_name(team_list_t *list, char const *name)
{
    team_t *tmp;

    if (list == NULL)
        return NULL;
    for (tmp = list->head; tmp; tmp = tmp->next) {
        if (strcmp(tmp->name, name) == 0)
            return tmp;
    }
    return NULL;
}

team_t *get_team_by_channel(team_list_t *list, channel_t *channel)
{
    team_t *tmp;

    if (list == NULL)
        return NULL;
    for (tmp = list->head; tmp; tmp = tmp->next) {
        if (uuid_compare(tmp->uuid, channel->team_uuid) == 0)
            return tmp;
    }
    return NULL;
}

team_t *get_team_by_thread(server_t *server, thread_t *thread)
{
    team_t *tmp;
    channel_t *channel;
    team_list_t *list = server->teams;

    if (list == NULL)
        return NULL;
    channel = get_channel_by_uuid(server->channels, thread->channel_uuid);
    if (channel == NULL)
        return NULL;
    for (tmp = list->head; tmp; tmp = tmp->next) {
        if (uuid_compare(tmp->uuid, channel->team_uuid) == 0)
            return tmp;
    }
    return NULL;
}

team_t *get_team_by_reply(server_t *server, reply_t *reply)
{
    team_t *tmp;
    thread_t *thread;
    channel_t *channel;
    team_list_t *list = server->teams;

    if (list == NULL)
        return NULL;
    thread = get_thread_by_uuid(server->threads, reply->thread_uuid);
    if (thread == NULL)
        return NULL;
    channel = get_channel_by_uuid(server->channels, thread->channel_uuid);
    if (channel == NULL)
        return NULL;
    for (tmp = list->head; tmp; tmp = tmp->next) {
        if (uuid_compare(tmp->uuid, channel->team_uuid) == 0)
            return tmp;
    }
    return NULL;
}

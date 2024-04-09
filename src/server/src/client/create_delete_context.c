/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** create_delete_context
*/

#include <stdlib.h>
#include "client.h"

context_t *create_context(char const *thread, char const *team,
    char const *channel)
{
    context_t *context = malloc(sizeof(context_t));

    if (context == NULL)
        return NULL;
    if (thread) {
        uuid_parse(thread, context->uuid_thread);
        context->nb_uuid = 1;
    }
    if (team) {
        uuid_parse(team, context->uuid_team);
        context->nb_uuid = 2;
    }
    if (channel) {
        uuid_parse(channel, context->uuid_channel);
        context->nb_uuid = 3;
    }
    return context;
}

void delete_context(context_t *context)
{
    if (context == NULL)
        return;
    free(context);
}

void set_context(client_t *client, context_t *context)
{
    if (client == NULL || context == NULL)
        return;
    client->context = context;
}

void add_context(client_t *client, char const *thread, char const *team,
    char const *channel)
{
    context_t *context = create_context(thread, team, channel);

    if (context == NULL)
        return;
    set_context(client, context);
}

/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** load_reply
*/

#include <stdlib.h>
#include <stdio.h>
#include "reply.h"

static reply_t *load_reply(reply_save_t save)
{
    reply_t *reply = create_reply_from_save(save);

    return reply;
}

void load_reply_list(reply_list_t *list)
{
    FILE *file = fopen(REPLY_FILE, "r");
    reply_save_t save;
    reply_t *reply;

    if (file == NULL)
        return;
    while (fread(&save, sizeof(reply_save_t), 1, file) == 1) {
        reply = load_reply(save);
        if (reply)
            add_reply_to_list(list, reply);
    }
    fclose(file);
}

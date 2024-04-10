/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** reply
*/

#pragma once

#ifndef PRIVATE_TEAMS_REPLY_H
    #define PRIVATE_TEAMS_REPLY_H
    #include <uuid/uuid.h>
    #include <time.h>

typedef struct reply_s {
    uuid_t uuid;
    char *body;
    uuid_t owner_uuid;
    time_t timestamp;
    uuid_t thread_uuid;
    struct reply_s *next;
    struct reply_s *prev;
} reply_t;

#endif //PRIVATE_TEAMS_REPLY_H

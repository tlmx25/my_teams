/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** command_client
*/

#pragma once

#ifndef PRIVATE_TEAMS_COMMAND_CLIENT_H
    #define PRIVATE_TEAMS_COMMAND_CLIENT_H
    #include "client.h"
    #include "request.h"

/**
 * @brief command logged_in for event
 * @param client
 * @param request
 */
void logged_in_command(UNUSED client_t *client, request_t *request);

#endif //PRIVATE_TEAMS_COMMAND_CLIENT_H

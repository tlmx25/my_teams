/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** command_server
*/

#pragma once

#ifndef PRIVATE_TEAMS_COMMAND_SERVER_H
    #define PRIVATE_TEAMS_COMMAND_SERVER_H
    #include "server.h"

void login_command(server_t *server, client_t *client, char **command);

#endif //PRIVATE_TEAMS_COMMAND_SERVER_H

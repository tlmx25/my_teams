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

void help_command(server_t *server, client_t *client, char **command);
void login_command(server_t *server, client_t *client, char **command);
void logout_command(server_t *server, client_t *client, char **command);
void users_command(server_t *server, client_t *client, char **command);
void user_command(server_t *server, client_t *client, char **command);
void send_command(server_t *server, client_t *client, char **command);
void info_command(server_t *server, client_t *client, char **command);
void messages_command(server_t *server, client_t *client, char **command);

#endif //PRIVATE_TEAMS_COMMAND_SERVER_H

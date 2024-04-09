/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** command_client
*/

#pragma once

#ifndef PRIVATE_TEAMS_COMMAND_CLIENT_H
    #define PRIVATE_TEAMS_COMMAND_CLIENT_H
    #include "client_cli.h"
    #include "request.h"

/**
 * @brief command logged_in for event
 * @param client
 * @param request
 */
void logged_in_command(UNUSED client_t *client, request_t *request);
void logged_out_command(UNUSED client_t *client, request_t *request);
void print_error_command(UNUSED client_t *client, request_t *request);
void print_users_command(UNUSED client_t *client, request_t *request);
void print_teams_command(UNUSED client_t *client, request_t *request);
void print_channels_command(UNUSED client_t *client, request_t *request);
void print_threads_command(UNUSED client_t *client, request_t *request);
void print_replies_command(UNUSED client_t *client, request_t *request);
void print_prv_msg_command(UNUSED client_t *client, request_t *request);
void prv_msg_rcvd_command(UNUSED client_t *client, request_t *request);
void thread_reply_rcvd_command(UNUSED client_t *client, request_t *request);
void error_team_command(UNUSED client_t *client, request_t *request);
void error_channel_command(UNUSED client_t *client, request_t *request);
void error_thread_command(UNUSED client_t *client, request_t *request);
void error_user_command(UNUSED client_t *client, request_t *request);
void error_unauthorized_command(UNUSED client_t *client, request_t *request);
void error_existing_client_command(UNUSED client_t *client,
    request_t *request);
void creation_team_command(UNUSED client_t *client, request_t *request);
void creation_channel_command(UNUSED client_t *client, request_t *request);
void creation_thread_command(UNUSED client_t *client, request_t *request);
void nt_print_user_command(UNUSED client_t *client, request_t *request);
void nt_print_team_command(UNUSED client_t *client, request_t *request);
void nt_print_channel_command(UNUSED client_t *client, request_t *request);
void nt_print_thread_command(UNUSED client_t *client, request_t *request);
void nt_team_created_command(UNUSED client_t *client, request_t *request);
void nt_channel_created_command(UNUSED client_t *client, request_t *request);
void nt_thread_created_command(UNUSED client_t *client, request_t *request);
void nt_print_reply_command(UNUSED client_t *client, request_t *request);
void nt_print_sub_command(UNUSED client_t *client, request_t *request);
void nt_print_unsub_command(UNUSED client_t *client, request_t *request);
#endif //PRIVATE_TEAMS_COMMAND_CLIENT_H

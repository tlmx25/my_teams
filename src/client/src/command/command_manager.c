/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** command_manger
*/

#include "client_cli.h"
#include "command_client.h"

static const command_t COMMANDS[] = {
    {LOGGED_IN, &logged_in_command},
    {LOGGED_OUT, &logged_out_command},
    {NT_LOGGED_OUT, &logged_out_command},
    {MSG_PRV_RCVD, &prv_msg_rcvd_command},
    {MSG_THREAD_REPLY, &thread_reply_rcvd_command},
    {TEAM_CREATED, &creation_team_command},
    {CHANNEL_CREATED, &creation_channel_command},
    {THREAD_CREATED, &creation_thread_command},
    {PRINT_USERS, &print_users_command},
    {PRINT_TEAMS, &print_teams_command},
    {PRINT_CHANNELS, &print_channels_command},
    {PRINT_THREADS, &print_threads_command},
    {PRINT_REPLIES, &print_replies_command},
    {PRINT_PRV_MSG, &print_prv_msg_command},
    {UNKNOWN_TEAM, &error_team_command},
    {UNKNOWN_CHANNEL, &error_channel_command},
    {UNKNOWN_THREAD, &error_thread_command},
    {UNKNOWN_USER, &error_user_command},
    {UNAUTHORIZED, &error_unauthorized_command},
    {ERROR_ALREADY_EXISTS, &print_error_existing_client_command},
    {NT_PRINT_USER, &nt_print_user_command},
    {NT_PRINT_TEAM, &nt_print_team_command},
    {NT_PRINT_CHANNEL, &nt_print_channel_command},
    {NT_PRINT_THREAD, &nt_print_thread_command},
    {NT_TEAM_CREATED, &nt_team_created_command},
    {NT_CHANNEL_CREATED, &nt_channel_created_command},
    {NT_THREAD_CREATED, &nt_thread_created_command},
    {NT_PRINT_REPLY, &nt_print_reply_command},
    {NT_PRINT_SUB, &nt_print_sub_command},
    {NT_PRINT_UNSUB, &nt_print_unsub_command},
    {PRINT_ERROR, &print_error_command},
    {NONE, NULL}
};

void command_manager(client_t *client, request_t *request)
{
    if (request->action == NONE)
        return;
    for (int i = 0; COMMANDS[i].action != NONE; i++) {
        if (COMMANDS[i].action == request->action) {
            COMMANDS[i].func(client, request);
            return;
        }
    }
}

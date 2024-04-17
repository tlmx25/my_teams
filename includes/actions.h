/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** actions
*/

#pragma once

#ifndef PRIVATE_TEAMS_ACTIONS_H
    #define PRIVATE_TEAMS_ACTIONS_H

typedef enum action_e {
    LOGGED_IN, //client_event_logged_in
    LOGGED_OUT, //client_event_logged_out
    MSG_PRV_RCVD, //client_event_private_message_received
    MSG_THREAD_REPLY, //client_event_thread_reply_received
    TEAM_CREATED, //client_event_team_created
    CHANNEL_CREATED, //client_event_channel_created
    THREAD_CREATED, //client_event_thread_created
    PRINT_USERS, //client_print_users
    PRINT_TEAMS, //client_print_teams
    PRINT_CHANNELS, //client_team_print_channels
    PRINT_THREADS, //client_channel_print_threads
    PRINT_REPLIES, //client_thread_print_replies
    PRINT_PRV_MSG, //client_private_message_print_messages
    UNKNOWN_TEAM, //client_error_unknown_team
    UNKNOWN_CHANNEL, //client_error_unknown_channel
    UNKNOWN_THREAD, //client_error_unknown_thread
    UNKNOWN_USER, //client_error_unknown_user
    UNAUTHORIZED, //client_error_unauthorized
    ERROR_ALREADY_EXISTS, //client_error_already_exist
    NT_PRINT_USER, //client_print_user
    NT_PRINT_TEAM, //client_print_team
    NT_PRINT_CHANNEL, //client_print_channel
    NT_PRINT_THREAD, //client_print_thread
    NT_TEAM_CREATED, //client_print_team_created
    NT_CHANNEL_CREATED, //client_print_channel_created
    NT_THREAD_CREATED, //client_print_thread_created
    NT_PRINT_REPLY, //client_print_reply_created
    NT_PRINT_SUB, //client_print_subscribed
    NT_PRINT_UNSUB, //client_print_unsubscribed
    PRINT_ERROR,
    NT_LOGGED_OUT,
    NONE,
} action_t;

#endif //PRIVATE_TEAMS_ACTIONS_H

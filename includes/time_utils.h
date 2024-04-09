/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** time_utils
*/

#pragma once

#ifndef PRIVATE_TEAMS_TIME_UTILS_H
    #define PRIVATE_TEAMS_TIME_UTILS_H
    #include <time.h>


char *timestamp_to_str(time_t timestamp);
time_t str_to_timestamp(char *str);
#endif //PRIVATE_TEAMS_TIME_UTILS_H

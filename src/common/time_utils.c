/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** time_utils
*/

#include <stdlib.h>
#include <stdio.h>
#include "time_utils.h"

char *timestamp_to_str(time_t timestamp)
{
    struct tm *tm;
    char *buffer = malloc(sizeof(char) * 26);

    if (buffer == NULL)
        return NULL;
    tm = localtime(&timestamp);
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm);
    return buffer;
}

time_t str_to_timestamp(char *str)
{
    struct tm tm;

    strptime(str, "%Y-%m-%d %H:%M:%S", &tm);
    return mktime(&tm);
}

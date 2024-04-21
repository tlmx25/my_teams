/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** msecurity.h
*/

#pragma once

#include <stdint.h>

#define MCRYPT_KEY ".settings/.mkey"

char *mhash(char *message);
char *muncrypt_string(const char *str, const char *key);
char *mcrypt_string(const char *str, const char *key);

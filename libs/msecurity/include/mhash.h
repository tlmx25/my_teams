/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** sha1.h
*/

#pragma once

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define A_SHA1 0x67452301
#define B_SHA1 0xefcdab89
#define C_SHA1 0x98badcfe
#define D_SHA1 0x10325476
#define E_SHA1 0xc3d2e1f0

typedef struct sha1_s {
    uint32_t a;
    uint32_t b;
    uint32_t c;
    uint32_t d;
    uint32_t e;
} sha1_t;

uint32_t left_rotate(uint32_t value, int shift);
uint32_t k_sha1(uint32_t turn);
uint32_t f_sha1(uint32_t turn, sha1_t *sha1);
char *get_hash(sha1_t *sha1);
void add_value(sha1_t *sha1, sha1_t *temp_sha1);

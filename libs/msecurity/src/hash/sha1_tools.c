/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** sha1_tools.c
*/

#include "mhash.h"

void add_value(sha1_t *sha1, sha1_t *temp_sha1)
{
    sha1->a += temp_sha1->a;
    sha1->b += temp_sha1->b;
    sha1->c += temp_sha1->c;
    sha1->d += temp_sha1->d;
    sha1->e += temp_sha1->e;
}

char *get_hash(sha1_t *sha1)
{
    char *hash = malloc(41);

    sprintf(hash, "%08x%08x%08x%08x%08x", sha1->a, sha1->b, sha1->c,
        sha1->d, sha1->e);
    return hash;
}

uint32_t left_rotate(uint32_t value, int shift)
{
    uint32_t res = (value << shift);

    res = res | (value >> (32 - shift));
    return res;
}

uint32_t k_sha1(uint32_t turn)
{
    switch (turn) {
        case 0 ... 19:
            return 0x5A827999;
        case 20 ... 39:
            return 0x6ED9EBA1;
        case 40 ... 59:
            return 0x8F1BBCDC;
        default:
            return 0xCA62C1D6;
    }
}

uint32_t f_sha1(uint32_t turn, sha1_t *sha1)
{
    uint32_t res;

    switch (turn) {
        case 0 ... 19:
            res = (sha1->b & sha1->c);
            res = res | ((~sha1->b) & sha1->d);
            return res;
        case 20 ... 39:
            res = sha1->b ^ sha1->c ^ sha1->d;
            return res;
        case 40 ... 59:
            res = (sha1->b & sha1->c);
            res = res | (sha1->b & sha1->d);
            res = res | (sha1->c & sha1->d);
            return res;
        default:
            res = sha1->b ^ sha1->c ^ sha1->d;
            return res;
    }
}

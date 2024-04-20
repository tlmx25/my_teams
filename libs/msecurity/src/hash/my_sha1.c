/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** my_sha1.c
*/

#include "mhash.h"

void process_loop(const uint32_t *w, uint32_t *temp, sha1_t *sha1, int turn)
{
    *temp = left_rotate(sha1->a, 5) + f_sha1(turn, sha1) + sha1->e + w[turn] +
            k_sha1(turn);
    sha1->e = sha1->d;
    sha1->d = sha1->c;
    sha1->c = left_rotate(sha1->b, 30);
    sha1->b = sha1->a;
    sha1->a = *temp;
}

void process_block(uint32_t block[16], sha1_t *sha1)
{
    int turn;
    uint32_t w[80];
    uint32_t temp;
    sha1_t temp_sha1 = {0, 0, 0, 0, 0};

    for (turn = 0; turn < 80; turn++) {
        if (turn < 16)
            w[turn] = block[turn];
        else {
            w[turn] = left_rotate(w[turn - 3] ^ w[turn - 8] ^ w[turn - 14] ^
                w[turn - 16], 1);
        }
    }
    add_value(&temp_sha1, sha1);
    for (turn = 0; turn < 80; turn++)
        process_loop(w, &temp, &temp_sha1, turn);
    add_value(sha1, &temp_sha1);
}

void process_message(uint8_t *message, size_t length, sha1_t *sha1)
{
    size_t num_blocks = length / 64;
    uint32_t *blocks = (uint32_t *)message;

    for (size_t i = 0; i < num_blocks; i++)
        process_block(blocks + i * 16, sha1);
}

void set_block(const uint8_t *input, size_t length, uint8_t **output, size_t
    *new_length)
{
    uint64_t bit_length_big_endian;
    size_t bit_length = length * 8;
    size_t padded_length = ((bit_length + 64) / 512 + 1) * 512;

    *new_length = padded_length / 8;
    *output = calloc(*new_length, sizeof(uint8_t));
    memcpy(*output, input, length);
    (*output)[length] = 0x80;
    bit_length_big_endian = __builtin_bswap64(bit_length);
    memcpy(*output + *new_length - 8, &bit_length_big_endian, 8);
}

char *mhash(char *message)
{
    uint8_t *preprocessed_message;
    size_t new_length;
    sha1_t sha1 = {A_SHA1, B_SHA1, C_SHA1, D_SHA1, E_SHA1};

    set_block((uint8_t *)message, strlen(message), &preprocessed_message,
        &new_length);
    process_message(preprocessed_message, new_length, &sha1);
    free(preprocessed_message);
    return get_hash(&sha1);
}

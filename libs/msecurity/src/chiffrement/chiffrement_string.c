/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** chiffrement_char.c
*/

#include "msecurity.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *get_key(const char *filename)
{
    long length;
    char *key;
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Failed to open file");
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);
    key = malloc(length + 1);
    if (key == NULL) {
        perror("Failed to allocate memory");
        return NULL;
    }
    fread(key, 1, length, file);
    key[length] = '\0';
    fclose(file);
    return mhash(key);
}

char *mcrypt_string(const char *str, const char *key)
{
    int len = strlen(str);
    int key_len = strlen(key);
    char *encrypted_str = malloc(len * 2 + 1);
    char encrypted_char;

    if (encrypted_str == NULL) {
        perror("Failed to allocate memory");
        return NULL;
    }
    for (int i = 0; i < len; i++) {
        encrypted_char = str[i] ^ key[i % key_len];
        sprintf(&encrypted_str[i * 2], "%02x", encrypted_char);
    }
    encrypted_str[len * 2] = '\0';
    return encrypted_str;
}

char *muncrypt_string(const char *str, const char *key)
{
    int len = strlen(str);
    int key_len = strlen(key);
    char *decrypted_str = malloc(len / 2 + 1);
    char decrypted_char;
    int key_index = 0;

    if (decrypted_str == NULL) {
        perror("Failed to allocate memory");
        return NULL;
    }
    for (int i = 0; i < len; i += 2) {
        sscanf(&str[i], "%02hhx", &decrypted_char);
        decrypted_char = decrypted_char ^ key[key_index % key_len];
        decrypted_str[key_index] = decrypted_char;
        key_index++;
    }
    decrypted_str[key_index] = '\0';
    return decrypted_str;
}

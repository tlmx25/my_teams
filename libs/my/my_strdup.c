/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** allocate memory in destination
*/

#include <stdlib.h>
#include "my.h"

char *my_strndup_free(char *src, size_t n)
{
    size_t i;
    char *dest = malloc(sizeof(char) * (n + 1));

    if (dest == NULL | src == NULL) {
        free(dest);
        free(src);
        return NULL;
    }
    if (n == 0) {
        dest[0] = '\0';
        return dest;
    }
    for (i = 0; src[i] != 0 && i < n; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    free(src);
    return dest;
}

char *my_strndup(char const *src, size_t n)
{
    size_t i;
    char *dest = malloc(sizeof(char) * (n + 1));

    if (dest == NULL)
        return NULL;
    if (n == 0) {
        dest[0] = '\0';
        return dest;
    }
    for (i = 0; src[i] != 0 && i < n; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strdup_free(char *src)
{
    int count = my_strlen(src);
    char *dest = malloc(sizeof(char) * (count + 1));

    if (dest == NULL || src == NULL) {
        free(dest);
        free(src);
        return NULL;
    }
    if (count == 0) {
        dest[0] = '\0';
        return dest;
    }
    for (size_t i = 0; src[i] != 0; i++)
        dest[i] = src[i];
    dest[count] = '\0';
    free(src);
    return dest;
}

char *my_strdup(char const *src)
{
    int count = my_strlen(src);
    char *dest = malloc(sizeof(char) * (count + 1));

    if (dest == NULL || src == NULL) {
        free(dest);
        return NULL;
    }
    if (count == 0) {
        dest[0] = '\0';
        return dest;
    }
    for (size_t i = 0; src[i] != 0; i++)
        dest[i] = src[i];
    dest[count] = '\0';
    return dest;
}

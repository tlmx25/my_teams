/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** my_clean_string.c
*/

#include "my.h"
#include <stdlib.h>

size_t my_strlen_skip_char(char const *str, char const *skip_char)
{
    size_t count = 0;

    if (str == NULL)
        return 0;
    for (size_t i = 0; str[i]; i++) {
        if (is_separator(skip_char, str[i]))
            continue;
        count++;
    }
    return count;
}

char *my_clean_string(char *str, char const *delete_char, int free_str)
{
    size_t len = my_strlen_skip_char(str, delete_char);
    char *clean_str;
    size_t j = 0;

    if (str == NULL)
        return NULL;
    clean_str = malloc(sizeof(char) * (len + 1));
    if (clean_str == NULL)
        return NULL;
    for (size_t i = 0; str[i]; i++) {
        if (!is_separator(delete_char, str[i])) {
            clean_str[j] = str[i];
            j++;
        }
    }
    clean_str[len] = '\0';
    if (free_str)
        free(str);
    return clean_str;
}

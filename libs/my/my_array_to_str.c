/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** my_array_to_str.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char *my_array_to_str_separator(char const **array, char const *separator)
{
    char *str = NULL;
    char *str_separator;
    char *str_tmp;

    if (array == NULL || array[0] == NULL)
        return NULL;
    for (size_t i = 0; array[i]; i++) {
        str_tmp = str;
        if (str != NULL) {
            str = my_strcat(str, separator);
            free(str_tmp);
            str_tmp = str;
        }
        str = my_strcat(str, array[i]);
        free(str_tmp);
        str_tmp = NULL;
    }
    return str;
}

char *my_array_to_str(char const **array)
{
    char *str = NULL;
    char *str_tmp;

    if (array == NULL)
        return NULL;
    for (size_t i = 0; array[i]; i++) {
        str_tmp = str;
        str = my_strcat(str, array[i]);
        free(str_tmp);
        str_tmp = NULL;
    }
    return str;
}

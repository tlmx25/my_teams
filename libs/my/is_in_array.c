/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** is_in_array
*/

#include "my.h"

int is_in_array(char const **array, char const *str)
{
    if (array == NULL)
        return 0;
    for (size_t i = 0; array[i]; i++) {
        if (my_strcmp(array[i], str) == 0)
            return 1;
    }
    return 0;
}

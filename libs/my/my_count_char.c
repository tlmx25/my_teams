/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_count_char
*/

#include <stddef.h>

size_t my_count_char(char const *str, char c)
{
    size_t count = 0;

    if (str == NULL)
        return 0;
    for (size_t i = 0; str[i]; i++) {
        if (str[i] == c)
            count++;
    }
    return count;
}

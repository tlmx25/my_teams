/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** count number of char in str
*/

#include <stdio.h>

int my_strlen(char const *str)
{
    int count = 0;

    if (str == NULL)
        return 0;
    while (str[count] != '\0') {
        count += 1;
    }
    return (count);
}

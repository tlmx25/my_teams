/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** copy str in other str with n char
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int count = my_strlen(src);

    for (; src[i] != '\0' && i != n; i++)
        dest[i] = src[i];
    if (count < n)
        dest[i] = '\0';
    return (dest);
}

/*
** EPITECH PROJECT, 2022
** my_strncat
** File description:
** copy of strncat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int count_d = my_strlen(dest);
    int i = count_d;

    for (int j = 0; src[j] != '\0' && j != nb; i++) {
        dest[i] = src[j];
        j++;
    }
    return (dest);
}

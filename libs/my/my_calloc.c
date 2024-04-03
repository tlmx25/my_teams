/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** my_calloc.c
*/

#include <stdlib.h>

void *my_calloc(size_t size)
{
    void *ptr = malloc(size);

    if (ptr == NULL)
        return NULL;
    for (size_t i = 0; i < size; i++)
        ((char *)ptr)[i] = 0;
    return ptr;
}

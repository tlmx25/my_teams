/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_addlign.c
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"


static char **my_realloc(int size, char const **array)
{
    char **new_array = malloc(size);

    if (new_array == NULL)
        return NULL;
    for (size_t i = 0; array[i]; i++)
        new_array[i] = my_strdup(array[i]);
    return new_array;
}

char **my_appendline(char **array, char *line)
{
    int len = 0;
    char **new_array = NULL;

    while (array != NULL && array[len] != NULL)
        len++;
    if (line == NULL)
        return array;
    new_array = (char **)realloc(array, (len + 2) * sizeof(char *));
    if (new_array == NULL)
        return array;
    new_array[len] = my_strdup(line);
    new_array[len + 1] = NULL;
    return new_array;
}

char **my_appendline_index(char **array, char *line, int index)
{
    int len = 0;
    char **new_array = NULL;

    while (array != NULL && array[len] != NULL)
        len++;
    if (line == NULL || index < 0 || index > len)
        return array;
    new_array = my_realloc((len + 2) * sizeof(char *), (char const **)array);
    if (new_array == NULL)
        return array;
    for (int i = len; i >= index; i--)
        new_array[i + 1] = new_array[i];
    new_array[index] = my_strdup(line);
    new_array[len + 1] = NULL;
    return new_array;
}

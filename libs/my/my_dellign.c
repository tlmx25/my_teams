/*
** EPITECH PROJECT, 2022
** my_delling
** File description:
** how to dell lign in a char **
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **my_delline(char **array, int key)
{
    int len = 0;

    if (!array || key < 0)
        return NULL;
    for (; array[len] != NULL; len++);
    if (key >= len)
        return array;
    free(array[key]);
    for (int i = key; i < len - 1; i++)
        array[i] = array[i + 1];
    array[len - 1] = NULL;
    return array;
}

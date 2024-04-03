/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_puttab.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void free_tab(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

int my_puttab(char **tab)
{
    int count = 0;

    if (tab == NULL)
        return 0;
    for (int i = 0; tab[i]; i++) {
        count += (int)write(1, tab[i], my_strlen(tab[i]));
        count += (int)write(1, "\n", 1);
    }
    return count;
}

/*
** EPITECH PROJECT, 2022
** contat_parms
** File description:
** separete string in char ** -> char *
*/

#include <stdlib.h>
#include "my.h"

static char *my_strcatnn(char *dest, char const *src, int check)
{
    int count_d = my_strlen(dest);
    int i = count_d;

    for (int j = 0; src[j] != '\0'; i++) {
        dest[i] = src[j];
        j++;
    }
    if (check == 0)
        dest[i] = '\n';
    return (dest);
}

char *concat_params(int ac, char **av)
{
    int count = 0;
    int i = 0;
    char *dest;

    for (int i = 0; i < ac; i++)
        count += my_strlen(av[i]);
    dest = malloc(sizeof(char) * (count + ac));
    for (; i < ac - 1; i++) {
        my_strcatnn(dest, av[i], 0);
    }
    my_strcatnn(dest, av[i], 1);
    return dest;
}

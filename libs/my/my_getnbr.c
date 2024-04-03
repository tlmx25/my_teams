/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** get nbr
*/

#include <stdio.h>
#include "my.h"

int my_getnbr(char const *str)
{
    int neg = 1;
    long int n = 0;
    int check = 0;

    if (str == NULL)
        return 0;
    for (int i = 0; str[i] < '0' || str[i] > '9'; i++)
        if (str[i] == '-')
            neg = neg * (-1);
    for (int j = 0; str[j]; j++) {
        for (; str[j] >= '0' && str[j] <= '9'; j++) {
            n = (n * 10) + (str[j] - '0');
            check++;
        }
        if (check != 0 && n < 2147483647)
            return (n * neg);
    }
    return 0;
}

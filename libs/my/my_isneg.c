/*
** EPITECH PROJECT, 2022
** my_isneg
** File description:
** return N if n is negative or P if n is null or positive
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar(78);
        return 1;
    } else {
        my_putchar(80);
        return 0;
    }
}

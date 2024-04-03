/*
** EPITECH PROJECT, 2022
** tkt
** File description:
** tkt
*/

#include "my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
    }
    if (nb == 0)
        my_putchar(48);
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + 48);
    }
    if (nb < 10)
        my_putchar(nb + 48);
    return nb;
}

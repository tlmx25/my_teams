/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** put a charractere of strf witch putchar
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return 0;
}

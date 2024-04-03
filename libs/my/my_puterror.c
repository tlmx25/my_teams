/*
** EPITECH PROJECT, 2022
** my_puterror
** File description:
** put message of error in error output
*/

#include <unistd.h>
#include "my.h"

void my_puterror(char *error)
{
    write(2, error, my_strlen(error));
    write(2, "\n", 1);
}

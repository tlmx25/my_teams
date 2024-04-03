/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** find a str in other str , return pointers if find a str , else 0
*/

#include <stddef.h>
#include "my.h"

int boucle2(char *str, char const *to_find, int i)
{
    int save;
    int check = 0;
    int j = 0;

    for (j = 0; str[i] == to_find[j] && to_find[j] != '\0';) {
        if (check == 0) {
            check = 1;
            save = i;
        }
        i += 1;
        j += 1;
    }
    if (j != 0)
        i = save;
    if (to_find[j] == '\0')
        return i - 1;
    check = 0;
    return i;
}

char *my_strstr(char *str, char const *to_find)
{
    int len_str = my_strlen(str);
    int len_find = my_strlen(to_find);

    if (len_find == 0 || len_str == 0)
        return 0;
    for (int i = 0; i < len_str; i++) {
        if (my_strncmp(&str[i], to_find, len_find) == 0)
            return &str[i];
    }
    return NULL;
}

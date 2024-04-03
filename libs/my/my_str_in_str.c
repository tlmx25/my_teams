/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** my_str_in_str.c
*/

#include <stddef.h>

static int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return 1;
    for (; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1; i++);
    if (s1[i] - s2[i] < 0)
        return (-1);
    if (s1[i] - s2[i] > 0)
        return (1);
    if (s1[i] == s2[i])
        return 0;
    return 84;
}

static int my_strlen(char const *str)
{
    int count = 0;

    if (str == NULL)
        return 0;
    while (str[count] != '\0') {
        count += 1;
    }
    return (count);
}

int my_str_in_str(char const *str, char const *find)
{
    int len_str = my_strlen(str);
    int len_find = my_strlen(find);

    if (len_find == 0 || len_str == 0)
        return 0;
    for (int i = 0; i < len_str; i++) {
        if (my_strncmp(&str[i], find, len_find) == 0)
            return 1;
    }
    return 0;
}

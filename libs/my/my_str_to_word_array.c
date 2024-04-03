/*
** EPITECH PROJECT, 2022
** Pokedex
** File description:
** Str to word array
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

int is_alphanum(char c)
{
    return (
        (c >= 'a' && c <= 'z')
        || (c >= 'A' && c <= 'Z')
        || (c >= '0' && c <= '9')
        );
}

int is_separator(char const *separators, char letter)
{
    if (separators == NULL)
        return 0;
    for (int i = 0; separators[i]; i++) {
        if (separators[i] == letter)
            return 1;
    }
    return 0;
}

int count_word_arr(char const *str, char *separators)
{
    int count = 0;
    size_t len = my_strlen(str);

    if (str == NULL)
        return 0;
    for (size_t i = 0; i < len; i++) {
        if (is_separator(separators, str[i]) &&
            !is_separator(separators, str[i + 1]))
            count += 1;
    }
    return count + (len > 0 && !is_separator(separators, str[len - 1]));
}

static size_t skip_sep(char const *separators, size_t len, char const *str,
    size_t *save)
{
    size_t i = 0;

    for (; is_separator(separators, str[i]) && i < len; i += 1)
        *save += 1;
    return i;
}

static size_t set_check(int *check, size_t len, char const *str,
    char const *separators)
{
    size_t i = 0;

    for (; !is_separator(separators, str[i]) && i < len; *check += 1)
        i += 1;
    return i;
}

static int fill_tab(char **tab, size_t len, char const *str, char *separators)
{
    int z = 0;
    int check;
    size_t save;

    for (size_t i = 0; i < len; i++) {
        check = 0;
        save = i;
        i += skip_sep(separators, len - i, &str[i], &save);
        i += set_check(&check, len - i, &str[i], separators);
        tab[z] = malloc(sizeof(char) * (check + 1));
        if (tab[z] == NULL)
            return 84;
        for (int j = 0; j != check; save++) {
            tab[z][j] = str[save];
            j++;
        }
        tab[z][check] = '\0';
        z++;
    }
    return 0;
}

char **my_str_to_word_array(char const *str, char *separators)
{
    size_t len = my_strlen(str);
    int nb_word = count_word_arr(str, separators);
    char **tab = malloc(sizeof(char *) * (nb_word + 1));

    for (int i = 0; i <= nb_word; i++)
        tab[i] = NULL;
    if (tab == NULL || str == NULL || str[0] == '\0') {
        free(tab);
        return NULL;
    }
    if (fill_tab(tab, len, str, separators) == 84) {
        free_tab(tab);
        return NULL;
    }
    if (tab[nb_word - 1] != NULL && tab[nb_word -1][0] == '\0')
        tab[nb_word -1] = NULL;
    tab[nb_word] = NULL;
    return tab;
}

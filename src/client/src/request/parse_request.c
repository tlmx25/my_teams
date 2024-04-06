/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** parse_request
*/

#include "client.h"
#include "my.h"

char **get_request_arg(const request_t *request)
{
    char **tab = my_str_to_word_array(request->body, "\r");

    return tab;
}

char **get_request_nb_arg(const request_t *request, int nb_arg)
{
    char **tab = my_str_to_word_array(request->body, "\r");

    if (tab == NULL)
        return NULL;
    if (my_arrsize((char const **)tab) != nb_arg) {
        free_tab(tab);
        return NULL;
    }
    return tab;
}

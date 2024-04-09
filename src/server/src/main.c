/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** main
*/

#include <stdio.h>
#include "my.h"
#include "server.h"

static int print_help(void)
{
    printf("USAGE: ./myteams_server port\n\n");
    printf("port is the port number on which the server socket listens.\n");
    return 0;
}

int main(int ac, char **av)
{
    server_t *server;
    int ret;

    if (ac != 2)
        return 84;
    if (my_strcmp(av[1], "--help") == 0 || my_strcmp(av[1], "-h") == 0)
        return print_help();
    if (my_str_isnum(av[1]) == 0)
        return 84;
    server = create_server(my_getnbr(av[1]));
    if (server == NULL)
        return 84;
    ret = run_server(server);
    delete_server(server);
    return ret;
}

/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** main
*/

#include <stdio.h>
#include "my.h"
#include "client_cli.h"

static int print_help(void)
{
    printf("USAGE: ./myteams_cli ip port\n\n");
    printf("ip\tis the server ip address on which the server socket listens");
    printf("\nport\tis the port number on which the server socket listens\n");
    return 0;
}

static int is_valid_ip(char *ip)
{
    int point = 0;
    int nbr = 0;

    for (int i = 0; ip[i]; i++) {
        if (point > 3 || nbr > 3)
            return 0;
        if (ip[i] == '.') {
            nbr = 0;
            point++;
            continue;
        }
        if (ip[i] >= '0' && ip[i] <= '9') {
            nbr++;
            continue;
        }
        return 0;
    }
    return 1;
}

int main(int ac, char **av)
{
    client_t *client = NULL;
    int ret;

    if (ac == 2)
        return print_help();
    if (ac != 3 || !is_valid_ip(av[1]) || !my_str_isnum(av[2]))
        return 84;
    client = create_client(my_strdup(av[1]), my_getnbr(av[2]));
    if (client == NULL)
        return 84;
    ret = run_client(client);
    delete_client(client);
    return ret;
}

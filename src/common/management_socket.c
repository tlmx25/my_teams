/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** management_socket
*/

#include <stdlib.h>
#include "management_socket.h"

select_t *init_select(void)
{
    select_t *select = malloc(sizeof(select_t));

    if (select == NULL)
        return NULL;
    FD_ZERO(&select->readfds);
    FD_ZERO(&select->writefds);
    select->timeout.tv_sec = 0;
    select->timeout.tv_usec = 0;
    select->use_timeout = 0;
    select->max_fd = 0;
    return select;
}

void add_to_select(select_t *select, int fd)
{
    FD_SET(fd, &select->readfds);
    FD_SET(fd, &select->writefds);
}

void reset_select(select_t *select)
{
    FD_ZERO(&select->readfds);
    FD_ZERO(&select->writefds);
}

int exec_select(select_t *select_config)
{
    int ret;

    if (select_config->use_timeout)
        ret = select(select_config->max_fd + 1, &select_config->readfds,
            &select_config->writefds, NULL, &select_config->timeout);
    else
        ret = select(select_config->max_fd + 1, &select_config->readfds,
            &select_config->writefds, NULL, NULL);
    if (ret == -1)
        return ERROR;
    return 0;
}

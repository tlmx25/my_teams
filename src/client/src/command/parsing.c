/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** parsing
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "client_cli.h"
#include "socket.h"
#include "my.h"

static void check_quotes(parse_cmd_t *cmd, int i)
{
    if (i > cmd->start) {
        cmd->args = realloc(cmd->args, (cmd->nb_args + 1) * sizeof(char *));
        cmd->args[cmd->nb_args] = malloc((i - cmd->start + 1) * sizeof(char));
        for (int j = cmd->start; j < i; (j)++) {
            cmd->args[cmd->nb_args][j - cmd->start] = cmd->cmd[j];
        }
        cmd->args[cmd->nb_args][i - cmd->start] = '\0';
        cmd->nb_args++;
    }
    cmd->start = i + 1;
}

char **parse_arguments(char *line)
{
    int i = 0;
    parse_cmd_t *cmd = malloc(sizeof(parse_cmd_t));

    cmd->args = NULL;
    cmd->nb_args = 0;
    cmd->in_quotes = 0;
    cmd->start = 0;
    cmd->cmd = my_strdup(line);
    for (i = 0; cmd->cmd[i] != '\0'; i++) {
        if (cmd->cmd[i] == '"')
            cmd->in_quotes = !cmd->in_quotes;
        else if (cmd->cmd[i] == ' ' && !cmd->in_quotes)
            check_quotes(cmd, i);
    }
    if (i > cmd->start)
        check_quotes(cmd, i);
    cmd->args = realloc(cmd->args, (cmd->nb_args + 1) * sizeof(char *));
    cmd->args[cmd->nb_args] = NULL;
    return cmd->args;
}

static int check_if_quotes(char *str, int len, int minus)
{
    if (str[0] != '"' || str[len - minus] != '"')
        return 1;
    return 0;
}

int command_error_handling(char **command)
{
    int size = my_arrsize((char const **)command);
    int len = strlen(command[0]);
    int check = 0;

    if (command[0][0] == '"' || command[0][len - 2] == '"')
        return 1;
    for (int i = 1; i < size; i++) {
        len = strlen(command[i]);
        if (size == 2 || i == size - 1)
            check = check_if_quotes(command[i], len, 2);
        else
            check = check_if_quotes(command[i], len, 1);
        if (check == 1)
            return 1;
    }
    return 0;
}

/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** parsing
*/

#include <stdlib.h>
#include "client_cli.h"
#include "my.h"

static void *handle_realloc(void *ptr, size_t size)
{
    void *new_ptr = realloc(ptr, size);

    if (new_ptr == NULL) {
        free(ptr);
        return NULL;
    }
    return new_ptr;
}

static void check_quotes(parse_cmd_t *cmd, int i)
{
    if (i > cmd->start) {
        cmd->args = handle_realloc(cmd->args,
        (cmd->nb_args + 1) * sizeof(char *));
        if (cmd->args == NULL)
            return;
        cmd->args[cmd->nb_args] = malloc((i - cmd->start + 1) * sizeof(char));
        for (int j = cmd->start; j < i; (j)++) {
            cmd->args[cmd->nb_args][j - cmd->start] = cmd->cmd[j];
        }
        cmd->args[cmd->nb_args][i - cmd->start] = '\0';
        cmd->nb_args++;
    }
    cmd->start = i + 1;
}

static void par_arg(parse_cmd_t *cmd, int i)
{
    if (cmd->cmd[i] == '"')
        cmd->in_quotes = !cmd->in_quotes;
    else if (cmd->cmd[i] == ' ' && !cmd->in_quotes)
        check_quotes(cmd, i);
}

static char **clean_cmd(parse_cmd_t *cmd)
{
    char **tmp = NULL;

    if (cmd)
        tmp = cmd->args;
    for (int i = 0; tmp && i < cmd->nb_args; i++) {
        tmp[i] = my_clean_string(cmd->args[i], "\n", 1);
    }
    if (tmp)
        tmp[cmd->nb_args] = NULL;
    if (cmd && cmd->cmd)
        free(cmd->cmd);
    if (cmd)
        free(cmd);
    return tmp;
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
    for (i = 0; cmd->cmd[i] != '\0'; i++)
        par_arg(cmd, i);
    if (i > cmd->start)
        check_quotes(cmd, i);
    cmd->args = handle_realloc(cmd->args, (cmd->nb_args + 1) * sizeof(char *));
    if (cmd->args == NULL)
        return clean_cmd(cmd);
    return clean_cmd(cmd);
}

static int check_if_quotes(char const *str, int len, int minus)
{
    if (str[0] != '"' || str[len - minus] != '"')
        return 1;
    return 0;
}

int command_error_handling(char **command)
{
    int size = my_arrsize((char const **)command);
    int len = my_strlen(command[0]);

    if (command[0][0] == '"' || command[0][len - 2] == '"')
        return 1;
    for (int i = 1; i < size; i++) {
        len = my_strlen(command[i]);
        if (check_if_quotes(command[i], len, 1) == 1)
            return 1;
    }
    for (int i = 0; command[i]; i++)
        command[i] = my_clean_string(command[i], "\"", 1);
    return 0;
}

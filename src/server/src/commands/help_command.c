/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** help_command
*/

#include "logging_server.h"
#include <stdlib.h>
#include "server.h"
#include "my.h"
#include "actions.h"

static char *get_file_content(char *file_path)
{
    FILE *file = fopen(file_path, "r");
    long file_size;
    char *help;

    if (file == NULL)
        return NULL;
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    help = malloc(file_size + 1);
    if (help == NULL) {
        fclose(file);
        return NULL;
    }
    fread(help, 1, file_size, file);
    help[file_size] = '\0';
    fclose(file);
    return help;
}

void help_command(UNUSED server_t *server, client_t *client,
    UNUSED char **command)
{
    char *help;
    request_t *request;

    help = get_file_content("src/server/src/commands/help_content.txt");
    if (help == NULL) {
        printf("Failed to get help content\n");
        return;
    }
    request = create_request(PRINT_ERROR, 200, help);
    if (request == NULL)
        return;
    add_request_to_list(client->requests_sent, request);
}

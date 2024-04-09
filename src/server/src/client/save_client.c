/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** save_client
*/

#include <uuid/uuid.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include "my.h"
#include "client.h"

static void save_client(client_t *client, FILE *fd)
{
    client_save_t save = {0};

    memset(&save, 0, sizeof(client_save_t));
    uuid_copy(save.uuid, client->uuid);
    if (client->username)
        my_strcpy(save.username, client->username);
    if (client->password)
        my_strcpy(save.password, client->password);
    fwrite(&save, sizeof(client_save_t), 1, fd);
}

int create_directory_if_not_exists(const char *dir_path)
{
    struct stat st = {0};

    if (stat(dir_path, &st) == -1) {
        if (mkdir(dir_path, 0700) == -1) {
            perror("mkdir");
            return -1;
        }
    }
    return 0;
}

void save_client_list(client_list_t *list)
{
    FILE *fd;

    create_directory_if_not_exists(SAVE_DIR);
    fd = fopen(CLIENT_FILE, "w+");
    if (fd == NULL) {
        perror("open");
        return;
    }
    for (client_t *tmp = list->head; tmp; tmp = tmp->next)
        save_client(tmp, fd);
    fclose(fd);
}

void add_client_to_save(client_t *client)
{
    FILE *fd;

    if (create_directory_if_not_exists(SAVE_DIR) == -1)
        return;
    fd = fopen(CLIENT_FILE, "a+");
    if (fd == NULL) {
        perror("open");
        return;
    }
    save_client(client, fd);
    fclose(fd);
}

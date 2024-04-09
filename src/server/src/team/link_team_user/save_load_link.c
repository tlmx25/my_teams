/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** save_link
*/

#include <stdio.h>
#include "link_team_user.h"

static void save_link(link_team_user_t *link, FILE *file)
{
    link_team_user_save_t save;

    if (link == NULL || file == NULL)
        return;
    uuid_copy(save.team_uuid, link->team_uuid);
    uuid_copy(save.user_uuid, link->user_uuid);
    fwrite(&save, sizeof(link_team_user_save_t), 1, file);
}

void save_link_list(link_team_user_list_t *list)
{
    link_team_user_t *tmp;
    FILE *file;

    if (list == NULL)
        return;
    if (create_directory_if_not_exists(SAVE_DIR) == -1)
        return;
    file = fopen(LINK_TEAM_USER_FILE, "w+");
    if (file == NULL)
        return;
    for (tmp = list->head; tmp; tmp = tmp->next)
        save_link(tmp, file);
    fclose(file);
}

void add_link_to_save(link_team_user_t *link)
{
    FILE *file;

    if (create_directory_if_not_exists(SAVE_DIR) == -1)
        return;
    file = fopen(LINK_TEAM_USER_FILE, "a+");
    if (file == NULL)
        return;
    save_link(link, file);
    fclose(file);
}

static link_team_user_t *load_link(link_team_user_save_t save)
{
    link_team_user_t *link;

    link = create_link(save.team_uuid, save.user_uuid);
    return link;
}

void load_link_list(link_team_user_list_t *list)
{
    link_team_user_save_t save;
    FILE *file;

    if (list == NULL)
        return;
    file = fopen(LINK_TEAM_USER_FILE, "r");
    if (file == NULL)
        return;
    while (fread(&save, sizeof(link_team_user_save_t), 1, file))
        add_link(list, load_link(save));
    fclose(file);
}

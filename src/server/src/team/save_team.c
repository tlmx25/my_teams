/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** save_team
*/

#include <stdio.h>
#include <string.h>
#include "team.h"

static void save_team(team_t *team, FILE *file)
{
    team_save_t save = {0};
    if (team == NULL || file == NULL)
        return;
    uuid_copy(save.uuid, team->uuid);
    uuid_copy(save.owner_uuid, team->owner_uuid);
    strncpy(save.name, team->name, MAX_NAME_LENGTH);
    strncpy(save.description, team->description, MAX_DESCRIPTION_LENGTH);
    fwrite(&save, sizeof(team_save_t), 1, file);
}

void save_teams_list(team_list_t *list)
{
    FILE *file;

    if (create_directory_if_not_exists(SAVE_DIR) == -1)
        return;
    file = fopen(TEAM_SAVE_FILE, "w+");
    if (file == NULL)
        return;
    for (team_t *tmp = list->head; tmp; tmp = tmp->next)
        save_team(tmp, file);
    fclose(file);
}

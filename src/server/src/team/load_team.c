/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** load_team
*/

#include <stdio.h>
#include <stdlib.h>
#include "team.h"

static team_t *load_team(team_save_t team_save)
{
    team_t *team = create_team(team_save.name, team_save.description,
        team_save.uuid, team_save.owner_uuid);

    return team;
}

void load_team_list(team_list_t *list)
{
    team_save_t save;
    team_t *team;
    FILE *file = fopen(TEAM_SAVE_FILE, "r+");

    if (file == NULL)
        return;
    while (fread(&save, sizeof(team_save_t), 1, file) == 1) {
        team = load_team(save);
        add_team_to_list(list, team);
    }
}

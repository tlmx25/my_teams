/*
** EPITECH PROJECT, 2024
** PRIVATE_TEAMS
** File description:
** load_thread
*/

#include <stdio.h>
#include "thread_teams.h"

static thread_t *load_thread(thread_save_t save)
{
    thread_t *thread = create_thread_from_save(save);

    if (thread == NULL)
        return NULL;
    return thread;
}

void load_thread_list(thread_list_t *list)
{
    thread_t *thread;
    thread_save_t save;
    FILE *file;

    if (list == NULL)
        return;
    file = fopen(THREAD_SAVE_FILE, "r");
    if (file == NULL)
        return;
    while (fread(&save, sizeof(thread_save_t), 1, file) == 1) {
        thread = load_thread(save);
        if (thread != NULL)
            add_thread_to_list(list, thread);
    }
    fclose(file);
}

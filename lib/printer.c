/*
** EPITECH PROJECT, 2020
** FASTAtools
** File description:
** special print functions
*/

#include "../inc/fasta.h"

void print(char **tabs, char *end)
{
    for (int i = 0; tabs[i]; i++) {
        printf("%s%s", tabs[i], end);
    }
}

void print_tabs(char **tabs)
{
    for (int i = 0; tabs[i] != NULL; i++)
        if (is_identifier(tabs[i]))
            printf("%s", tabs[i]);
        else
        {
            for (int j = 0; tabs[i][j]; j++)
                if (tabs[i][j] != '\n')
                    printf("%c", tabs[i][j]);
            if (is_identifier(tabs[i + 1]))
                printf("\n");
        }
    printf("\n");
}
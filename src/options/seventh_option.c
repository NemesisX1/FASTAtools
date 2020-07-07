/*
** EPITECH PROJECT, 2020
** FASTAtools
** File description:
** fifth_option
*/

#include "../../inc/fasta.h"

void seventh_option(char **tabs_content)
{
    char **tabs = get_seq_tabs(tabs_content);

    for (int i = 0; tabs[i]; i++)
        printf("%s", tabs[i]);
    printf("\n");
    free_tabs(tabs);
}
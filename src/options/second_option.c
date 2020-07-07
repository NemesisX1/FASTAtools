/*
** EPITECH PROJECT, 2020
** FASTAtools
** File description:
** second_option
*/

#include "../../inc/fasta.h"

void second_option(char **tabs_content)
{
    for (int i = 0; tabs_content[i]; i++)
        for (int j = 0; tabs_content[i][j]; j++)
            if (tabs_content[i][j] == 'T')
                tabs_content[i][j] = 'U';
    print_tabs(tabs_content);
}

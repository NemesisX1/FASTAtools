/*
** EPITECH PROJECT, 2020
** FASTAtools
** File description:
** third_option
*/

#include "../../inc/fasta.h"

void *get_reversed_complement(char *sequence)
{
    char *reversed =  my_revstr(sequence);

    for (int i = 0; reversed[i]; i++) {
        if (reversed[i] == 'A')
            reversed[i] = 'T';
        else if (reversed[i] == 'T')
            reversed[i] = 'A';
        else if (reversed[i] == 'G')
            reversed[i] = 'C';
        else if (reversed[i] == 'C')
            reversed[i] = 'G';
    }
    printf("%s\n", reversed);
}

void third_option(char **tabs_content)
{
    char *fused_sequence = NULL;

    for (int i = 0; tabs_content[i] != NULL; i++) {
        if (is_identifier(tabs_content[i])) {
            printf("%s", tabs_content[i]);
            i++;
            for (; !is_identifier(tabs_content[i]) && tabs_content[i] != NULL
            ; i++)
                fused_sequence = fuse_str(fused_sequence, tabs_content[i]);
            i--;
            get_reversed_complement(clean_str(fused_sequence));
            fused_sequence = NULL;
        }
    }
}

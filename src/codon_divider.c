/*
** EPITECH PROJECT, 2020
** FASTAtools
** File description:
** FASTAtools
*/

#include "../inc/fasta.h"

bool is_here_codon(char *seq, char *codon, int i)
{
    if (seq[i] == codon[0]
        && seq[i + 1] == codon[1]
        && seq[i + 2] == codon[2])
        return (true);
    return (false);
}

char **codon_divider(char *seq)
{
    char **codon_begins = malloc(sizeof(char *) * 100000);
    int idx = 0;

    for (int i = 0, j = 0; seq[i]; i++, j++) {
        if (i >= 3 && (i % 3 == 0)) {
            codon_begins[idx][strlen(codon_begins[idx])] = '\0';
            idx++;
            j = 0;
        }
        codon_begins[idx] = realloc(codon_begins[idx],
        sizeof(char *) * (j + 1));
        codon_begins[idx][j] = seq[i];
    }
    codon_begins[idx + 1] = NULL;
    return (codon_begins);
}
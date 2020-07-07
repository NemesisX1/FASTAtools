/*
** EPITECH PROJECT, 2020
** FASTAtools
** File description:
** fifth_option
*/

#include "../../inc/fasta.h"
#include "../../inc/ref_tabs.h"

char put_letters(char *codon)
{
    int is_n = 0, idx = 0, pos = 0;

    for (int i = 0; codon[i]; i++)
        if (codon[i] == 'N')
            is_n = 1;
    if (is_n)
        return ('X');
    else {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; ref_tabs[i].name[j] != NULL; j++)
                if (is_same_str(ref_tabs[i].name[j], codon)) {
                    idx = i;
                    break;
                }
        }
    }
    return (ref_tabs[idx].ref);
}

char *get_amino_acid_tabs(char *seq)
{
    char *amino_tab = malloc(sizeof(char) * 1000000000);
    char **codon_tabs = codon_divider(seq);
    char letter = 0;
    int idx = 0;


    for (int i = 0; codon_tabs[i]; i++) {
        letter = put_letters(codon_tabs[i]);
        amino_tab[idx] = letter;
        idx++;
    }
    amino_tab[idx] = '\0';
    return (amino_tab);
}

void sixth_option(char **tabs_content)
{
    char **coding_seq_tabs = get_coding_sequence(tabs_content);
    char *seq = NULL;
    char **amino_acid = malloc(sizeof(char *) * 1000000000);
    int idx = 0;

    for (int i = 0; coding_seq_tabs[i]; i++) {
        seq = strdup(coding_seq_tabs[i]);
        amino_acid[idx] = strdup(get_amino_acid_tabs(seq));
        idx++;
    }
    amino_acid[idx] = NULL;
    my_sort_word_array(amino_acid);
    print(amino_acid, "\n");
    free_tabs(coding_seq_tabs);
    free_tabs(amino_acid);
    free(seq);
}
/*
** EPITECH PROJECT, 2020
** FASTAtools
** File description:
** fifth_option
*/

#include "../../inc/fasta.h"

void search_for_the_codon_seq(char **codon, int *ok1, int *ok2)
{
    int idxa = 0;
    int idxb = 0;

    for (int i = 0; codon[i] != NULL; i++) {
        if (is_same_str("ATG", codon[i]))
            idxa++;
        if (is_same_str("TAA", codon[i])
            || is_same_str("TAG", codon[i])
            || is_same_str("TGA", codon[i]))
            idxb++;
    }
    *ok1 = idxa;
    *ok2 = idxb;
}

int *get_atg_idx(char *seq, int *ptr_idx)
{
    int idx = 0;
    int *begin = malloc(sizeof(int) * 1);

    for (int i = 0; seq[i]; i++) {
        if (is_here_codon(seq, "ATG", i)) {
            begin[idx] = i;
            idx++;
            begin = realloc(begin, sizeof(int) * (idx + 1));
        }
    }
    *ptr_idx = idx;
    return (begin);
}

char **codons_seq(char *seq)
{
    int idx = 0, ok1 = 0, ok2 = 0, *begin = NULL, find = 0;
    char *tmp = NULL, **codon_tmp = NULL;

    begin = get_atg_idx(seq, &idx);
    for (int i = 0; i < idx; i++, ok1 = 0, ok2 = 0) {
        tmp = get_string_from_pos(seq, begin[i]);
        codon_tmp = codon_divider(tmp);
        search_for_the_codon_seq(codon_tmp, &ok1, &ok2);
        if (ok1 > 0 && ok2 > 0) {
            find = 1;
            break;
        }
    }
    if (find)
        return (codon_tmp);
    else
        return (NULL);
}

int printer(char *codon, int *start)
{
    int text = 0;

    if (is_empty_line(codon))
        return (3);
    if (is_same_str(codon, "ATG")) {
        text = 1;
        *start = 1;
    }
    else if (is_same_str("TAA", codon)
            || is_same_str("TAG", codon) || is_same_str("TGA", codon)) {
        text = 0;
        *start = 0;
    } else
        text = 2;
    if ((text == 1 || text == 2) && strlen(codon) > 2)
       return (1);
    if (!text)
        return (0);
}

void fifth_option(char **tabs_content)
{
    char **seq_tabs = get_seq_tabs(tabs_content);
    char **tmp = {NULL};
    int text = 0;
    int start = 0;

    for (int i = 0; seq_tabs[i]; i++) {
        tmp = codons_seq(seq_tabs[i]);
        if (tmp) {
            for (int j = 0; tmp[j]; j++) {
                text = printer(tmp[j], &start);
                if (text && strlen(tmp[j]) > 2 && start)
                    printf("%s", tmp[j]);
                if (!text && !start)
                    printf("\n");
            }
        }
    }
}
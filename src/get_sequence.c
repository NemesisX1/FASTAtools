/*
** EPITECH PROJECT, 2020
** FASTAtools
** File description:
** get_conding_seq
*/
#include "../inc/fasta.h"

int  decide_text(char *tmp)
{
    int text = 0;

    if (is_same_str(tmp, "ATG"))
        text = 1;
    else if (is_same_str("TAA", tmp) || is_same_str("TAG", tmp)
            || is_same_str("TGA", tmp))
            text = 0;
    else
        text = 2;
    return (text);
}

char **get_coding_sequence(char **tabs_content)
{
    char **seq_tabs = get_seq_tabs(tabs_content), **tmp = {NULL};
    int text = 0, start = 0, idx = 0;
    char **coding_seq = malloc(sizeof(char *) * 1);

    for (int i = 0; seq_tabs[i]; i++) {
        tmp = codons_seq(seq_tabs[i]);
        if (tmp) {
            for (int j = 0; tmp[j]; j++) {
                //text = printer(tmp[j], &start);
                if (text && strlen(tmp[j]) > 2 && start)
                    coding_seq[idx] = fuse_str(coding_seq[idx], tmp[j]);
                if (!text && !start) {
                    idx++;
                    coding_seq = realloc(coding_seq,
                    sizeof(char *) * (idx + 1));
                }
            }
        }
    }
    coding_seq[idx] = NULL;
    return (coding_seq);
}

char **get_seq_tabs(char **tabs_content)
{
    char *fused_sequence = NULL;
    char **seq_tabs = malloc(sizeof(char *) * 1);
    int idx = 0;

    for (int i = 0; tabs_content[i] != NULL; i++) {
        if (is_identifier(tabs_content[i])) {
            i++;
            for (; !is_identifier(tabs_content[i]) && tabs_content[i] != NULL
            ; i++)
                fused_sequence = fuse_str(fused_sequence, tabs_content[i]);
            i--;
            seq_tabs[idx] = clean_str(fused_sequence);
            idx++;
            seq_tabs = realloc(seq_tabs, sizeof(char *) * (idx + 1));
            fused_sequence = NULL;
        }
    }
    seq_tabs[idx] = NULL;
    return (seq_tabs);
}
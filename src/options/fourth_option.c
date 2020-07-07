/*
** EPITECH PROJECT, 2020
** FASTAtools
** File description:
** fourth_option
*/

#include "../../inc/fasta.h"

bool is_in_tabs(char **tabs, char *str)
{
    bool is_in = false;

    for (int i = 0; tabs[i] != NULL; i++) {
        if (is_same_str(tabs[i], str))
            is_in = true;
    }
    return (is_in);
}

char *get_k_from_pos(char *str, int pos, int k)
{
    char *result = malloc(sizeof(char) * (k + 1));
    int idx = 0;

    for (int i = pos; i < pos + k ; i++, idx++)
        result[idx] = str[i];
    result[idx] = '\0';
    return (result);
}

char **get_k_mer_tabs(char **seq, int k)
{
    char **tabs = (char **)malloc(sizeof(char *) * 1);
    char *result = NULL;
    int len = 0;
    long idx = 0;

    for (int i = 0; seq[i]; i++) {
        len = strlen(seq[i]);
        if (len > k)
            for (int j = 0; j < len - k + 1 ; j++) {
                result = get_k_from_pos(seq[i], j, k);
                if (!is_in_tabs(tabs, result)) {
                    tabs[idx] = strdup(result);
                    idx++;
                    tabs = realloc(tabs, sizeof(char *) * (idx + 1));
                }
            }
    }
    tabs[idx] = NULL;
    free(result);
    return (tabs);
}

void fourth_option(char **tabs_content, int k)
{
    char **seq = get_seq_tabs(tabs_content);
    char **kmers_tabs = get_k_mer_tabs(seq, k);

    my_sort_word_array(kmers_tabs);
    print(kmers_tabs, "\n");
    free_tabs(seq);
    free_tabs(kmers_tabs);
}
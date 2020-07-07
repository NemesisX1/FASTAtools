/*
** EPITECH PROJECT, 2020
** FASTAtools
** File description:
** sort_word
*/

#include "../inc/fasta.h"

static int check_swap(char **tab, int i)
{
    int k = 0;

    if (i > 0 && tab[i][k] < tab[i - 1][k])
        return (1);
    else if (i > 0 && tab[i][k] == tab[i - 1][k]) {
        while (tab[i][k] == tab[i - 1][k])
            k += 1;
        if (tab[i][k] < tab[i - 1][k])
            return (1);
        else
            return (0);
    } else
        return (0);
}

void my_sort_word_array(char **tab)
{
    int i = 0;
    char *tmp = NULL;

    while (tab[i] != NULL) {
        if (check_swap(tab, i)) {
            tmp = strdup(tab[i]);
            tab[i] = strdup(tab[i - 1]);
            tab[i - 1] = strdup(tmp);
            i -= 2;
        }
        i += 1;
    }
    free(tmp);
}
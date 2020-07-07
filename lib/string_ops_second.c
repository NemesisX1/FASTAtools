/*
** EPITECH PROJECT, 2020
** FASTAtools
** File description:
** string_ops
*/

#include "../inc/fasta.h"

char *get_string_from_pos(char *str, int pos)
{
    char *result = malloc(sizeof(char) *(strlen(str) - pos + 1));
    int idx = 0;

    for (int i = pos; str[i]; i++, idx++)
        result[idx] = str[i];
    result[idx] = '\0';
    return (result);
}

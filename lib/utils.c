/*
** EPITECH PROJECT, 2020
** FASTAtools
** File description:
** utils functions
*/

#include "../inc/fasta.h"

bool is_valid_molecule(char a)
{
    if (a == 'A' || a == 'G' || a == 'C' || a == 'T' || a == '\n'
        || a == 'a' || a == 'g' || a == 'c' || a == 't'
        || a == 'n' || a == 'N')
        return (true);
    return (false);
}

bool is_empty_line(char *str)
{
    if (str[0] == '\0' || str[0] == '\n'
        || (str[0] == ' ' && str[1] == '\n')
        || (str[0] == ' ' && str[1] == '\n'))
        return (true);
    return (false);
}

bool is_identifier(char *str)
{
    if (str == NULL)
        return (false);
    for (int i = 0; str[i]; i++)
        if (str[i] == '>')
            return (true);
    return (false);
}

void print_exit(char *msg, int nbr_exit)
{
    printf("%s\n", msg);
    exit(nbr_exit);
}
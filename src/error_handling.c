/*
** EPITECH PROJECT, 2020
** FASTAtools
** File description:
** error_handling
*/

#include "../inc/fasta.h"

bool is_number(char *str)
{
    for (int i = 0; str[i]; i++)
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (false);
    return (true);
}

void error(int ac, char **av)
{
    if (av[1] ==  NULL)
        print_exit("Tou must choose an option", 84);
    if (!is_number(av[1]))
        print_exit("Invalid option", 84);
    if (!(atoi(av[1]) > 0 && atoi(av[1]) < 8))
        print_exit("Invalid option. Choose the right one.", 84);
}
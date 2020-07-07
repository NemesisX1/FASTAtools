/*
** EPITECH PROJECT, 2020
** FASTAtools
** File description:
** FASTAtools
*/

#include "../inc/fasta.h"

void fastatools(int ac, char **av)
{
    char **tabs_content = capitalized_tabs();

    if (is_same_str(av[1], "1"))
        print_tabs(tabs_content);
    if (is_same_str(av[1], "2"))
        second_option(tabs_content);
    if (is_same_str(av[1], "3"))
        third_option(tabs_content);
    if (is_same_str(av[1], "4"))
        fourth_option(tabs_content, atoi(av[2]));
    if (is_same_str(av[1], "5"))
        fifth_option(tabs_content);
    if (is_same_str(av[1], "6"))
        sixth_option(tabs_content);
    if (is_same_str(av[1], "7"))
        seventh_option(tabs_content);
    free_tabs(tabs_content);
}
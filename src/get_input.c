/*
** EPITECH PROJECT, 2020
** FASTAtools
** File description:
** FASTAtools
*/

#include "../inc/fasta.h"

char *capitalize_and_clean(char *str)
{
    char *result = malloc(sizeof(char) * 1);
    int tmp = 1;
    int idx = 0;

    for (int i = 0; str[i]; i++) {
        if (is_valid_molecule(str[i])) {
            if (str[i] >= 'a' && str[i] <= 'z')
                result[idx] = str[i] - 32;
            else
                result[idx] = str[i];
            idx++;
            result = (char *)realloc(result, sizeof(char) * (idx + 1));
        }
    }
    result[idx] = '\0';
    return (result);
}

char **get_file_tabs(void)
{
    char **tab = malloc(sizeof(char *) * 1);
    size_t size = 0;
    int checker = 0;
    int i = 0;
    char *line = NULL;

    while (1) {
        checker = getline(&line, &size, stdin);
        if (checker < 0)
            break;
        if (!is_empty_line(line)) {
            tab[i] = strdup(line);
            i++;
            tab = (char **)realloc(tab, sizeof(char *) * (i + 1));
        }
    }
    free(line);
    tab[i] = NULL;
    return (tab);
}

char **capitalized_tabs(void)
{
    char **tab = get_file_tabs();

    for (int i = 0; tab[i] != NULL; i++)
        if (!is_identifier(tab[i]))
            tab[i] = capitalize_and_clean(tab[i]);
    return (tab);
}

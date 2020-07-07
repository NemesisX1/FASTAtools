/*
** EPITECH PROJECT, 2020
** FASTAtools
** File description:
** string_ops
*/

#include "../inc/fasta.h"

char *clean_str(char *str)
{
    char *result = malloc(sizeof(char) * 1);
    int idx = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] != '\n' && str[i] != ' ') {
            result[idx] = str[i];
            idx++;
            result = realloc(result, sizeof(char) * (idx + 1));
        }
    }
    result[idx] = '\0';
    return (result);
}

char *my_revstr(char *str)
{
    char tmp = 0;
    int len = strlen(str);
    char *revstr = NULL;
    int i = 0;

    if (str == NULL)
        return (NULL);
    revstr = malloc(len + 2);
    for (int j = len - 1; i < len + 1; i++, j--)
        revstr[i] = str[j];
    revstr[i] = '\0';
    return (revstr);
}

char *fuse_str(char *a, char *b)
{
    char *result = NULL;
    int idx = 0;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    else {
        result = (char *)malloc(sizeof(char) * (strlen(a) + strlen(b) + 1));
        for (int i = 0; a[i]; i++, idx++)
            result[idx] = a[i];
        for (int i = 0; b[i]; i++, ++idx)
            result[idx] = b[i];
        result[idx] = '\0';
    }
    return (result);
}

bool is_same_str(char *a, char *b)
{
    int check = 0;
    int lena = 0;
    int lenb = 0;

    if (a == NULL || b == NULL)
        return (false);
    for (; a[lena]; lena++);
    for (; b[lenb]; lenb++);
    if (lena != lenb)
        return (false);
    for (int i = 0; a[i]; i++)
        if (a[i] != b[i])
            return (false);
    return (true);
}

void free_tabs(char **tabs)
{
    for (int i = 0; tabs[i] != NULL; i++)
        free(tabs[i]);
    free(tabs);
}
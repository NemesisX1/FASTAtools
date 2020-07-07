/*
** EPITECH PROJECT, 2020
** ref_tabs
** File description:
** ref_tabs
*/

#include <unistd.h>

typedef struct name
{
    char ref;
    char *name[10];
}ref_name_t;

ref_name_t ref_tabs[21] = { {'A', {"GCT", "GCC", "GCA", "GCG", NULL}},
                            {'C', {"TGT", "TGC", NULL}},
                            {'D', {"GAT", "GAC", NULL}},
                            {'E', {"GAA", "GAG", NULL}},
                            {'F', {"TTT", "TTC", NULL}},
                            {'G', {"GGT", "GGC", "GGA", "GGG", NULL}},
                            {'H', {"CAT", "CAC", NULL}},
                            {'I', {"ATT", "ATC", "ATA", NULL}},
                            {'K', {"AAA", "AAG", NULL}},
                            {'L', {"TTA", "TTG", "CTT", "CTC", "CTA",
                            "CTG", NULL}},
                            {'M', {"ATG", NULL}},
                            {'N', {"AAT", "AAC", NULL}},
                            {'P', {"CCT", "CCC", "CCA", "CCG", NULL}},
                            {'Q', {"CAA", "CAG", NULL}},
                            {'R', {"AGA", "AGG", "CGT", "CGC", "CGA",
                            "CGG", NULL}},
                            {'S', {"TCT", "TCC", "TCA", "TCG", "AGT",
                            "AGC", NULL}},
                            {'T', {"ACT", "ACC", "ACA", "ACG", NULL}},
                            {'V', {"GTT", "GTC", "GTA", "GTG", NULL}},
                            {'W', {"TGG", NULL}},
                            {'Y', {"TAT", "TAC", NULL}} };

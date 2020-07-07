/*
** EPITECH PROJECT, 2020
** FASTAtools
** File description:
** include file
*/

#ifndef FASTA_H_
#define FASTA_H_

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

/* LIBS */

///condon_divider.c///
char **codon_divider(char *seq);
char **codons_seq(char *seq);

///string_ops.c ///
bool is_same_str(char *a, char *b);
char *fuse_str(char *a, char *b);
char *my_revstr(char *str);
char *clean_str(char *str);
void free_tabs(char **tabs);
char *get_string_from_pos(char *str, int pos);

///utils.c///
bool is_valid_molecule(char a);
bool is_empty_line(char *str);
bool is_identifier(char *str);
void print_exit(char *msg, int nbr_exit);
char **get_seq_tabs(char **tabs_content);

///prinf.c//
void my_printf(const char *s, ...);

///get_input.c///
char *capitalize_and_clean(char *str);
char **get_file_tabs(void);
char **capitalized_tabs(void);

/// printer.c///
void print_tabs(char **tabs);
void print(char **tabs, char *end);

///error_handling.c///
bool is_number(char *str);
void error(int ac, char **av);

///fasta_tools.c///
void fastatools(int ac, char ** av);

///options///
void second_option(char **tabs_content);
void third_option(char **tabs_content);
void fourth_option(char **tabs_content, int k);
char *get_k_from_pos(char *str, int pos, int k);
void fifth_option(char **tabs_content);
void sixth_option(char **tabs_content);
void seventh_option(char **tabs_content);
bool is_here_codon(char *seq, char *codon, int pos_in_seq);
void *get_reversed_complement(char *sequence);

///get_coding_seq.c///
char **get_coding_sequence(char **tabs_content);
int  decide_text(char *tmp);
int printer(char *codon);

///sort_word.c///
char *my_strdup(char *src);
static int check_swap(char **tab, int i);
void my_sort_word_array(char **tab);

#endif /* !FASTA_H_ */

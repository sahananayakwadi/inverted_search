#ifndef TYPES_H
#define TYPES_H
#include <stdio.h>

typedef struct sub_node
{
    char file_name[20];
    int word_count;
    struct sub_node *link;
} SubNode;

typedef struct main_node
{
    char word[20];
    int file_count;
    int word_count;
    SubNode *sub_link;
    struct main_node *main_link;
} MainNode;

#define HASH_SIZE 27

int get_index(char ch);

int create_database(int argc, char *argv[], MainNode *hash_table[]);

int read_datafile(FILE *file, MainNode *hash_table[], char *filename);

int store_word(char *word, char *filename, MainNode *hash_table[]);

void display_database(MainNode *hash_table[]);

int save_databasefile(MainNode *hash_table[]);

int read_databasefile(MainNode *hash_table[]);

int update_database(MainNode *hash_table[], char *filename);

int search_database(MainNode *hash_table[], char *word);

#endif
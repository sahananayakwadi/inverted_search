#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"


int create_database(int argc, char *argv[], MainNode *hash_table[])
{
    int i;

    printf("\nCreating database...\n");

    for(i = 1; i < argc; i++)
    {
        FILE *fp = fopen(argv[i], "r");

        if(fp == NULL)
        {
            printf("INFO: Unable to open %s\n", argv[i]);
            return 1;
        }

        printf("Reading %s\n", argv[i]);

        read_datafile(fp, hash_table, argv[i]);

        fclose(fp);
    }

    printf("Database creation completed\n");

    return 0;
}


int read_datafile(FILE *file, MainNode *hash_table[], char *filename)
{
    char word[27];
    int index = 0;
    char ch;

    while((ch = fgetc(file)) != EOF)
    {
        if((ch >= 'A' && ch <= 'Z') ||
           (ch >= 'a' && ch <= 'z'))
        {
            if(index < 26)
            {
                word[index] = ch;
                index++;
            }
        }
        else
        {
            if(index > 0)
            {
                word[index] = '\0';

                store_word(word, filename, hash_table);

                index = 0;
            }
        }
    }

    if(index > 0)
    {
        word[index] = '\0';

        store_word(word, filename, hash_table);
    }

    return 0;
}


int store_word(char *word, char *filename, MainNode *hash_table[])
{
    int index = get_index(word[0]);
    MainNode *temp = hash_table[index];
    MainNode *prev = NULL;

    while(temp != NULL)
    {
        if(strcmp(temp->word, word) == 0)
        {

            SubNode *sub_temp = temp->sub_link;

    while(sub_temp != NULL)
    {
        if(strcmp(sub_temp->file_name, filename) == 0)
        {
        sub_temp->word_count++;
        return 0;
        }

    sub_temp = sub_temp->link;
    }
            SubNode *new_sub = malloc(sizeof(SubNode));

            if(new_sub == NULL)
            {
                return 1;
            }

        strcpy(new_sub->file_name, filename);
        new_sub->word_count = 1;
        new_sub->link = NULL;


            if(temp->sub_link == NULL)
            {
                temp->sub_link = new_sub;
            }
            else
            {
                sub_temp = temp->sub_link;

                while(sub_temp->link != NULL)
                {
                    sub_temp = sub_temp->link;
                }

                sub_temp->link = new_sub;
            }

            temp->file_count++;

            return 0;
        }

        if(strcmp(temp->word, word) > 0)
        {
            break;
        }

        prev = temp;
        temp = temp->main_link;
    }

    MainNode *new_main = malloc(sizeof(MainNode));

    if(new_main == NULL)
    {
        return 1;
    }

    strcpy(new_main->word, word);

    new_main->file_count = 1;
    new_main->word_count = 1;
    new_main->sub_link = NULL;
    new_main->main_link = NULL;

    SubNode *new_sub = malloc(sizeof(SubNode));

    if(new_sub == NULL)
    {
        free(new_main);
        return 1;
    }

    strcpy(new_sub->file_name, filename);
    new_sub->word_count = 1;
    new_sub->link = NULL;

    new_main->sub_link = new_sub;

   if(prev == NULL)
{
    new_main->main_link = hash_table[index];
    hash_table[index] = new_main;
}
else
{
    new_main->main_link = temp;
    prev->main_link = new_main;
}

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"


int update_database(MainNode *hash_table[], char *filename)
{
    FILE *fp;

    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("INFO: Unable to open %s\n", filename);
        return 1;
    }

    printf("\nUpdating database using %s\n", filename);

    read_datafile(fp, hash_table, filename);

    fclose(fp);

    printf("Database updated successfully\n");

    return 0;
}


int read_databasefile(MainNode *hash_table[])
{
    FILE *fp;
    char line[500];

    fp = fopen("DatabaseFile.txt", "r");

    if(fp == NULL)
    {
        printf("INFO: DatabaseFile.txt not found\n");
        return 1;
    }

    while(fgets(line, sizeof(line), fp) != NULL)
    {
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, ";");

        if(token == NULL)
            continue;

        token = strtok(NULL, ";");

        if(token == NULL)
            continue;

        char word[20];
        strcpy(word, token);

        token = strtok(NULL, ";");

        if(token == NULL)
            continue;

        while(1)
        {
            token = strtok(NULL, ";");

            if(token == NULL || strcmp(token, "#") == 0)
                break;

            char filename[20];
            strcpy(filename, token);

            token = strtok(NULL, ";");

            if(token == NULL)
                break;

            int word_count = atoi(token);

            int index = get_index(word[0]);

            MainNode *main_temp = hash_table[index];

            while(main_temp != NULL)
            {
                if(strcmp(main_temp->word, word) == 0)
                    break;

                main_temp = main_temp->main_link;
            }

            if(main_temp == NULL)
            {
                store_word(word, filename, hash_table);

                main_temp = hash_table[index];

                while(main_temp != NULL)
                {
                    if(strcmp(main_temp->word, word) == 0)
                        break;

                    main_temp = main_temp->main_link;
                }
            }

            if(main_temp != NULL)
            {
                SubNode *sub_temp = main_temp->sub_link;

                while(sub_temp != NULL)
                {
                    if(strcmp(sub_temp->file_name, filename) == 0)
                    {
                        sub_temp->word_count = word_count;
                        break;
                    }

                    sub_temp = sub_temp->link;
                }
            }
        }
    }

    fclose(fp);

    printf("\nDatabase loaded successfully\n");

    return 0;
}
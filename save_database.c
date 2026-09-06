#include<stdio.h>
#include "types.h"


#include <stdio.h>
#include "types.h"

#include <stdio.h>
#include "types.h"

int save_databasefile(MainNode *hash_table[])
{
    FILE *fp;

    fp = fopen("DatabaseFile.txt", "w");

    if(fp == NULL)
    {
        printf("INFO: Unable to create database file\n");
        return 1;
    }

    int index;

    for(index = 0; index < HASH_SIZE; index++)
    {
        MainNode *main_temp = hash_table[index];

        while(main_temp != NULL)
        {
            fprintf(fp, "#%d;%s;%d;",
                    index,
                    main_temp->word,
                    main_temp->file_count);

            SubNode *sub_temp = main_temp->sub_link;

            while(sub_temp != NULL)
            {
                fprintf(fp, "%s;%d;",
                        sub_temp->file_name,
                        sub_temp->word_count);

                sub_temp = sub_temp->link;
            }

            fprintf(fp, "#\n");

            main_temp = main_temp->main_link;
        }
    }

    fclose(fp);

    printf("\nDatabase file created successfully\n");

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"

void display_database(MainNode *hash_table[])
{
    int index;

    for(index = 0; index < HASH_SIZE; index++)
    {
        MainNode *main_temp = hash_table[index];

        while(main_temp != NULL)
        {
            printf("\nIndex : %d", index);
            printf("\nWord : %s", main_temp->word);
            printf("\nFile count : %d", main_temp->file_count);

            SubNode *sub_temp = main_temp->sub_link;

            while(sub_temp != NULL)
            {
                printf("\nFile : %s", sub_temp->file_name);
                printf("\nWord count : %d", sub_temp->word_count);

                sub_temp = sub_temp->link;
            }

            printf("\n");

            main_temp = main_temp->main_link;
        }
    }
}
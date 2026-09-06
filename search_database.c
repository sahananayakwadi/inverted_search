#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"

int search_database(MainNode *hash_table[], char *word)
{
    int index = get_index(word[0]);

    MainNode *temp = hash_table[index];

    while(temp != NULL)
    {
        if(strcmp(temp->word, word) == 0)
        {
            printf("\nIndex : %d\n", index);
            printf("Word : %s\n", temp->word);
            printf("File count : %d\n", temp->file_count);

            SubNode *sub_temp = temp->sub_link;

            while(sub_temp != NULL)
            {
                printf("File : %s\n", sub_temp->file_name);
                printf("Word count : %d\n", sub_temp->word_count);

                sub_temp = sub_temp->link;
            }

            return 0;
        }

        temp = temp->main_link;
    }

    printf("\nWord '%s' not found\n", word);

    return 1;
}
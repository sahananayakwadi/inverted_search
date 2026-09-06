#include <stdio.h>
#include <string.h>
#include "types.h"

int main(int argc, char *argv[])
{
    MainNode *hash_table[HASH_SIZE] = {NULL};
    int choice;
    char word[20];
    char filename[50];

    while(1)
    {
        printf("\n1. Create Database\n");
        printf("2. Display Database\n");
        printf("3. Search Database\n");
        printf("4. Update Database\n");
        printf("5. Save Database\n");
        printf("6. Load Database\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(argc < 2)
                {
                    printf("No input files provided\n");
                    break;
                }

                create_database(argc, argv, hash_table);
                break;

            case 2:
                display_database(hash_table);
                break;

            case 3:
                printf("Enter word to search: ");
                scanf("%19s", word);

                search_database(hash_table, word);
                break;

            case 4:
                printf("Enter file name to update: ");
                scanf("%49s", filename);

                update_database(hash_table, filename);
                break;

            case 5:
                save_databasefile(hash_table);
                break;
            case 6:
                read_databasefile(hash_table);
                break;

            case 7:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
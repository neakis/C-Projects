/*
    Author: Nerijus Akelaitis
    Date: 2021-01-26 version 2.0
    Short information: deletes selected data from  the input information

*/
#include "./timetable.h"

void deleteOne() {
    int lineNum;
    FILE *fp1 = fopen(BIN_NAME, "rb");
    if (!fp1) {
        printf("%s", UNABLE_TO_OPEN);
        exit (1);
    }
    fseek(fp1, 0L, SEEK_END);
    int size = ftell(fp1);
    fseek(fp1, 0L, SEEK_SET);

    FILE * fp2 = fopen("temp.bin", "wb");
    if (!fp2) {
        printf("%s", UNABLE_TO_OPEN);
        fclose(fp1);
        exit (1);
    }

    printf("Here is the data:\n");
    loadData();

    printf("\nInput the line you want to remove: ");
    scanf("%d", &lineNum);
    lineNum--;

    Data *buffer = malloc(size);
    fread(buffer, sizeof(Data), size / sizeof(struct Data), fp1);
    for (int i = 0; i < size / sizeof(struct Data); ++i) {
        if (i != lineNum) {
            fwrite(&buffer[i], sizeof(struct Data), 1, fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    // Replacing previous file to the one with deleted line
    remove(BIN_NAME);
    rename("temp.bin", BIN_NAME);
    free(buffer);

    printf("\nHere is new data: \n");
    loadData();
    printf("\nInformation has been deleted.\n %s", CONTINUE_MSG);
}

void delData() {
    int option = getChoice(0, 2);
        switch (option) {
            case 0:
                // Return to menu
                system("cls");
                showMenu();
                break;
            case 1:
                // Delete the whole file
                if (remove(BIN_NAME) == 0)
                    printf("\nDeleted successfully.\n %s", CONTINUE_MSG);
                else printf("\nUnable to delete the file. %s\n", RETURN_TO_MENU);
                    break;
            case 2:
                // Delete selected line
                system("cls");
                deleteOne();
                break;
    }
}

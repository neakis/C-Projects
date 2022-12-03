/*
    Author: Nerijus Akelaitis
    Date: 2021-01-26 version 2.0
    Short information: edits selected data from the input information

*/
#include "./timetable.h"

Data makeStruct(char* name, char* day, char* location, char* time){
    Data a;
    strcpy(a.name, name);
    strcpy(a.day, day);
    strcpy(a.location, location);
    strcpy(a.time, time);
    return a;
}

void editData() {
    Data structToEdit;
    int lineNumEdit;

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
    printf("\nInput the line you want to edit: ");
    scanf("%d", &lineNumEdit);
    lineNumEdit--;

    Data *buffer = malloc(size);
    fread(buffer, sizeof(Data), size / sizeof(struct Data), fp1);
    for (int i = 0; i < size / sizeof(struct Data); ++i) {
        if (i != lineNumEdit) {
            fwrite(&buffer[i], sizeof(struct Data), 1, fp2);
        } else {
            printf("\nSelect a section to edit: \n");
            printf("Enter 1 to change the name\n");
            printf("Enter 2 to change the day of the week\n");
            printf("Enter 3 to change the location\n");
            printf("Enter 4 to change the time of lecture\n\n");

            int section = getChoice(1, 4);
            switch (section) {
            case 1:
                // Change the name
                structToEdit = makeStruct(getName(), buffer[i].day, buffer[i].location, buffer[i].time);
                break;
            case 2:
                // Change the day of the week
                structToEdit = makeStruct(buffer[i].name, getDay(), buffer[i].location, buffer[i].time);
                break;
            case 3:
                // Change the location
                structToEdit = makeStruct(buffer[i].name, buffer[i].day, getLocation(), buffer[i].time);
                break;
            case 4:
                // Change the time of lecture
                structToEdit = makeStruct(buffer[i].name, buffer[i].day, buffer[i].location, getTime());
                break;
            }
            fwrite(&structToEdit, sizeof(struct Data), 1, fp2);
        }
    }

    fclose(fp1);
    fclose(fp2);
    // Replacing previous file to the one with edited information
    remove(BIN_NAME);
    rename("temp.bin", BIN_NAME);
    free(buffer);

    printf("\n");

    printf("Here is the new data: \n");
    loadData();
    printf("\n\nInformation has been updated. (Press 2 to edit next entry, press 1 to return to menu)\n");
}

/*
    Author: Nerijus Akelaitis
    Date: 2021-01-26 version 2.0
    Short information: saves and loads the correct information to binary file

*/
#include "./timetable.h"

void saveData(Data d) {
    FILE *write = fopen(BIN_NAME, "a+b");
    if (write == NULL) {
        printf("%s", ERROR_MSG);
        exit (1);
    }
    fwrite(&d, sizeof(struct Data), 1, write);
    fclose(write);
}

void loadData() {
    FILE *read = fopen(BIN_NAME, "rb");
    if (read == NULL) {
        printf("%s", ERROR_MSG);
    } else {
        fseek(read, 0L, SEEK_END);
        int size = ftell(read);
        fseek(read, 0L, SEEK_SET);

        Data *buffer = malloc(size);
        fread(buffer, sizeof(Data), size / sizeof(struct Data), read);
        for (int i = 0; i < size / sizeof(struct Data); ++i) {
            printf("\n%d. Name: %-25s Day: %-20s Location: %-25s Time: %-10s\n",(i+1), buffer[i].name, buffer[i].day, buffer[i].location, buffer[i].time);
        }
        fclose(read);
        free(buffer);
    }
}

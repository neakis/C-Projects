/*
    Author: Nerijus Akelaitis
    Date: 2021-01-26 version 2.0
    Short information: validates the input information

*/
#include "./timetable.h"

int getChoice(int low, int high) {
    bool b;
    char c;
    int choice = 0;
    while (1) {
        scanf("%d", &choice);
        b = false;
        c = getchar();
        while (c != '\n') {
            b = true;
            c = getchar();
        } if (b) {
            printf("Letters or symbols not allowed! Try again.\n\n");
        } else if (choice >= low && choice <= high) {
            printf("Proceeding...\n");
            break;
        } else {
            printf("Your entered choice exceeds the boundaries. Try again.\n\n");
        }
    }
    return choice;
}

bool isSymbol(char* str) {
        return !(isalpha(str[0]));
}

char* getName() {
    char* name = malloc(BUFFERSIZE);
    unsigned size;
    printf("Enter lecture's name: \n");
    while (1) {
        fgets(name, BUFFERSIZE + 2, stdin);
        fflush(stdin);
        size = strlen(name);
        name[size - 1] = '\0';

        if (size > BUFFERSIZE) {
            printf("%s", OVER_CAPACITY);
        } else if (strlen(name) <= 0) {
            printf("%s", EMPTY_MSG);
        } else if (isSymbol(name)) {
            printf("%s", NAME_INPUT);
        } else {
            printf("%s", INPUT_ACCEPTED);
            break;
        }
    }
    return name;
}

char* getDay() {
    char* day = malloc(BUFFERSIZE);
    unsigned size;
    printf("\nEnter day of the week (e.g., Monday, Tuesday): \n");
    while (1) {
        fgets(day, BUFFERSIZE + 2, stdin);
        fflush(stdin);
        size = strlen(day);
        day[size - 1] = '\0';

        if (size > BUFFERSIZE) {
            printf("%s", OVER_CAPACITY);
        } else if (strlen(day) <= 0) {
            printf("%s", EMPTY_MSG);
        } else if (isSymbol(day)) {
            printf("%s", NAME_INPUT);
        } else {
            printf("%s", INPUT_ACCEPTED);
            break;
        }
    }
    return day;
}

char* getLocation() {
    char* location = malloc(BUFFERSIZE);
    unsigned size;
    printf("\nEnter location (e.g., Remote lecture, Naugarduko g. 24): \n");
    while (1) {
        fgets(location, BUFFERSIZE + 2, stdin);
        fflush(stdin);
        size = strlen(location);
        location[size - 1] = '\0';

        if (size > BUFFERSIZE) {
            printf("%s", OVER_CAPACITY);
        } else if (strlen(location) <= 0) {
            printf("%s", EMPTY_MSG);
        } else if (isSymbol(location)) {
            printf("%s", LOCATION_INPUT);
        } else {
            printf("%s", INPUT_ACCEPTED);
            break;
        }
    }
    return location;
}
// New string of two characters
char* subString(char* str, int startPos) {
    char* subStr = malloc(3);
    strncpy(subStr, str + startPos, 2);
    subStr[2] = '\0';
    return subStr;
}
// Convert string to integer
int strValue(char* str) {
    if (strncmp(str, "0", 1) < 0 || strncmp(str, "9", 1) > 0) {
        return -1;
    }
    if (strncmp(str + 1, "0", 1) < 0 || strncmp(str + 1, "9", 1) > 0) {
        return -1;
    }
    return atoi(str);
}

char* getTime() {
    char* time = malloc(BUFFERSIZE);
    unsigned size;
    printf("\nEnter duration of lecture in format (hh:mm-hh:mm) (e.g., 08:30-10:00): \n");
    while (1) {
        fgets(time, BUFFERSIZE + 2, stdin);
        fflush(stdin);
        size = strlen(time);
        time[size - 1] = '\0';

        if (size > BUFFERSIZE) {
            printf("%s", OVER_CAPACITY);
        } else if (strlen(time) <= 0) {
            printf("%s", EMPTY_MSG);
        } else
            if (size == 12 && time[2] == ':' && time[5] == '-' && time[8] == ':' &&
            strValue(subString(time, 0)) >= 0 && strValue(subString(time, 0)) < 24 &&
            strValue(subString(time, 3)) >= 0 && strValue(subString(time, 3)) < 60 &&
            strValue(subString(time, 6)) >= 0 && strValue(subString(time, 6)) < 24 &&
            strValue(subString(time, 9)) >= 0 && strValue(subString(time, 9)) < 60) {

                if (strValue(subString(time, 6)) > strValue(subString(time, 0)) ||
                    ((strValue(subString(time, 6)) == strValue(subString(time, 0))) &&
                    (strValue(subString(time, 9)) >= strValue(subString(time, 3))))) {
                        printf("%s", INPUT_ACCEPTED);
                        break;
                    } else {
                        printf("Lecture cannot finish sooner than it starts. Try again.\n");
                    }
            } else {
                printf("Duration was put in wrong format. Try again.\n");
            }
    }
    return time;
}

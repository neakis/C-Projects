/*
    Author: Nerijus Akelaitis
    Date: 2021-01-26 version 2.0
    Short information: printouts of information and menu

*/
#include "./timetable.h"

void userInformation() {
    printf("Hello, student! Let me help you to construct your timetable.\n");
    printf("To fill the timetable, program needs correct information. Please follow the steps and enter what is needed.\n\n");
}

void showMenu() {
    userInformation();
    printf("Here is the menu:\n");
    printf("0. Close the program.\n");
    printf("1. Call menu.\n\n");
    printf("2. Edit inserted data.\n");
    printf("3. Show inserted data.\n");
    printf("4. Delete inserted data.\n");
    printf("5. Enter data.\n\n");
}

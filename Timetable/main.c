/*
    Author: Nerijus Akelaitis
    Date: 2021-01-26 version 2.0
    Short information: main function, that executes menu's options

*/
#include "./timetable.h"

void exitProgram() {
    system("taskkill/IM cb_console_runner.exe");
}

int main()
{
    startLogging();
    atexit(endLogging);
    void runTests(); // run assert tests
    showMenu();
    char* name;
    char* day;
    char* location;
    char* time;
    // Menu options
    do {
    int choice = getChoice(0, 5);
         switch (choice) {
            case 0:
                exitProgram();
                break;
            case 1:
                system("cls");
                showMenu();
                break;
            case 2:
                system("cls");
                editData();
                break;
            case 3:
                system("cls");
                printf("Saved data:\n");
                loadData();
                printf("%s", CONTINUE_MSG);
                break;
            case 4:
                system("cls");
                printf("Enter 0 if you want to return to the menu.\n");
                printf("Enter 1 if you want to delete the whole file.\n");
                printf("Enter 2 if you want to delete specific line from the file.\n");
                delData();
                break;
            case 5:
                system("cls");
                name = getName();
                day = getDay();
                location = getLocation();
                time = getTime();
                saveData(makeStruct(name, day, location, time));
                printf("\nInformation has been saved.\n %s", CONTINUE_MSG);
                break;
            default:
                printf("Unreachable code. %d", choice);
                return 0;
        }
    } while (true);

    return 0;
}

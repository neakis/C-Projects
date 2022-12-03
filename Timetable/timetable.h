/*
    Author: Nerijus Akelaitis
    Date: 2021-01-26 version 2.0
    Short information: header, that includes all the libraries, functions' prototypes

*/
#ifndef TIMETABLE_H // prevent the file from being included more than once
#define TIMETABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>

#define BUFFERSIZE 100

// #define assert(ignore) ((void) 0)

#define BIN_NAME "timetable.bin"

#define CONTINUE_MSG "\nYou may continue. (1 to call menu, 5 to enter data)\n"
#define ERROR_MSG "Error opening file. Enter 1 to return to menu.\n"
#define EMPTY_MSG "Field cannot be empty. Try again.\n"
#define RETURN_TO_MENU "Enter 1 to return to menu.\n"
#define NAME_INPUT "Should be a word, not a symbol/number. Try again.\n"
#define LOCATION_INPUT "Location cannot start with a symbol/number. Try again.\n"
#define INPUT_ACCEPTED "Input accepted.\n"
#define UNABLE_TO_OPEN "File not found or unable to open the input file. Reopen the program and insert some data first.\n"
#define OVER_CAPACITY "Input exceeds the capacity. Try again.\n"

// Timetable data (name, day, location, time of the lecture)
typedef struct Data {
    char name[BUFFERSIZE];
    char day[BUFFERSIZE];
    char location[BUFFERSIZE];
    char time[BUFFERSIZE];
} Data;

// Functions:

// save/load
Data makeStruct(char* name, char* day, char* location, char* time);
void saveData(Data d);
void loadData();

// change
void editData();
void delData();

// menu
void showMenu();
void userInformation();
void exitProgram();

// input
int getChoice(int low, int high);
bool isSymbol(char* str);
int strValue(char* str);
char* subString(char* str, int startPos);

char* getName();
char* getDay();
char* getLocation();
char* getTime();

// logging
clock_t startLogging();
void endLogging();

// unit tests
void unitTests();

#endif // TIMETABLE_H

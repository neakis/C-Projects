/*
    Author: Nerijus Akelaitis
    Date: 2021-01-26 version 2.0
    Short information: unit tests check if there are any errors in functions

*/
#include "./timetable.h"

void testIsSymbol() {
    assert(isSymbol("a") == false); // finds if the input is a symbol/number (true), or a letter (false)
    assert(isSymbol("1") == true);
}

void testStrValue() {
    assert(strValue("a1") == -1); // returns number if input is numeric, otherwise returns -1
    assert(strValue("1a") == -1);
    assert(strValue("11") == 11);
}

void testSubString() {
    assert(strcmp(subString("12:30-14:00", 0), "12") == 0); // takes two numbers from the given position.
    assert(strcmp(subString("11:00-14:00", 3), "00") == 0); // equals to zero, if both strings are identical (true)
}

void runTests() {
    testIsSymbol();
    testStrValue();
    testSubString();
}

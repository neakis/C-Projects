/*
    Author: Nerijus Akelaitis
    Date: 2021-01-26 version 2.0
    Short information: prints out total time elapsed, while program was running

*/
#include "./timetable.h"

static clock_t beginTime = NULL;

clock_t startLogging() {
    clock_t startTime = clock();
    FILE *fptr = fopen("timetable.log", "a");
    if (fptr != NULL) {
        time_t now = time(0); // get the system time
        struct tm tm = *localtime(&now); // convert to local time
        fprintf(fptr, "Program start time: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    }
    fclose(fptr);
    return startTime;
}

void endLogging() {
    clock_t endTime = clock();
    FILE *fptr = fopen("timetable.log", "a");
    if (fptr != NULL) {
        time_t now = time(0); // system time
        struct tm tm = *localtime(&now); // system time converted to local time
        fprintf(fptr, "Program end time: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
        fprintf(fptr, "Total time elapsed: %.2f seconds\n\n", ((double)(endTime - beginTime) / CLOCKS_PER_SEC));
    }
    fclose(fptr);
}

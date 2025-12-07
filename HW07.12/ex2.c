/*
    Ex2: Write a C program that:
      – Retrieves the current date and time.
      – Displays the date in the format: YYYY-MM-DD.
      – Displays the time in the format: HH:MM:SS.
*/

#include <stdio.h>
#include <time.h>

int main() {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);

    char date[11];
    strftime(date, sizeof(date), "%Y-%m-%d", t);

    char _time[9];
    strftime(_time, sizeof(_time), "%H:%M:%S", t);

    printf("%s\n%s\n", date, _time);
    return 0;
}

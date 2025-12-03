/*
    Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.
*/

#include <stdio.h>
#include <string.h>

int main() {
    while (1) {
        char string[512];
        printf("Enter a string (/q to quit): ");
        scanf(" %512[^\n]", string);
        if (strcmp(string, "/q") == 0) {
            printf("Bye :(\n");
            break;
        }
        if (strlen(string) >= 80) {
            printf("%s\n", string);
        }
    }
    return 0;
}
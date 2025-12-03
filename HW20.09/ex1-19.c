/*
    Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to write
    a program that reverses its input a line at a time.
*/

#include <stdio.h>
#include <string.h>

void reverse(char str[]) {
    for (int i = (int)strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    while (1) {
        char string[256];
        printf("Enter a string (/q to quit): ");
        scanf(" %63[^\n]", string);
        if (strcmp(string, "/q") == 0) {
            printf("Bye :(\n");
            break;
        }
        reverse(string);
    }
    return 0;
}
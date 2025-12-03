/*
    Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the
    histogram with the bars horizontal; a vertical orientation is more challenging.
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

void getWords(char string[]) {
    char word[24];
    int wordIndex = 0,
        wordCount = 0,
        lettersCount[255] = {0};
    for (int i = 0; i <= strlen(string); i++) {
        if (!isalnum(string[i]) || string[i] == '\0') {
            word[wordIndex] = '\0';

            if (word[0] != '\0')
                lettersCount[wordCount] = (int)strlen(word);
            memset(word, 0, sizeof(word));
            wordIndex = 0;
            wordCount++;
        }
        else {
            word[wordIndex++] = string[i];
        }
    }

    for (int i = 0; i < wordCount; i++) {
        if (lettersCount[i] == 0) continue;
        printf("%d letters: *", lettersCount[i]);
        for (int j = i + 1; j < wordCount; j++) {
            if (lettersCount[j] == 0) continue;
            if (lettersCount[i] == lettersCount[j]) {
                printf("*");
                lettersCount[j] = 0;
            }
        }
        printf("\n");
        lettersCount[i] = 0;
    }
}

int main() {
    char string[64];
    while (1) {
        printf("Enter a string (/q to quit): ");
        scanf(" %64[^\n]", string);
        if (strcmp(string, "/q") == 0) {
            printf("Bye :(\n");
            break;
        }
        getWords(string);
    }
    return 0;
}
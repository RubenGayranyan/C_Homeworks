/*
    Write a C program that checks if a given string is a palindrome. A
    palindrome is a word, phrase, number, or other sequence of
    characters that reads the same forward and backward, ignoring
    spaces, punctuation, and capitalization. Use functions to
    implement the palindrome checking logic.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char string[]);

int main() {
    char str[64];
    printf("Please, enter the string: ");
    fgets(str, sizeof(str), stdin);
    printf("Provided string is%s Palindrome", (isPalindrome(str) == 0) ? (" not") : (""));
    return 0;
}

int isPalindrome(char string[]) {
    char newStr[64];
    int wordIndex = 0;
    for (int i = 0; i <= strlen(string); i++) {
        if (isalnum(string[i])) {
            newStr[wordIndex++] = string[i];
        }
    }

    newStr[wordIndex] = '\0';

    for (int i = 0; i < strlen(newStr); i++) {
        if (newStr[i] != newStr[strlen(newStr) - i - 1])
            return 0;
    }
    return 1;
}
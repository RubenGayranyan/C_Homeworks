/*
    Ex1: Write a C program that asks the user for two strings (maximum length 100 each) andperforms the following operations:
      – Concatenates the strings and prints the result.
      – Compares the two strings and prints whether they are the same or different.
      – Finds the length of each string and prints it.
      – Copies the first string into another variable and prints the copy.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE	100

void strClear(char* str);
void strConcate(char* str1, const char* str2);
bool strCompare(const char* str1, const char* str2);
void strCopy(char** dest, const char* src);
void freeMemory(void* pointer);

int main() {
    char string1[MAX_SIZE],
        string2[MAX_SIZE];
    printf("Input the first string (max. 100 characters): ");
    fgets(string1, MAX_SIZE, stdin);
    strClear(string1);

    printf("Input the second string (max. 100 characters): ");
    fgets(string2, MAX_SIZE, stdin);
    strClear(string2);
    
    strConcate(string1, string2);
    printf("Strings are %s\n", (strCompare(string1, string2) == true) ? ("the same") : ("different"));
    printf("String 1 length: %ld | String 2 length: %ld\n", strlen(string1), strlen(string2));

    char* _string1;
    strCopy(&_string1, string1);
    printf("%s", _string1);
    freeMemory(_string1);
    return 0;
}

void strClear(char* str) {
    if(strlen(str) > 0 && str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}

void strConcate(char* str1, const char* str2) {
    char* str = (char*)malloc(strlen(str1) + strlen(str2) + 1);
    if(!str) {
        printf("Memory allocation failed!");
        return;
    }
    str[0] = '\0';
    strcat(str, str1);
    strcat(str, str2);
    printf("%s\n", str);
    free(str);
}

bool strCompare(const char* str1, const char* str2) {
    return !(strcmp(str1, str2));
}

void strCopy(char** dest, const char* src) {
    *dest = (char*)malloc(strlen(src) + 1);
    if(*dest != NULL)
        strcpy(*dest, src);
}

void freeMemory(void* ptr) {
    free(ptr);
}

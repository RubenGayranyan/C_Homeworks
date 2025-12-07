/*
    Exercise 8-3. Design and write _flushbuf, fflush, and fclose.
*/

#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 10

int _flushbuf(int c, FILE *fp, char *buffer, int *count) {
    buffer[*count] = (char)c;
    (*count)++;

    if(*count >= BUFSIZE) {
        fwrite(buffer, 1, BUFSIZE, fp);
        *count = 0;
    }
    return c;
}

void fflush_custom(FILE *fp, char *buffer, int *count) {
    if(*count > 0) {
        fwrite(buffer, 1, *count, fp);
        *count = 0;
    }
}

void fclose_custom(FILE *fp, char *buffer, int *count) {
    fflush_custom(fp, buffer, count);
    fclose(fp);
}

int main() {
    FILE *fp = fopen("file.txt", "w");
    if(fp == NULL) {
        printf("File cannot be opened\n");
        return 1;
    }

    char buffer[BUFSIZE];
    int count = 0;

    char text[512];
    fgets(text, sizeof(text), stdin);

    for(int i = 0; text[i] != '\0'; i++) {
        _flushbuf(text[i], fp, buffer, &count);
    }

    fflush_custom(fp, buffer, &count);
    fclose_custom(fp, buffer, &count);
    printf("Done writing to file.txt\n");
    return 0;
}

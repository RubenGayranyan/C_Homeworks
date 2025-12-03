/*
    Write a C program that generates and prints a pyramid pattern of ‘*’
    characters based on user input number of rows. The program should
    take an integer as input (n) from the user and then generate a
    pyramid pattern of n rows. Use functions to implement the pattern
    generation.
*/

#include <stdio.h>

void drawTriangle(const short rows) {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= rows - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    unsigned short num;
    printf("Please, input the rows count: ");
    scanf("%hu", &num);
    drawTriangle(num);
    return 0;
}
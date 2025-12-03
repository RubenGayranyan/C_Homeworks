/*
    Create a C program for a simple calculator that can perform basic arithmetic operations:
    addition, subtraction, multiplication, and division. The program should display a menu to the
    user, allowing them to choose the operation they want to perform and then input two numbers to
    perform the chosen operation. After performing the operation, the program should display the
    result.
*/

#include <stdio.h>

void calculate(float a, float b, unsigned short op);

void progInit() {
    unsigned short operation;
    float a, b;
    printf("Hi! Choose the operation.\n");
    printf(" 1. Addition, 2. Subtraction, 3. Multiplication, 4. Division, 5. Quit (to exit the program): ");
    scanf("%hu", &operation);
    if (operation == 5)
        printf("Bye! :(");
    else {
        printf("Please input the numbers (Example: 1, 2): ");
        scanf("%f, %f", &a, &b);
        calculate(a, b, operation);
    }
}

int main() {
    progInit();
    return 0;
}

void calculate(const float a, const float b, const unsigned short op) {
    float res;
    switch (op) {
        case 1:
            res = a + b;
            break;
        case 2:
            res = a - b;
            break;
        case 3:
            res = a * b;
            break;
        case 4:
            res = a / b;
            break;
        default:
            res = 0;
            break;
    }
    printf("Result is: %.2f\n", res);
    progInit();
}
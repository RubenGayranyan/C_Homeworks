/*
    Create a C calculator program that provides the operators ‘+’, ‘-’,
    ‘*’, ‘/’, ‘%’ and reads the expressions in the postfix (reverse Polish)
    notation. After calculating the expression result it should print result
    and allow another expression to be entered by the user. The
    program should exit when EOF is read.
*/

#include <stdio.h>
#include <string.h>


double calculator(const char exp[]);

int main() {
    char expression[32];
    while (1) {
        printf("Please, enter the expression (/q to exit): ");
        fgets(expression, sizeof(expression), stdin);
        expression[strcspn(expression, "\n")] = '\0';
        if (strcmp(expression, "/q") == 0)
            break;
        printf("Result: %f\n", calculator(expression));
    }
    return 0;
}

double calculator(const char exp[]) {
    float a, b;
    char c;
    sscanf(exp, "%f %f %c", &a, &b, &c);
    switch (c) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '%':
            return (int)a % (int)b;
        default:
            return -1;
    }
}
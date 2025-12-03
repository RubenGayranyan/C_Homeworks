/*
    Create a C calculator program that provides the operators ‘+’, ‘-’,
    ‘*’, ‘/’, ‘%’ and reads the expressions in the infix notation. After
    calculating the expression result it should print result and allow
    another expression to be entered by the user. The program should
    exit when EOF is read.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

const char* expr;

double parseExpr();

double parseNumber() {
    double num = 0;
    while (isdigit(*expr)) {
        num = num * 10 + (*expr - '0');
        expr++;
    }
    return num;
}

double parseFactor() {
    if (*expr == '(') {
        expr++;
        const double val = parseExpr();
        expr++;
        return val;
    }
    return parseNumber();
}

double parseTerm() {
    double val = parseFactor();
    while (*expr == '*' || *expr == '/' || *expr == '%') {
        const char op = *expr;
        expr++;
        if (op == '*')
            val *= parseFactor();
        else if (op == '%')
            val = (int)val % (int)parseFactor();
        else
            val /= parseFactor();
    }
    return val;
}

double parseExpr() {
    double val = parseTerm();
    while (*expr == '+' || *expr == '-') {
        const char op = *expr;
        expr++;
        if (op == '+')
            val += parseTerm();
        else
            val -= parseTerm();
    }
    return val;
}

int main() {
    char input[256];
    while (1) {
        printf("\nEnter the expression (/q to quit): ");
        if (!fgets(input, 256, stdin)) break;
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "/q") == 0)
            break;

        expr = input;
        const double result = parseExpr();
        printf("Result: %.2lf\n", result);
    }

    printf("Calculator exited.\n");
    return 0;
}

/*
    Create a C program that calculates N-th Fibonacci number for a given N user number.
*/

#include <stdio.h>

int calcFibonacci(int index);

int main() {
    int i;
    printf("Please, input the number index: ");
    scanf("%d", &i);
    printf("%d-%s fibonacci number is %d", i, (i > 2) ? ("rd") : ((i == 1) ? ("st") : ("nd")), calcFibonacci(i));
    return 0;
}

int calcFibonacci(int index) {
    int previous = 1,
        current = 1;
    for (int i = 2; i < index; i++) {
        int next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}
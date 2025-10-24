/*
    Create a C program that checks whether user provided number
    can be expressed as a sum of two Prime numbers, if yes then
    show all possible combinations. Use functions in the implementation.
*/

#include <stdio.h>

int isPrime(int number);
void findPrimeSums(int num);

int main() {
    int number;
    printf("Please, enter a number: ");
    scanf("%d", &number);
    findPrimeSums(number);
    return 0;
}

void findPrimeSums(int num) {
    int result = 0;
    for (int i = 2; i <= num / 2; i++) {
        if (isPrime(i) && isPrime(num - i)) {
            printf("%d + %d = %d\n", i, num - i, num);
            result++;
        }
    }

    if (!result) {
        printf("This number can't be expressed as a sum of 2 prime numbers.\n");
    }
}

int isPrime(int number) {
    if (number < 2) return 0;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0)
            return 0;
    }
    return 1;
}
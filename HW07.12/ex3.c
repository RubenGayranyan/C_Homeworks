/*
    Ex3: Write a C program that:
      – Prompts the user to enter a floating-point number.
      – Computes and prints the square root of the number.
      – Rounds the number to the nearest integer and prints the result.
      – Calculates and prints the value of the sine of the number (in radians).
*/

#include <stdio.h>
#include <math.h>

int main() {
    float num = 0.0;
    printf("Enter the floating point number: ");
    scanf("%f", &num);
    printf("Square root: %.2f\n", sqrt(num));
    
    int round = (num - (int)num >= 0.5) ? ((int)num + 1) : ((int)num);
    printf("%d", round);

    double sine = sin(num);
    printf("sin(%f)=%.3f", num, sine);
    return 0;
}

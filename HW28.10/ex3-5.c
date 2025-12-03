/*
    Write the function itob(n, s, b) that converts the integer n
    into a base b character representation in the string s. In
    particular, itob(n, s, 16) formats n as a hexadecimal integer in s.
*/

#include <stdio.h>

void itob(const int *n, char *s, const short *b);

int main() {
    int n;
    char s[65];
    short b;
    printf("2 - Base 2 (Binary)\n10 - Base 10 (Decimal)\n16 - Base 16 (Hexadecimal)\n0 - Quit\n\n");

    while (1) {
        printf("Select the base: ");
        scanf("%hd", &b);
        if (b == 0)
            break;
        if (b != 16 && b != 10 && b != 2)
            continue;

        printf("Enter the number: ");
        scanf("%d", &n);

        itob(&n, s, &b);
        printf("%d(10) = %s(%d)\n", n, s, b);
    }
    return 0;
}

void itob(const int *n, char *s, const short *b) {
    switch (*b) {
        case 2: { // Base 2
            int num = *n;
            char temp[64];
            short binLen = 0;

            if (num == 0) {
                s[0] = '0';
                s[1] = '\0';
                return;
            }

            while (num > 0) {
                temp[binLen++] = (num % 2) + '0';
                num /= 2;
            }

            for (int i = binLen - 1, j = 0; i >= 0; i--, j++)
                s[j] = temp[i];
            s[binLen] = '\0';
            break;
        }

        case 10: { // Base 10
            sprintf(s, "%d", *n);
            break;
        }

        case 16: { // Base 16
            sprintf(s, "%X", *n);
            break;
        }
        default:
            break;
    }
}
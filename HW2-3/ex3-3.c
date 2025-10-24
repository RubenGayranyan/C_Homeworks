/*
    Write a function expand(s1,s2) that expands shorthand notations like a-z in
    the string s1 into the equivalent complete list abc...xyz in s2 . Allow for
    letters of either case and digits, and be prepared to handle cases like a-b-c
    and a-z0-9 and -a-z . Arrange that a leading or trailing - is taken literally.
*/

#include <stdio.h>
#include <string.h>

void expand(const char *s1, char *s2);

int main() {
    char str1[8], str2[64];;
    printf("Please enter shorthand notation: ");
    scanf("%s", str1);
    expand(str1, str2);
    printf("%s", str2);
    return 0;
}
void expand(const char *s1, char *s2) {
    char ch[64][2];
    short chID = 0;

    for (int i = 1; i < strlen(s1); i++) {
        if (s1[i] == '-') {
            ch[chID][0]= s1[i-1];
            ch[chID][1]= s1[i+1];
            chID++;
        }
    }
    int k = 0, sID = 0;

    if (s1[0] == '-')
        s2[sID++] = '-';

    while (k < chID) {
        for (char i = ch[k][0]; i <= ch[k][1]; i++)
            s2[sID++] = i;
        k++;
    }

    if (s1[strlen(s1) - 1] == '-')
        s2[sID++] = '-';

    s2[sID] = '\0';
}
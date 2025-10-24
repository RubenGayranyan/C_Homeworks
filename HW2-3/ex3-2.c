/*
    Write a function escape(s,t) that converts characters like newline and tab into visible
    escape sequences like \n and \t as it copies the string t to s . Use a switch . Write a
    function for the other direction as well, converting escape sequences into the real characters.
*/

#include <stdio.h>
#include <string.h>

void escape(const char *s, char *t);
void undo(const char *t, char *u);

int main() {
    char input[40] = "Line 1\tTab 1\nLine 2\tTab 2\nLine 3\tTab 3";
    char output[sizeof(input) + 5];
    char outputUndo[sizeof(output) - 5];
    printf("%s\n\n", input);
    escape(input, output);
    printf("%s\n\n", output);
    undo(output, outputUndo);
    printf("%s", outputUndo);
    return 0;
}

void escape(const char *s, char *t) {
    int outIndex = 0;
    for (int i = 0; i < strlen(s); i++) {
        switch (s[i]) {
            case '\n': {
                t[outIndex++] = '\\';
                t[outIndex++] = 'n';
                break;
            }
            case '\t': {
                t[outIndex++] = '\\';
                t[outIndex++] = 't';
                break;
            }
            default: {
                t[outIndex++] = s[i];
                break;
            }
        }
    }
}

void undo(const char *t, char *u) {
    int outIndex = 0;
    for (int i = 0; i < strlen(t); i++) {
        switch (t[i]) {
            case '\\': {
                switch (t[++i]) {
                    case 'n': {
                        u[outIndex++] = '\n';
                        break;
                    }
                    case 't': {
                        u[outIndex++] = '\t';
                        break;
                    }
                    default: {
                        u[outIndex++] = '\\';
                        break;
                    }
                }
                break;
            }
            default: {
                u[outIndex++] = t[i];
                break;
            }
        }
    }
}
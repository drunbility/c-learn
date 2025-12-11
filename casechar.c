#include <stdio.h>

void escapec(char s[], char t[]);

void escapec(char s[], char t[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    for (int j = 0; t[j] != '\0'; j++) {
        switch (t[j]) {
        case '\n':
            s[i++] = '\\';
            s[i++] = 'n';
            break;
        case '\t':
            s[i++] = '\\';
            s[i++] = 't';

            break;
        default:
            s[i++] = t[j];
            break;
        }
    }
    s[i] = '\0';
}

int main() {
    char s[] = "343";
    char t[] = "abc\t";
    escapec(s, t);
    puts(s);
}
#include <stdio.h>

void sques(char s1[], char s2[]);

void squec(char s[], char c);

void squec(char s[], char c) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

void sques(char s1[], char s2[]) {
    int i;
    for (i = 0; s2[i] != '\0'; i++) {
        squec(s1, s2[i]);
    }
}

int main() {
    char s1[] = "abcd";
    sques(s1, "adc");
    puts(s1);
    return 0;
}
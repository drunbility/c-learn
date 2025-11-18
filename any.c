#include <stdio.h>

int anyp(char s1[], char s2[]);

int fc(char s[], char c);

int fc(char s[], char c) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            return i;
        }
    }
    return -1;
}

int anyp(char s1[], char s2[]) {
    int i, j;
    for (i = 0; s2[i] != '\0'; i++) {
        if ((j = fc(s1, s2[i])) != -1) {
            return j;
        }
    }

    return -1;
}

int main() {
    char s1[] = "werer";
    char s2[] = "r";
    printf("p:%d", anyp(s1, s2));

    return 0;
}
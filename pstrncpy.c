#include <stdio.h>

void pstrncpt(char *s, char *t, int n) {
    for (int i = 0; i < n; i++) {
        /* code */

        if (*t) {
            *s = *t;
            s++;
            t++;
        } else {
            *s = '\0';
        }
    }
}

int main() {
    char s[] = "123677";
    char t[] = "abc";
    int n = 4;
    pstrncpt(s, t, n);
    printf("%s\n", s);
    printf("%d\n", sizeof(s) / sizeof(s[0]));
    return 1;
}
#include <stdio.h>

void mstrcat(char *s, char *t) {
    while (*s != '\0') {
        s++;
    }

    while (*t != '\0') {
        *s++ = *t++;
    }
    *s = '\0';
}

int main() {
    char s[] = "123";
    char t[] = "abc";
    mstrcat(s, t);
    printf("%s\n", s);
    return 0;
}
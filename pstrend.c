#include <stdio.h>

int pstrend(char *s, char *t) {
    char *s_st = s;
    char *t_st = t;

    while (*s != '\0') {
        /* code */
        s++;
    }

    while (*t != '\0') {
        /* code */
        t++;
    }

    if (t - t_st > s - s_st) {
        return 0;
    }

    while (t >= t_st) {
        /* code */
        if (*t-- != *s--) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char s[] = "adbdg";
    char t[] = "dg1";
    int rel = pstrend(s, t);
    printf("%d\n", rel);
}
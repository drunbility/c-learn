#include <stdio.h>
static int pos;
void itoa_r(int n, char s[]) {
    if (n < 0) {
        s[pos++] = '-';
        n = -n;
    }
    if (n / 10) {
        itoa_r(n / 10, s);
    }

    s[pos++] = n % 10 + '0';
    s[pos] = '\0';
}

void itoa(int n, char s[]) {
    itoa_r(n, s);
}

int main() {
    int n = -67845;
    char s[100];
    itoa(n, s);
    printf("%s", s);
}
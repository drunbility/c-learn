#include <stdio.h>

int main() {
    int c, pre_c;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == ' ') {
            printf("\n");

        } else {
            putchar(c);
        }
    }
    return 0;
}
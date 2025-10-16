#include <stdio.h>

int main() {
    int c, pre_c;
    while ((c = getchar()) != EOF) {
        // if (c == ' ' && pre_c == ' ') {
        // } else {
        //     putchar(c);
        // }

        // pre_c = c;

        if (c == '\t') {
            printf("\\t");
        } else if (c == '\b') {
            printf("\\b");
        } else if (c == '\\') {
            printf("\\\\");
        } else {
            putchar(c);
        }
    }
    return 0;
}
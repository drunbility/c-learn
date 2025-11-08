#include <stdio.h>

#define TAB_N 5
#define OUT   1
#define IN    0
int main() {
    // int c;
    // int state = OUT;
    // int i = 0;
    // while ((c = getchar()) != EOF) {
    //     if (c == '\t') {
    //         printf(" ");
    //         if (i < TAB_N) {
    //             state = IN;
    //         } else {
    //             state = OUT;
    //             i = 0;
    //         }

    //     } else {
    //         if (state == IN) {
    //             printf("-");
    //             i++;
    //         } else {
    //             printf("%c", c);
    //         }
    //     }
    // }

    int c;
    int coln;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spa_n = TAB_N - (coln % TAB_N);
            for (int i = 0; i < spa_n; i++) {
                printf(" ");
                coln++;
            }

        } else if (c == '\n') {
            printf("\n");
            coln = 0;
        } else {
            putchar(c);
            coln++;
        }
    }

    return 0;
}
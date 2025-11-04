#include <stdio.h>

#define MAX_LEN 10
#define S_IN    1
#define S_OUT   0

int main() {
    int c;
    int state;
    int word_len;
    int len_freq[MAX_LEN + 1];
    int max_freq = 0;

    for (int i = 0; i <= MAX_LEN; i++) {
        len_freq[i] = 0;
    }
    state = S_OUT;
    word_len = 0;

    printf("输入文本: \n");

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == S_IN) {
                if (word_len > 0) {
                    if (word_len <= MAX_LEN) {
                        len_freq[word_len - 1]++;
                    } else {
                        len_freq[MAX_LEN]++;
                    }
                }
                word_len = 0;
                state = S_OUT;
            }
        } else {
            if (state == S_OUT) {
                state = S_IN;
            }
            word_len++;
        }
    }

    if (state == S_IN && word_len > 0) {
        if (word_len <= MAX_LEN) {
            len_freq[word_len - 1]++;
        } else {
            len_freq[MAX_LEN]++;
        }
    }

    // printf("\n 水平直方图--\n");
    // for (int i = 0; i < MAX_LEN; i++) {
    //     printf("%2d: ", i + 1);
    //     for (int j = 0; j < len_freq[i]; j++) {
    //         printf("*");
    //     }
    //     // printf(" %2d ", lengths[i]);
    //     printf("\n");
    // }

    // printf(">%d", MAX_LEN);
    // for (int i = 0; i < len_freq[MAX_LEN]; i++) {
    //     printf("*");
    // }
    // printf("\n");

    printf("\n 垂直直方图 \n");

    for (int i = 0; i < MAX_LEN; i++) {
        if (len_freq[i] > max_freq) {
            max_freq = len_freq[i];
        }
    }

    for (int i = max_freq; i > 0; i--) {
        printf("%4d |", i);
        for (int j = 0; j <= MAX_LEN; j++) {
            if (len_freq[j] >= i) {
                printf("  *");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }

    printf("     +");
    for (int i = 0; i <= MAX_LEN; ++i) {
        printf("---");
    }
    printf("\n");
    printf("     ");
    for (int i = 0; i < MAX_LEN; i++) {
        printf("%3d", i + 1);
    }

    printf(" >%d\n", MAX_LEN);
    return 0;
}
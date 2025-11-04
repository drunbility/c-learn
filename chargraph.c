#include <stdio.h>

#define MAX_LEN 256

int main() {
    int c;
    int char_freq[MAX_LEN];
    int max_freq = 0;

    for (int i = 0; i < MAX_LEN; i++) {
        char_freq[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= 0 && c < 256) {
            char_freq[c]++;
        }
    }

    // for (int i = 0; i < MAX_LEN; i++) {
    //     if (char_freq[i] > 0) {
    //         if (i == '\n') {
    //             printf("NL  (0x%02X): ", i);  // 换行符
    //         } else if (i == '\t') {
    //             printf("TAB (0x%02X): ", i);  // 制表符
    //         } else if (i == ' ') {
    //             printf("SPC (0x%02X): ", i);   // 空格
    //         } else if (i >= 33 && i <= 126) {  // 可打印 ASCII 字符 (排除已处理的空格)
    //             printf(" '%c' (0x%02X): ", (char)i, i);
    //         } else {                              // 其他控制字符或扩展 ASCII 字符
    //             printf(" %3d (0x%02X): ", i, i);  // 显示其十进制和十六进制值
    //         }

    //         for (int j = 0; j < char_freq[i]; j++) {
    //             printf("*");
    //         }

    //         printf("\n");
    //     }
    // }

    for (int i = 0; i < MAX_LEN; i++) {
        if (char_freq[i] > max_freq) {
            max_freq = char_freq[i];
        }
    }

    for (int j = max_freq; j > 0; j--) {
        printf("%4d |", j);
        for (int i = 0; i < MAX_LEN; i++) {
            if (char_freq[i] > 0) {
                if (char_freq[i] >= j) {
                    printf("  *");
                } else {
                    printf("   ");
                }
            }
        }
        printf("\n");
    }

    printf("   +");
    for (int i = 0; i < MAX_LEN; i++) {
        if (char_freq[i] > 0) {
            printf("---");
        }
    }
    printf("\n");
    printf("      ");
    for (int i = 0; i < MAX_LEN; i++) {
        if (char_freq[i] > 0) {
            if (i == '\n') {
                printf("NL ");  // 换行符
            } else if (i == '\t') {
                printf("TAB ");  // 制表符
            } else if (i == ' ') {
                printf("SPC ");                // 空格
            } else if (i >= 33 && i <= 126) {  // 可打印 ASCII 字符 (排除已处理的空格)
                printf("  %c", (char)i);
            } else {                  // 其他控制字符或扩展 ASCII 字符
                printf("  %02X", i);  // 显示其十进制和十六进制值
            }
        }
    }
    printf("\n");
    return 0;
}
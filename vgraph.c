#include <stdio.h>

#define MAX_WORD_LENGTH 10  // 假定最长单词长度为 20
#define IN              1
#define OUT             0

int main() {
    int c;
    int state;
    int word_len;
    int lengths[MAX_WORD_LENGTH + 1];  // 存储每个单词长度的计数
    int max_freq = 0;                  // 存储最大的单词长度计数，用于绘制垂直直方图

    // 初始化数组
    for (int i = 0; i <= MAX_WORD_LENGTH; ++i) {
        lengths[i] = 0;
    }

    state = OUT;
    word_len = 0;

    printf("请输入文本（输入 Ctrl+D 或 Ctrl+Z 结束）：\n");

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                if (word_len > 0) {
                    if (word_len <= MAX_WORD_LENGTH) {
                        lengths[word_len - 1]++;
                    } else {
                        lengths[MAX_WORD_LENGTH]++;
                    }
                }
                word_len = 0;
                state = OUT;
            }
        } else {
            if (state == OUT) {
                state = IN;
            }
            word_len++;
        }
    }

    // 处理最后一个单词
    if (state == IN && word_len > 0) {
        if (word_len <= MAX_WORD_LENGTH) {
            lengths[word_len - 1]++;
        } else {
            lengths[MAX_WORD_LENGTH]++;
        }
    }

    // 找到最大的频率，用于确定直方图的高度
    for (int i = 0; i <= MAX_WORD_LENGTH; ++i) {
        if (lengths[i] > max_freq) {
            max_freq = lengths[i];
        }
    }

    // 打印垂直直方图
    printf("\n--- 单词长度垂直直方图 ---\n");
    for (int i = max_freq; i > 0; --i) {  // 从最高频率向下打印
        printf("%4d |", i);               // 打印频率刻度
        for (int j = 0; j <= MAX_WORD_LENGTH; ++j) {
            if (lengths[j] >= i) {  // 如果当前单词长度的计数达到或超过当前行的高度
                printf("  *");      // 打印一个星号
            } else {
                printf("   ");  // 否则打印空白
            }
        }
        printf("\n");
    }

    // 打印横轴标签 (单词长度)
    printf("     +");
    for (int i = 0; i <= MAX_WORD_LENGTH; ++i) {
        printf("---");
    }
    printf("\n");

    printf("     ");
    for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
        printf("%3d", i + 1);
    }
    printf(" >%d\n", MAX_WORD_LENGTH);

    return 0;
}

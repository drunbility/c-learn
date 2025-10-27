#include <stdio.h>

#define MAX_WORD_LENGTH 10  // 假定最长单词长度为 20。超出这个长度的单词，我们将其归为“更长”
#define IN              1   // 在单词内部
#define OUT             0   // 在单词外部

int main() {
    int c;                             // 用于存储从输入中读取的字符
    int state;                         // 当前是否在单词内部
    int word_len;                      // 当前单词的长度
    int lengths[MAX_WORD_LENGTH + 1];  // 存储每个单词长度的计数
                                       // lengths[0] 存储长度为1的单词数量
                                       // lengths[1] 存储长度为2的单词数量
                                       // ...
                                       // lengths[MAX_WORD_LENGTH-1] 存储长度为MAX_WORD_LENGTH的单词数量
                                       // lengths[MAX_WORD_LENGTH] 存储长度超过MAX_WORD_LENGTH的单词数量

    // 初始化长度计数数组
    for (int i = 0; i <= MAX_WORD_LENGTH; ++i) {
        lengths[i] = 0;
    }

    state = OUT;   // 初始状态：在单词外部
    word_len = 0;  // 当前单词长度初始化为0

    printf("请输入文本（输入 Ctrl+D 或 Ctrl+Z 结束）：\n");

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {  // 遇到空白字符
            if (state == IN) {                     // 如果之前在单词内部，说明一个单词结束了
                // 记录这个单词的长度
                if (word_len > 0) {  // 确保单词长度大于0
                    if (word_len <= MAX_WORD_LENGTH) {
                        lengths[word_len - 1]++;  // 长度为1的存入lengths[0]，以此类推
                    } else {
                        lengths[MAX_WORD_LENGTH]++;  // 超过最大长度的归类
                    }
                }
                word_len = 0;  // 重置当前单词长度
                state = OUT;   // 状态变为单词外部
            }
        } else {                 // 遇到非空白字符
            if (state == OUT) {  // 如果之前在单词外部，说明一个新的单词开始了
                state = IN;
            }
            word_len++;  // 增加当前单词的长度
        }
    }

    // 处理最后一个单词（如果输入以非空白字符结束）
    if (state == IN && word_len > 0) {
        if (word_len <= MAX_WORD_LENGTH) {
            lengths[word_len - 1]++;
        } else {
            lengths[MAX_WORD_LENGTH]++;
        }
    }

    // 打印水平直方图
    printf("\n--- 单词长度水平直方图 ---\n");
    for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
        printf("%2d: ", i + 1);  // 打印单词长度
        for (int j = 0; j < lengths[i]; ++j) {
            printf("*");  // 打印星号表示计数
        }
        printf("\n");
    }
    // 打印超长单词的计数
    printf(">%d: ", MAX_WORD_LENGTH);
    for (int j = 0; j < lengths[MAX_WORD_LENGTH]; ++j) {
        printf("*");
    }
    printf("\n");

    return 0;
}

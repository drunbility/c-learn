#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint:  从输入中获取下一个整数 */
int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch())) /* 跳过空白 */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* 不是数字 */
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch(); /* ⚠️ 问题：如果下一个不是数字，就丢失了符号信息！ */

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main() {
    int n;
    int result;

    printf("输入一些数据（Ctrl+D 结束）：\n");

    while ((result = getint(&n)) != EOF) {
        if (result != 0) {
            printf("读取到整数: %d\n", n);
        } else {
            printf("不是整数，字符被压回\n");
            /* 消耗一个字符，避免无限循环 */
            int c = getch();
            if (c != EOF) {
                printf("跳过的字符: '%c'\n", c);
                /* 这里可以选择重新压回，或者直接丢弃 */
            }
        }
    }

    return 0;
}